package main

import (
    "encoding/json"
    "errors"
    "fmt"
    "log"
    "net/http"
    "strconv"
    "time"
)

func handleError(err error) {
    log.Println(err.Error())
    log.Println("currentMove: ", currentMove)
    msg, _ := json.Marshal(err.Error())
    http.Error(writer, string(msg), 500)
}

func validatePosParams(yKey, xKey, color string) (int, int, bool) {
    if yKey == "" || xKey == "" {
        handleError(errors.New("no get params"))
        return 0, 0, false
    }
    y, errY := strconv.Atoi(yKey)
    x, errX := strconv.Atoi(xKey)
    if errY != nil || errX != nil ||
        x < 0 || y < 0 || x > 18 || y > 18 ||
        board[y][x] != EMPTY || (color != "red" && color != "blue") {
        if errY != nil {
            handleError(errY)
        } else if errX != nil {
            handleError(errX)
        } else {
            handleError(errors.New("invalid params"))
        }
        return 0, 0, false
    }
    if currentMove == EMPTY {
        if color == "blue" {
            currentMove = HUMAN
        } else {
            currentMove = AI
        }
    } else {
        if color == "red" && currentMove == HUMAN ||
            color == "blue" && currentMove == AI {
            handleError(errors.New("invalid params"))
            return 0, 0, false
        }
    }
    return y, x, true
}

func checkWinMove(y, x int) string {
    if captures[currentMove] == 10 {
        winByCapture = currentMove
        if currentMove == AI {
            return "Red won"
        } else {
            return "Blue won"
        }
    }
    if isWin, line := fiveInARow(y, x, currentMove); isWin {
        win = line
        if currentMove == AI {
            return "Red won"
        } else {
            return "Blue won"
        }
    }
    return ""
}

func apiMove(w http.ResponseWriter, r *http.Request) {
    var aiMove = Move{nil, 0}
    var debug *Debug = nil
    if debugMode {
        debug = &Debug{0, 0, nil, 0, -1, []*Debug{}}
    }
    var notification string

    writer = w

    get := r.URL.Query().Get
    y, x, valid := validatePosParams(get("y"), get("x"), get("color"))
    if valid == false {
        return
    }

    timerStart := time.Now().UnixNano()

    pos := &Position{captureMove(y, x, currentMove), y, x}
    if doubleThree(pos, currentMove) {
        notification = fmt.Sprintf("No double-three")
    } else {
        if currentMove == HUMAN && AIMode {
            board[pos.Y][pos.X] = HUMAN
            if pos.Capture != nil {
                board[pos.Capture.Pos[0].Y][pos.Capture.Pos[0].X] = EMPTY
                board[pos.Capture.Pos[1].Y][pos.Capture.Pos[1].X] = EMPTY
                captures[HUMAN] += 2
            }
            if notification = checkWinMove(y, x); notification == "" {
                aiMove = minimax(AI, Depth, debug, -10000000000, 10000000000)
                currentMove = AI
                board[aiMove.pos.Y][aiMove.pos.X] = AI
                if aiMove.pos.Capture != nil {
                    board[aiMove.pos.Capture.Pos[0].Y][aiMove.pos.Capture.Pos[0].X] = EMPTY
                    board[aiMove.pos.Capture.Pos[1].Y][aiMove.pos.Capture.Pos[1].X] = EMPTY
                    captures[AI] += 2
                }
                notification = checkWinMove(aiMove.pos.Y, aiMove.pos.X)
                currentMove = HUMAN
            }
        } else {
            board[pos.Y][pos.X] = currentMove
            if pos.Capture != nil {
                board[pos.Capture.Pos[0].Y][pos.Capture.Pos[0].X] = EMPTY
                board[pos.Capture.Pos[1].Y][pos.Capture.Pos[1].X] = EMPTY
                captures[currentMove] += 2
            }
            if notification = checkWinMove(y, x); notification == "" {
                currentMove = changePlayer(currentMove)
            }
            if AITips && AIMode == false {
                aiMove = minimax(currentMove, Depth, debug, -10000000000, 10000000000)
            } else {
                aiMove.pos = pos
            }
        }
        if doubleThreeRule {
            resetFreeThrees()
        }

        timerEnd := time.Now().UnixNano()
        notification = fmt.Sprintf("Time: %f %s",
            float64(timerEnd-timerStart)/1e9, notification)
    }

    data, _ := json.Marshal(struct {
        BluePos      *Position   `json:"blue_pos"`
        RedPos       *Position   `json:"red_pos"`
        Win          *[]Coord    `json:"win"`
        WinByCapture int         `json:"win_by_capture"`
        Notification string      `json:"notification"`
        Captures     map[int]int `json:"captures"`
        Debug        *Debug      `json:"debug"`
    }{
        pos,
        aiMove.pos,
        win,
        winByCapture,
        notification,
        captures,
        debug,
    })
    fmt.Fprintln(w, string(data))
}

func resetGame() {
    board = [BoardHeight][BoardWidth]int{}
    win = nil
    winByCapture = 0
    currentMove = EMPTY
    freeThreeAI = false
    freeThreeHuman = false
    captures[AI] = 0
    captures[HUMAN] = 0
}

func apiBoard(w http.ResponseWriter, r *http.Request) {
    resetGame()
    data, _ := json.Marshal(struct {
        Depth       int  `json:"depth"`
        Moves       int  `json:"moves"`
        DoubleThree bool `json:"double_three"`
        CaptureRule bool `json:"capture_rule"`
        DebugMode   bool `json:"debug_mode"`
        AIMode      bool `json:"ai_mode"`
        AITips      bool `json:"ai_tips"`
    }{
        Depth,
        MovesCheck,
        doubleThreeRule,
        captureRule,
        debugMode,
        AIMode,
        AITips,
    })
    fmt.Fprintln(w, string(data))
}

func apiReset(w http.ResponseWriter, r *http.Request) {
    resetGame()
    data, _ := json.Marshal(board)
    fmt.Fprintln(w, string(data))
}

func validateDifficultyParams(depth, moves string) (int, int, bool) {
    if depth == "" || moves == "" {
        handleError(errors.New("no get params"))
        return 0, 0, false
    }
    newDepth, errDepth := strconv.Atoi(depth)
    newMoves, errMoves := strconv.Atoi(moves)
    if errDepth != nil || errMoves != nil ||
        newDepth < 1 || newMoves < 1 ||
        newDepth > maxDepth || newMoves > maxMovesCheck {
        if errDepth != nil {
            handleError(errDepth)
        } else if errMoves != nil {
            handleError(errMoves)
        } else {
            handleError(errors.New("invalid params"))
        }
        return 0, 0, false
    }
    return newDepth, newMoves, true
}

func apiDifficulty(w http.ResponseWriter, r *http.Request) {
    writer = w

    depth := r.URL.Query().Get("depth")
    moves := r.URL.Query().Get("moves")
    if newDepth, newMoves, valid := validateDifficultyParams(depth, moves); valid {
        Depth = newDepth
        MovesCheck = newMoves
    }
}

func changeSetting(w http.ResponseWriter, r *http.Request, boolVar *bool) {
    writer = w

    if check := r.URL.Query().Get("check");
        check != "" && (check == "true" || check == "false") {
        *boolVar = map[string]bool{"true": true, "false": false}[check]
    } else if check == "" {
        handleError(errors.New("no get params"))
    } else {
        handleError(errors.New("invalid params"))
    }
}

func main() {
    http.Handle("/", http.FileServer(http.Dir("front")))
    http.HandleFunc("/api/move", apiMove)
    http.HandleFunc("/api/board", apiBoard)
    http.HandleFunc("/api/reset", apiReset)
    http.HandleFunc("/api/settings/difficulty", apiDifficulty)

    http.HandleFunc("/api/settings/double-three",
        func(w http.ResponseWriter, r *http.Request) { changeSetting(w, r, &doubleThreeRule) })
    http.HandleFunc("/api/settings/ai-mode",
        func(w http.ResponseWriter, r *http.Request) { changeSetting(w, r, &AIMode) })
    http.HandleFunc("/api/settings/ai-tips",
        func(w http.ResponseWriter, r *http.Request) { changeSetting(w, r, &AITips) })
    http.HandleFunc("/api/settings/capture",
        func(w http.ResponseWriter, r *http.Request) { changeSetting(w, r, &captureRule) })
    http.HandleFunc("/api/settings/debug",
        func(w http.ResponseWriter, r *http.Request) { changeSetting(w, r, &debugMode) })

    log.Fatal(http.ListenAndServe(":8080", nil))
}
