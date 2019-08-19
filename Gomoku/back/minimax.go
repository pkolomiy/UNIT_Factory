package main

import "container/heap"

func fiveInARow(y, x, player int) (bool, *[]Coord) {
    inARow := 0
    line := [9]Coord{{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}}
    var tempX, tempY int

    // Horizontal
    for tempX = x - 4; tempX <= x+4 && tempX < BoardWidth; tempX++ {
        if inARow >= 5 && tempX >= 0 && tempX < BoardWidth && board[y][tempX] != player {
            break
        } else if tempX >= 0 && tempX < BoardWidth && board[y][tempX] == player {
            line[inARow].Y, line[inARow].X = y, tempX
            inARow++
        } else {
            inARow = 0
        }
    }
    if inARow < 5 {
        inARow = 0
    } else {
        winLine := line[:inARow]
        return true, &winLine
    }

    // Vertical
    for tempY = y - 4; tempY <= y+4 && tempY < BoardHeight; tempY++ {
        if inARow >= 5 && tempY >= 0 && tempY < BoardHeight && board[tempY][x] != player {
            break
        } else if tempY >= 0 && tempY < BoardHeight && board[tempY][x] == player {
            line[inARow].Y, line[inARow].X = tempY, x
            inARow++
        } else {
            inARow = 0
        }
    }
    if inARow < 5 {
        inARow = 0
    } else {
        winLine := line[:inARow]
        return true, &winLine
    }

    // Diagonal 1
    for tempY, tempX = y-4, x-4; tempX <= x+4 && tempY < BoardHeight && tempX < BoardWidth; tempY, tempX = tempY+1, tempX+1 {
        if inARow >= 5 && tempY >= 0 && tempY < BoardHeight && tempX >= 0 && tempX < BoardWidth &&
            board[tempY][tempX] != player {
            break
        } else if tempY >= 0 && tempY < BoardHeight && tempX >= 0 && tempX < BoardWidth && board[tempY][tempX] == player {
            line[inARow].Y, line[inARow].X = tempY, tempX
            inARow++
        } else {
            inARow = 0
        }
    }
    if inARow < 5 {
        inARow = 0
    } else {
        winLine := line[:inARow]
        return true, &winLine
    }

    // Diagonal 2
    for tempY, tempX = y+4, x-4; tempX <= x+4 && tempY >= 0 && tempX < BoardWidth; tempY, tempX = tempY-1, tempX+1 {
        if inARow >= 5 && tempY >= 0 && tempY < BoardHeight && tempX >= 0 && tempX < BoardWidth && board[tempY][tempX] != player {
            break
        } else if tempY >= 0 && tempY < BoardHeight && tempX >= 0 && tempX < BoardWidth && board[tempY][tempX] == player {
            line[inARow].Y, line[inARow].X = tempY, tempX
            inARow++
        } else {
            inARow = 0
        }
    }
    if inARow < 5 {
        inARow = 0
    } else {
        winLine := line[:inARow]
        return true, &winLine
    }
    winLine := line[:inARow]

    return false, &winLine
}

func adjacentNotEmpty(y, x int) bool {
    if (y-1 >= 0 && x-1 >= 0 && board[y-1][x-1] != EMPTY) ||
        (y-1 >= 0 && board[y-1][x] != EMPTY) ||
        (y-1 >= 0 && x+1 < BoardWidth && board[y-1][x+1] != EMPTY) ||
        (x-1 >= 0 && board[y][x-1] != EMPTY) ||
        (x+1 < BoardWidth && board[y][x+1] != EMPTY) ||
        (y+1 < BoardHeight && x-1 >= 0 && board[y+1][x-1] != EMPTY) ||
        (y+1 < BoardHeight && board[y+1][x] != EMPTY) ||
        (y+1 < BoardHeight && x+1 < BoardWidth && board[y+1][x+1] != EMPTY) {
        return true
    }
    return false
}

func getScore(row, openEnds int, current bool) int {
    if openEnds == 0 && row >= 1 && row <= 4 {
        return 0
    } else if row > 4 {
        return 200000000
    } else if row == 4 {
        if current {
            return 100000000
        }
        return 500000
    } else if row == 3 {
        if openEnds == 1 {
            if current {
                return 10000
            }
            return 500
        }
        if current {
            return 20000
        }
        return 10000
    } else if row == 2 {
        if openEnds == 1 {
            if current {
                return 10
            }
            return 5
        }
        if current {
            return 20
        }
        return 10
    }
    if openEnds == 1 {
        if current {
            return 2
        }
        return 1
    }
    if current {
        return 4
    }
    return 2
}

func getCaptureScore(player int) int {
    if captures[player] == 8 {
        return 400000000
    } else if captures[player] == 6 {
        return 40000
    } else if captures[player] == 4 {
        return 400
    } else if captures[player] == 2 {
        return 40
    } else if captures[player] == 0 {
        return 4
    }
    return 800000000
}

func doubleThree(pos *Position, player int) bool {
    double := false
    if pos.Capture != nil {
        return false
    }
    board[pos.Y][pos.X] = player
    if doubleThreeRule &&
        ((player == AI && freeThreeAI) || (player == HUMAN && freeThreeHuman)) &&
        checkForFreeThree(pos.Y, pos.X, player) {
        double = true
    }
    board[pos.Y][pos.X] = EMPTY
    return double
}

func checkForWin(player int) *Position {
    var win bool
    var capture *Capture = nil
    for y := 0; y < BoardHeight; y++ {
        for x := 0; x < BoardWidth; x++ {
            if board[y][x] == EMPTY && adjacentNotEmpty(y, x) {
                board[y][x] = player
                win, _ = fiveInARow(y, x, player)
                if win == true {
                    board[y][x] = EMPTY
                    return &Position{nil, y, x}
                }
                if captures[player] != 8 {
                    capture = nil
                } else {
                    capture = captureMove(y, x, player)
                }
                if capture != nil {
                    return &Position{capture, y, x}
                }
                board[y][x] = EMPTY
            }
        }
    }
    return nil
}

func checkIfThereWin(player int) (win bool, pos *Position, score int) {
    win = false

    pos = checkForWin(player)
    if pos == nil {
        pos = checkForWin(changePlayer(player))
    }

    if pos != nil {
        win = true
        board[pos.Y][pos.X] = player
        score = finalScore(changePlayer(player))
        if pos.Capture != nil {
            board[pos.Capture.Pos[0].Y][pos.Capture.Pos[0].X] = EMPTY
            board[pos.Capture.Pos[1].Y][pos.Capture.Pos[1].X] = EMPTY
            captures[player] += 2
            captureScore := getCaptureScore(AI) - getCaptureScore(HUMAN)
            if (player == AI && captureScore > score) ||
                (player == HUMAN && captureScore < score) {
                score = captureScore
            }
            captures[player] -= 2
            board[pos.Capture.Pos[0].Y][pos.Capture.Pos[0].X] = pos.Capture.Enemy
            board[pos.Capture.Pos[1].Y][pos.Capture.Pos[1].X] = pos.Capture.Enemy
        }
        board[pos.Y][pos.X] = EMPTY
    }

    return
}

var boardPlayer = [BoardHeight][BoardWidth]int{}
var boardEnemy = [BoardHeight][BoardWidth]int{}

func generateMoves(player int) Moves {
    if win, pos, score := checkIfThereWin(player); win {
        return Moves{{pos, score}}
    }

    var y, x int
    for y = 0; y < BoardHeight; y++ {
        for x = 0; x < BoardWidth; x++ {
            boardPlayer[y][x] = board[y][x]
            boardEnemy[y][x] = board[y][x]
        }
    }

    var moves Moves
    var tempX, tempY, tempX2, tempY2 int
    var startX, endX, startY, endY int
    var playerScore, enemyScore, emptyPlayerScore, emptyEnemyScore int
    var playerRow, enemyRow, emptyPlayerRow, emptyEnemyRow int
    var playerOpenEnds, enemyOpenEnds, emptyPlayerOpenEnds, emptyEnemyOpenEnds int
    var captureScore int
    heap.Init(&moves)

    enemy := changePlayer(player)

    for y = 0; y < BoardHeight; y++ {
        for x = 0; x < BoardWidth; x++ {
            if board[y][x] == EMPTY && adjacentNotEmpty(y, x) {
                playerPos := &Position{captureMove(y, x, player), y, x}
                if doubleThree(playerPos, player) == false {
                    enemyPos := &Position{captureMove(y, x, enemy), y, x}
                    boardPlayer[y][x] = player
                    boardEnemy[y][x] = enemy
                    if playerPos.Capture != nil {
                        boardPlayer[playerPos.Capture.Pos[0].Y][playerPos.Capture.Pos[0].X] = EMPTY
                        boardPlayer[playerPos.Capture.Pos[1].Y][playerPos.Capture.Pos[1].X] = EMPTY
                    }
                    if enemyPos.Capture != nil {
                        boardEnemy[enemyPos.Capture.Pos[0].Y][enemyPos.Capture.Pos[0].X] = EMPTY
                        boardEnemy[enemyPos.Capture.Pos[1].Y][enemyPos.Capture.Pos[1].X] = EMPTY
                    }
                    playerScore, enemyScore, emptyPlayerScore, emptyEnemyScore = 0, 0, 0, 0
                    playerRow, enemyRow, emptyPlayerRow, emptyEnemyRow = 0, 0, 0, 0
                    playerOpenEnds, enemyOpenEnds, emptyPlayerOpenEnds, emptyEnemyOpenEnds = 0, 0, 0, 0
                    startX, endX, startY, endY = 0, BoardWidth, 0, BoardHeight
                    if x > 4 {
                        startX = x - 4
                    }
                    if y > 4 {
                        startY = y - 4
                    }
                    if x < BoardWidth-5 {
                        endX = x + 5
                    }
                    if y < BoardHeight-5 {
                        endY = y + 5
                    }

                    // Horizontal
                    for tempY = startY; tempY < endY; tempY++ {
                        for tempX = startX; tempX < endX; tempX++ {

                            if board[tempY][tempX] == player {
                                emptyPlayerRow = emptyPlayerRow + 1
                            } else if board[tempY][tempX] == EMPTY && emptyPlayerRow > 0 {
                                emptyPlayerOpenEnds = emptyPlayerOpenEnds + 1
                                emptyPlayerScore = emptyPlayerScore + getScore(emptyPlayerRow, emptyPlayerOpenEnds, false)
                                emptyPlayerRow, emptyPlayerOpenEnds = 0, 1
                            } else if board[tempY][tempX] == EMPTY {
                                emptyPlayerOpenEnds = 1
                            } else if emptyPlayerRow > 0 {
                                emptyPlayerScore = emptyPlayerScore + getScore(emptyPlayerRow, emptyPlayerOpenEnds, false)
                                emptyPlayerRow, emptyPlayerOpenEnds = 0, 0
                            } else {
                                emptyPlayerOpenEnds = 0
                            }

                            if board[tempY][tempX] == enemy {
                                emptyEnemyRow = emptyEnemyRow + 1
                            } else if board[tempY][tempX] == EMPTY && emptyEnemyRow > 0 {
                                emptyEnemyOpenEnds = emptyEnemyOpenEnds + 1
                                emptyEnemyScore = emptyEnemyScore + getScore(emptyEnemyRow, emptyEnemyOpenEnds, false)
                                emptyEnemyRow, emptyEnemyOpenEnds = 0, 1
                            } else if board[tempY][tempX] == EMPTY {
                                emptyEnemyOpenEnds = 1
                            } else if emptyEnemyRow > 0 {
                                emptyEnemyScore = emptyEnemyScore + getScore(emptyEnemyRow, emptyEnemyOpenEnds, false)
                                emptyEnemyRow, emptyEnemyOpenEnds = 0, 0
                            } else {
                                emptyEnemyOpenEnds = 0
                            }

                            if boardPlayer[tempY][tempX] == player {
                                playerRow = playerRow + 1
                            } else if boardPlayer[tempY][tempX] == EMPTY && playerRow > 0 {
                                playerOpenEnds = playerOpenEnds + 1
                                playerScore = playerScore + getScore(playerRow, playerOpenEnds, false)
                                playerRow, playerOpenEnds = 0, 1
                            } else if boardPlayer[tempY][tempX] == EMPTY {
                                playerOpenEnds = 1
                            } else if playerRow > 0 {
                                playerScore = playerScore + getScore(playerRow, playerOpenEnds, false)
                                playerRow, playerOpenEnds = 0, 0
                            } else {
                                playerOpenEnds = 0
                            }

                            if boardEnemy[tempY][tempX] == enemy {
                                enemyRow = enemyRow + 1
                            } else if boardEnemy[tempY][tempX] == EMPTY && enemyRow > 0 {
                                enemyOpenEnds = enemyOpenEnds + 1
                                enemyScore = enemyScore + getScore(enemyRow, enemyOpenEnds, false)
                                enemyRow, enemyOpenEnds = 0, 1
                            } else if boardEnemy[tempY][tempX] == EMPTY {
                                enemyOpenEnds = 1
                            } else if enemyRow > 0 {
                                enemyScore = enemyScore + getScore(enemyRow, enemyOpenEnds, false)
                                enemyRow, enemyOpenEnds = 0, 0
                            } else {
                                enemyOpenEnds = 0
                            }

                        }

                        if emptyPlayerRow > 0 {
                            emptyPlayerScore = emptyPlayerScore + getScore(emptyPlayerRow, emptyPlayerOpenEnds, false)
                        }
                        if emptyEnemyRow > 0 {
                            emptyEnemyScore = emptyEnemyScore + getScore(emptyEnemyRow, emptyEnemyOpenEnds, false)
                        }
                        if playerRow > 0 {
                            playerScore = playerScore + getScore(playerRow, playerOpenEnds, false)
                        }
                        if enemyRow > 0 {
                            enemyScore = enemyScore + getScore(enemyRow, enemyOpenEnds, false)
                        }
                        playerRow, enemyRow, emptyPlayerRow, emptyEnemyRow = 0, 0, 0, 0
                        playerOpenEnds, enemyOpenEnds, emptyPlayerOpenEnds, emptyEnemyOpenEnds = 0, 0, 0, 0
                    }

                    // Vertical
                    for tempX = startX; tempX < endX; tempX++ {
                        for tempY = startY; tempY < endY; tempY++ {

                            if board[tempY][tempX] == player {
                                emptyPlayerRow = emptyPlayerRow + 1
                            } else if board[tempY][tempX] == EMPTY && emptyPlayerRow > 0 {
                                emptyPlayerOpenEnds = emptyPlayerOpenEnds + 1
                                emptyPlayerScore = emptyPlayerScore + getScore(emptyPlayerRow, emptyPlayerOpenEnds, false)
                                emptyPlayerRow, emptyPlayerOpenEnds = 0, 1
                            } else if board[tempY][tempX] == EMPTY {
                                emptyPlayerOpenEnds = 1
                            } else if emptyPlayerRow > 0 {
                                emptyPlayerScore = emptyPlayerScore + getScore(emptyPlayerRow, emptyPlayerOpenEnds, false)
                                emptyPlayerRow, emptyPlayerOpenEnds = 0, 0
                            } else {
                                emptyPlayerOpenEnds = 0
                            }

                            if board[tempY][tempX] == enemy {
                                emptyEnemyRow = emptyEnemyRow + 1
                            } else if board[tempY][tempX] == EMPTY && emptyEnemyRow > 0 {
                                emptyEnemyOpenEnds = emptyEnemyOpenEnds + 1
                                emptyEnemyScore = emptyEnemyScore + getScore(emptyEnemyRow, emptyEnemyOpenEnds, false)
                                emptyEnemyRow, emptyEnemyOpenEnds = 0, 1
                            } else if board[tempY][tempX] == EMPTY {
                                emptyEnemyOpenEnds = 1
                            } else if emptyEnemyRow > 0 {
                                emptyEnemyScore = emptyEnemyScore + getScore(emptyEnemyRow, emptyEnemyOpenEnds, false)
                                emptyEnemyRow, emptyEnemyOpenEnds = 0, 0
                            } else {
                                emptyEnemyOpenEnds = 0
                            }

                            if boardPlayer[tempY][tempX] == player {
                                playerRow = playerRow + 1
                            } else if boardPlayer[tempY][tempX] == EMPTY && playerRow > 0 {
                                playerOpenEnds = playerOpenEnds + 1
                                playerScore = playerScore + getScore(playerRow, playerOpenEnds, false)
                                playerRow, playerOpenEnds = 0, 1
                            } else if boardPlayer[tempY][tempX] == EMPTY {
                                playerOpenEnds = 1
                            } else if playerRow > 0 {
                                playerScore = playerScore + getScore(playerRow, playerOpenEnds, false)
                                playerRow, playerOpenEnds = 0, 0
                            } else {
                                playerOpenEnds = 0
                            }

                            if boardEnemy[tempY][tempX] == enemy {
                                enemyRow = enemyRow + 1
                            } else if boardEnemy[tempY][tempX] == EMPTY && enemyRow > 0 {
                                enemyOpenEnds = enemyOpenEnds + 1
                                enemyScore = enemyScore + getScore(enemyRow, enemyOpenEnds, false)
                                enemyRow, enemyOpenEnds = 0, 1
                            } else if boardEnemy[tempY][tempX] == EMPTY {
                                enemyOpenEnds = 1
                            } else if enemyRow > 0 {
                                enemyScore = enemyScore + getScore(enemyRow, enemyOpenEnds, false)
                                enemyRow, enemyOpenEnds = 0, 0
                            } else {
                                enemyOpenEnds = 0
                            }

                        }

                        if emptyPlayerRow > 0 {
                            emptyPlayerScore = emptyPlayerScore + getScore(emptyPlayerRow, emptyPlayerOpenEnds, false)
                        }
                        if emptyEnemyRow > 0 {
                            emptyEnemyScore = emptyEnemyScore + getScore(emptyEnemyRow, emptyEnemyOpenEnds, false)
                        }
                        if playerRow > 0 {
                            playerScore = playerScore + getScore(playerRow, playerOpenEnds, false)
                        }
                        if enemyRow > 0 {
                            enemyScore = enemyScore + getScore(enemyRow, enemyOpenEnds, false)
                        }
                        playerRow, enemyRow, emptyPlayerRow, emptyEnemyRow = 0, 0, 0, 0
                        playerOpenEnds, enemyOpenEnds, emptyPlayerOpenEnds, emptyEnemyOpenEnds = 0, 0, 0, 0
                    }

                    // Diagonal 1.1
                    for tempX2 = startX; tempX2 < endX; tempX2++ {
                        for tempY, tempX = startY, tempX2; tempY < endY && tempX < endX; tempY, tempX = tempY+1, tempX+1 {

                            if board[tempY][tempX] == player {
                                emptyPlayerRow = emptyPlayerRow + 1
                            } else if board[tempY][tempX] == EMPTY && emptyPlayerRow > 0 {
                                emptyPlayerOpenEnds = emptyPlayerOpenEnds + 1
                                emptyPlayerScore = emptyPlayerScore + getScore(emptyPlayerRow, emptyPlayerOpenEnds, false)
                                emptyPlayerRow, emptyPlayerOpenEnds = 0, 1
                            } else if board[tempY][tempX] == EMPTY {
                                emptyPlayerOpenEnds = 1
                            } else if emptyPlayerRow > 0 {
                                emptyPlayerScore = emptyPlayerScore + getScore(emptyPlayerRow, emptyPlayerOpenEnds, false)
                                emptyPlayerRow, emptyPlayerOpenEnds = 0, 0
                            } else {
                                emptyPlayerOpenEnds = 0
                            }

                            if board[tempY][tempX] == enemy {
                                emptyEnemyRow = emptyEnemyRow + 1
                            } else if board[tempY][tempX] == EMPTY && emptyEnemyRow > 0 {
                                emptyEnemyOpenEnds = emptyEnemyOpenEnds + 1
                                emptyEnemyScore = emptyEnemyScore + getScore(emptyEnemyRow, emptyEnemyOpenEnds, false)
                                emptyEnemyRow, emptyEnemyOpenEnds = 0, 1
                            } else if board[tempY][tempX] == EMPTY {
                                emptyEnemyOpenEnds = 1
                            } else if emptyEnemyRow > 0 {
                                emptyEnemyScore = emptyEnemyScore + getScore(emptyEnemyRow, emptyEnemyOpenEnds, false)
                                emptyEnemyRow, emptyEnemyOpenEnds = 0, 0
                            } else {
                                emptyEnemyOpenEnds = 0
                            }

                            if boardPlayer[tempY][tempX] == player {
                                playerRow = playerRow + 1
                            } else if boardPlayer[tempY][tempX] == EMPTY && playerRow > 0 {
                                playerOpenEnds = playerOpenEnds + 1
                                playerScore = playerScore + getScore(playerRow, playerOpenEnds, false)
                                playerRow, playerOpenEnds = 0, 1
                            } else if boardPlayer[tempY][tempX] == EMPTY {
                                playerOpenEnds = 1
                            } else if playerRow > 0 {
                                playerScore = playerScore + getScore(playerRow, playerOpenEnds, false)
                                playerRow, playerOpenEnds = 0, 0
                            } else {
                                playerOpenEnds = 0
                            }

                            if boardEnemy[tempY][tempX] == enemy {
                                enemyRow = enemyRow + 1
                            } else if boardEnemy[tempY][tempX] == EMPTY && enemyRow > 0 {
                                enemyOpenEnds = enemyOpenEnds + 1
                                enemyScore = enemyScore + getScore(enemyRow, enemyOpenEnds, false)
                                enemyRow, enemyOpenEnds = 0, 1
                            } else if boardEnemy[tempY][tempX] == EMPTY {
                                enemyOpenEnds = 1
                            } else if enemyRow > 0 {
                                enemyScore = enemyScore + getScore(enemyRow, enemyOpenEnds, false)
                                enemyRow, enemyOpenEnds = 0, 0
                            } else {
                                enemyOpenEnds = 0
                            }

                        }

                        if emptyPlayerRow > 0 {
                            emptyPlayerScore = emptyPlayerScore + getScore(emptyPlayerRow, emptyPlayerOpenEnds, false)
                        }
                        if emptyEnemyRow > 0 {
                            emptyEnemyScore = emptyEnemyScore + getScore(emptyEnemyRow, emptyEnemyOpenEnds, false)
                        }
                        if playerRow > 0 {
                            playerScore = playerScore + getScore(playerRow, playerOpenEnds, false)
                        }
                        if enemyRow > 0 {
                            enemyScore = enemyScore + getScore(enemyRow, enemyOpenEnds, false)
                        }
                        playerRow, enemyRow, emptyPlayerRow, emptyEnemyRow = 0, 0, 0, 0
                        playerOpenEnds, enemyOpenEnds, emptyPlayerOpenEnds, emptyEnemyOpenEnds = 0, 0, 0, 0
                    }

                    // Diagonal 1.2
                    for tempY2 = startY + 1; tempY2 < endY; tempY2++ {
                        for tempY, tempX = tempY2, startX; tempY < endY && tempX < endX; tempY, tempX = tempY+1, tempX+1 {

                            if board[tempY][tempX] == player {
                                emptyPlayerRow = emptyPlayerRow + 1
                            } else if board[tempY][tempX] == EMPTY && emptyPlayerRow > 0 {
                                emptyPlayerOpenEnds = emptyPlayerOpenEnds + 1
                                emptyPlayerScore = emptyPlayerScore + getScore(emptyPlayerRow, emptyPlayerOpenEnds, false)
                                emptyPlayerRow, emptyPlayerOpenEnds = 0, 1
                            } else if board[tempY][tempX] == EMPTY {
                                emptyPlayerOpenEnds = 1
                            } else if emptyPlayerRow > 0 {
                                emptyPlayerScore = emptyPlayerScore + getScore(emptyPlayerRow, emptyPlayerOpenEnds, false)
                                emptyPlayerRow, emptyPlayerOpenEnds = 0, 0
                            } else {
                                emptyPlayerOpenEnds = 0
                            }

                            if board[tempY][tempX] == enemy {
                                emptyEnemyRow = emptyEnemyRow + 1
                            } else if board[tempY][tempX] == EMPTY && emptyEnemyRow > 0 {
                                emptyEnemyOpenEnds = emptyEnemyOpenEnds + 1
                                emptyEnemyScore = emptyEnemyScore + getScore(emptyEnemyRow, emptyEnemyOpenEnds, false)
                                emptyEnemyRow, emptyEnemyOpenEnds = 0, 1
                            } else if board[tempY][tempX] == EMPTY {
                                emptyEnemyOpenEnds = 1
                            } else if emptyEnemyRow > 0 {
                                emptyEnemyScore = emptyEnemyScore + getScore(emptyEnemyRow, emptyEnemyOpenEnds, false)
                                emptyEnemyRow, emptyEnemyOpenEnds = 0, 0
                            } else {
                                emptyEnemyOpenEnds = 0
                            }

                            if boardPlayer[tempY][tempX] == player {
                                playerRow = playerRow + 1
                            } else if boardPlayer[tempY][tempX] == EMPTY && playerRow > 0 {
                                playerOpenEnds = playerOpenEnds + 1
                                playerScore = playerScore + getScore(playerRow, playerOpenEnds, false)
                                playerRow, playerOpenEnds = 0, 1
                            } else if boardPlayer[tempY][tempX] == EMPTY {
                                playerOpenEnds = 1
                            } else if playerRow > 0 {
                                playerScore = playerScore + getScore(playerRow, playerOpenEnds, false)
                                playerRow, playerOpenEnds = 0, 0
                            } else {
                                playerOpenEnds = 0
                            }

                            if boardEnemy[tempY][tempX] == enemy {
                                enemyRow = enemyRow + 1
                            } else if boardEnemy[tempY][tempX] == EMPTY && enemyRow > 0 {
                                enemyOpenEnds = enemyOpenEnds + 1
                                enemyScore = enemyScore + getScore(enemyRow, enemyOpenEnds, false)
                                enemyRow, enemyOpenEnds = 0, 1
                            } else if boardEnemy[tempY][tempX] == EMPTY {
                                enemyOpenEnds = 1
                            } else if enemyRow > 0 {
                                enemyScore = enemyScore + getScore(enemyRow, enemyOpenEnds, false)
                                enemyRow, enemyOpenEnds = 0, 0
                            } else {
                                enemyOpenEnds = 0
                            }

                        }

                        if emptyPlayerRow > 0 {
                            emptyPlayerScore = emptyPlayerScore + getScore(emptyPlayerRow, emptyPlayerOpenEnds, false)
                        }
                        if emptyEnemyRow > 0 {
                            emptyEnemyScore = emptyEnemyScore + getScore(emptyEnemyRow, emptyEnemyOpenEnds, false)
                        }
                        if playerRow > 0 {
                            playerScore = playerScore + getScore(playerRow, playerOpenEnds, false)
                        }
                        if enemyRow > 0 {
                            enemyScore = enemyScore + getScore(enemyRow, enemyOpenEnds, false)
                        }
                        playerRow, enemyRow, emptyPlayerRow, emptyEnemyRow = 0, 0, 0, 0
                        playerOpenEnds, enemyOpenEnds, emptyPlayerOpenEnds, emptyEnemyOpenEnds = 0, 0, 0, 0
                    }

                    // Diagonal 2.1
                    for tempX2 = startX; tempX2 < endX; tempX2++ {
                        for tempY, tempX = startY, tempX2; tempY < endY && tempX >= startX; tempY, tempX = tempY+1, tempX-1 {

                            if board[tempY][tempX] == player {
                                emptyPlayerRow = emptyPlayerRow + 1
                            } else if board[tempY][tempX] == EMPTY && emptyPlayerRow > 0 {
                                emptyPlayerOpenEnds = emptyPlayerOpenEnds + 1
                                emptyPlayerScore = emptyPlayerScore + getScore(emptyPlayerRow, emptyPlayerOpenEnds, false)
                                emptyPlayerRow, emptyPlayerOpenEnds = 0, 1
                            } else if board[tempY][tempX] == EMPTY {
                                emptyPlayerOpenEnds = 1
                            } else if emptyPlayerRow > 0 {
                                emptyPlayerScore = emptyPlayerScore + getScore(emptyPlayerRow, emptyPlayerOpenEnds, false)
                                emptyPlayerRow, emptyPlayerOpenEnds = 0, 0
                            } else {
                                emptyPlayerOpenEnds = 0
                            }

                            if board[tempY][tempX] == enemy {
                                emptyEnemyRow = emptyEnemyRow + 1
                            } else if board[tempY][tempX] == EMPTY && emptyEnemyRow > 0 {
                                emptyEnemyOpenEnds = emptyEnemyOpenEnds + 1
                                emptyEnemyScore = emptyEnemyScore + getScore(emptyEnemyRow, emptyEnemyOpenEnds, false)
                                emptyEnemyRow, emptyEnemyOpenEnds = 0, 1
                            } else if board[tempY][tempX] == EMPTY {
                                emptyEnemyOpenEnds = 1
                            } else if emptyEnemyRow > 0 {
                                emptyEnemyScore = emptyEnemyScore + getScore(emptyEnemyRow, emptyEnemyOpenEnds, false)
                                emptyEnemyRow, emptyEnemyOpenEnds = 0, 0
                            } else {
                                emptyEnemyOpenEnds = 0
                            }

                            if boardPlayer[tempY][tempX] == player {
                                playerRow = playerRow + 1
                            } else if boardPlayer[tempY][tempX] == EMPTY && playerRow > 0 {
                                playerOpenEnds = playerOpenEnds + 1
                                playerScore = playerScore + getScore(playerRow, playerOpenEnds, false)
                                playerRow, playerOpenEnds = 0, 1
                            } else if boardPlayer[tempY][tempX] == EMPTY {
                                playerOpenEnds = 1
                            } else if playerRow > 0 {
                                playerScore = playerScore + getScore(playerRow, playerOpenEnds, false)
                                playerRow, playerOpenEnds = 0, 0
                            } else {
                                playerOpenEnds = 0
                            }

                            if boardEnemy[tempY][tempX] == enemy {
                                enemyRow = enemyRow + 1
                            } else if boardEnemy[tempY][tempX] == EMPTY && enemyRow > 0 {
                                enemyOpenEnds = enemyOpenEnds + 1
                                enemyScore = enemyScore + getScore(enemyRow, enemyOpenEnds, false)
                                enemyRow, enemyOpenEnds = 0, 1
                            } else if boardEnemy[tempY][tempX] == EMPTY {
                                enemyOpenEnds = 1
                            } else if enemyRow > 0 {
                                enemyScore = enemyScore + getScore(enemyRow, enemyOpenEnds, false)
                                enemyRow, enemyOpenEnds = 0, 0
                            } else {
                                enemyOpenEnds = 0
                            }

                        }

                        if emptyPlayerRow > 0 {
                            emptyPlayerScore = emptyPlayerScore + getScore(emptyPlayerRow, emptyPlayerOpenEnds, false)
                        }
                        if emptyEnemyRow > 0 {
                            emptyEnemyScore = emptyEnemyScore + getScore(emptyEnemyRow, emptyEnemyOpenEnds, false)
                        }
                        if playerRow > 0 {
                            playerScore = playerScore + getScore(playerRow, playerOpenEnds, false)
                        }
                        if enemyRow > 0 {
                            enemyScore = enemyScore + getScore(enemyRow, enemyOpenEnds, false)
                        }
                        playerRow, enemyRow, emptyPlayerRow, emptyEnemyRow = 0, 0, 0, 0
                        playerOpenEnds, enemyOpenEnds, emptyPlayerOpenEnds, emptyEnemyOpenEnds = 0, 0, 0, 0
                    }

                    // Diagonal 2.2
                    for tempY2 = startY + 1; tempY2 < endY; tempY2++ {
                        for tempY, tempX = tempY2, endX-1; tempY < endY && tempX >= startX; tempY, tempX = tempY+1, tempX-1 {

                            if board[tempY][tempX] == player {
                                emptyPlayerRow = emptyPlayerRow + 1
                            } else if board[tempY][tempX] == EMPTY && emptyPlayerRow > 0 {
                                emptyPlayerOpenEnds = emptyPlayerOpenEnds + 1
                                emptyPlayerScore = emptyPlayerScore + getScore(emptyPlayerRow, emptyPlayerOpenEnds, false)
                                emptyPlayerRow, emptyPlayerOpenEnds = 0, 1
                            } else if board[tempY][tempX] == EMPTY {
                                emptyPlayerOpenEnds = 1
                            } else if emptyPlayerRow > 0 {
                                emptyPlayerScore = emptyPlayerScore + getScore(emptyPlayerRow, emptyPlayerOpenEnds, false)
                                emptyPlayerRow, emptyPlayerOpenEnds = 0, 0
                            } else {
                                emptyPlayerOpenEnds = 0
                            }

                            if board[tempY][tempX] == enemy {
                                emptyEnemyRow = emptyEnemyRow + 1
                            } else if board[tempY][tempX] == EMPTY && emptyEnemyRow > 0 {
                                emptyEnemyOpenEnds = emptyEnemyOpenEnds + 1
                                emptyEnemyScore = emptyEnemyScore + getScore(emptyEnemyRow, emptyEnemyOpenEnds, false)
                                emptyEnemyRow, emptyEnemyOpenEnds = 0, 1
                            } else if board[tempY][tempX] == EMPTY {
                                emptyEnemyOpenEnds = 1
                            } else if emptyEnemyRow > 0 {
                                emptyEnemyScore = emptyEnemyScore + getScore(emptyEnemyRow, emptyEnemyOpenEnds, false)
                                emptyEnemyRow, emptyEnemyOpenEnds = 0, 0
                            } else {
                                emptyEnemyOpenEnds = 0
                            }

                            if boardPlayer[tempY][tempX] == player {
                                playerRow = playerRow + 1
                            } else if boardPlayer[tempY][tempX] == EMPTY && playerRow > 0 {
                                playerOpenEnds = playerOpenEnds + 1
                                playerScore = playerScore + getScore(playerRow, playerOpenEnds, false)
                                playerRow, playerOpenEnds = 0, 1
                            } else if boardPlayer[tempY][tempX] == EMPTY {
                                playerOpenEnds = 1
                            } else if playerRow > 0 {
                                playerScore = playerScore + getScore(playerRow, playerOpenEnds, false)
                                playerRow, playerOpenEnds = 0, 0
                            } else {
                                playerOpenEnds = 0
                            }

                            if boardEnemy[tempY][tempX] == enemy {
                                enemyRow = enemyRow + 1
                            } else if boardEnemy[tempY][tempX] == EMPTY && enemyRow > 0 {
                                enemyOpenEnds = enemyOpenEnds + 1
                                enemyScore = enemyScore + getScore(enemyRow, enemyOpenEnds, false)
                                enemyRow, enemyOpenEnds = 0, 1
                            } else if boardEnemy[tempY][tempX] == EMPTY {
                                enemyOpenEnds = 1
                            } else if enemyRow > 0 {
                                enemyScore = enemyScore + getScore(enemyRow, enemyOpenEnds, false)
                                enemyRow, enemyOpenEnds = 0, 0
                            } else {
                                enemyOpenEnds = 0
                            }

                        }

                        if emptyPlayerRow > 0 {
                            emptyPlayerScore = emptyPlayerScore + getScore(emptyPlayerRow, emptyPlayerOpenEnds, false)
                        }
                        if emptyEnemyRow > 0 {
                            emptyEnemyScore = emptyEnemyScore + getScore(emptyEnemyRow, emptyEnemyOpenEnds, false)
                        }
                        if playerRow > 0 {
                            playerScore = playerScore + getScore(playerRow, playerOpenEnds, false)
                        }
                        if enemyRow > 0 {
                            enemyScore = enemyScore + getScore(enemyRow, enemyOpenEnds, false)
                        }
                        playerRow, enemyRow, emptyPlayerRow, emptyEnemyRow = 0, 0, 0, 0
                        playerOpenEnds, enemyOpenEnds, emptyPlayerOpenEnds, emptyEnemyOpenEnds = 0, 0, 0, 0
                    }

                    if playerPos.Capture != nil {
                        captures[player] += 2
                        captureScore = getCaptureScore(player)
                        if captureScore > playerScore {
                            playerScore = captureScore
                        }
                        captures[player] -= 2
                        captureScore = getCaptureScore(player)
                        if captureScore > emptyPlayerScore {
                            emptyPlayerScore = captureScore
                        }
                        boardPlayer[playerPos.Capture.Pos[0].Y][playerPos.Capture.Pos[0].X] = playerPos.Capture.Enemy
                        boardPlayer[playerPos.Capture.Pos[1].Y][playerPos.Capture.Pos[1].X] = playerPos.Capture.Enemy
                    }
                    if enemyPos.Capture != nil {
                        captures[enemy] += 2
                        captureScore = getCaptureScore(enemy)
                        if captureScore > enemyScore {
                            enemyScore = captureScore
                        }
                        captures[enemy] -= 2
                        captureScore = getCaptureScore(enemy)
                        if captureScore > emptyEnemyScore {
                            emptyEnemyScore = captureScore
                        }
                        boardEnemy[enemyPos.Capture.Pos[0].Y][enemyPos.Capture.Pos[0].X] = enemyPos.Capture.Enemy
                        boardEnemy[enemyPos.Capture.Pos[1].Y][enemyPos.Capture.Pos[1].X] = enemyPos.Capture.Enemy
                    }

                    playerScore = playerScore - emptyPlayerScore
                    enemyScore = enemyScore - emptyEnemyScore
                    if enemyScore > playerScore {
                        playerScore = enemyScore
                    }
                    if playerScore > 50000000 {
                        return Moves{{playerPos, playerScore}}
                    }
                    heap.Push(&moves, Move{playerPos, playerScore})

                    boardPlayer[y][x] = EMPTY
                    boardEnemy[y][x] = EMPTY
                }
            }
        }
    }
    return moves
}

func changePlayer(player int) int {
    if player == AI {
        return HUMAN
    }
    return AI
}

func finalScore(player int) int {
    var x, y, tempX, tempY int
    score1, row1, openEnds1 := 0, 0, 0
    score2, row2, openEnds2 := 0, 0, 0

    // Horizontal
    for y = 0; y < BoardHeight; y++ {
        for x = 0; x < BoardWidth; x++ {

            if board[y][x] == AI {
                row1 = row1 + 1
            } else if board[y][x] == EMPTY && row1 > 0 {
                openEnds1 = openEnds1 + 1
                score1 = score1 + getScore(row1, openEnds1, player == AI)
                row1, openEnds1 = 0, 1
            } else if board[y][x] == EMPTY {
                openEnds1 = 1
            } else if row1 > 0 {
                score1 = score1 + getScore(row1, openEnds1, player == AI)
                row1, openEnds1 = 0, 0
            } else {
                openEnds1 = 0
            }

            if board[y][x] == HUMAN {
                row2 = row2 + 1
            } else if board[y][x] == EMPTY && row2 > 0 {
                openEnds2 = openEnds2 + 1
                score2 = score2 + getScore(row2, openEnds2, player == HUMAN)
                row2, openEnds2 = 0, 1
            } else if board[y][x] == EMPTY {
                openEnds2 = 1
            } else if row2 > 0 {
                score2 = score2 + getScore(row2, openEnds2, player == HUMAN)
                row2, openEnds2 = 0, 0
            } else {
                openEnds2 = 0
            }

        }
        if row1 > 0 {
            score1 = score1 + getScore(row1, openEnds1, player == AI)
        } else if row2 > 0 {
            score2 = score2 + getScore(row2, openEnds2, player == HUMAN)
        }
        row1, row2, openEnds1, openEnds2 = 0, 0, 0, 0
    }

    // Vertical
    for x = 0; x < BoardWidth; x++ {
        for y = 0; y < BoardHeight; y++ {

            if board[y][x] == AI {
                row1 = row1 + 1
            } else if board[y][x] == EMPTY && row1 > 0 {
                openEnds1 = openEnds1 + 1
                score1 = score1 + getScore(row1, openEnds1, player == AI)
                row1, openEnds1 = 0, 1
            } else if board[y][x] == EMPTY {
                openEnds1 = 1
            } else if row1 > 0 {
                score1 = score1 + getScore(row1, openEnds1, player == AI)
                row1, openEnds1 = 0, 0
            } else {
                openEnds1 = 0
            }

            if board[y][x] == HUMAN {
                row2 = row2 + 1
            } else if board[y][x] == EMPTY && row2 > 0 {
                openEnds2 = openEnds2 + 1
                score2 = score2 + getScore(row2, openEnds2, player == HUMAN)
                row2, openEnds2 = 0, 1
            } else if board[y][x] == EMPTY {
                openEnds2 = 1
            } else if row2 > 0 {
                score2 = score2 + getScore(row2, openEnds2, player == HUMAN)
                row2, openEnds2 = 0, 0
            } else {
                openEnds2 = 0
            }

        }
        if row1 > 0 {
            score1 = score1 + getScore(row1, openEnds1, player == AI)
        } else if row2 > 0 {
            score2 = score2 + getScore(row2, openEnds2, player == HUMAN)
        }
        row1, row2, openEnds1, openEnds2 = 0, 0, 0, 0
    }

    // Diagonal 1.1
    for tempX = 0; tempX < BoardWidth; tempX++ {
        for y, x = 0, tempX; y < BoardHeight && x < BoardWidth; y, x = y+1, x+1 {
            if board[y][x] == AI {
                row1 = row1 + 1
            } else if board[y][x] == EMPTY && row1 > 0 {
                openEnds1 = openEnds1 + 1
                score1 = score1 + getScore(row1, openEnds1, player == AI)
                row1, openEnds1 = 0, 1
            } else if board[y][x] == EMPTY {
                openEnds1 = 1
            } else if row1 > 0 {
                score1 = score1 + getScore(row1, openEnds1, player == AI)
                row1, openEnds1 = 0, 0
            } else {
                openEnds1 = 0
            }

            if board[y][x] == HUMAN {
                row2 = row2 + 1
            } else if board[y][x] == EMPTY && row2 > 0 {
                openEnds2 = openEnds2 + 1
                score2 = score2 + getScore(row2, openEnds2, player == HUMAN)
                row2, openEnds2 = 0, 1
            } else if board[y][x] == EMPTY {
                openEnds2 = 1
            } else if row2 > 0 {
                score2 = score2 + getScore(row2, openEnds2, player == HUMAN)
                row2, openEnds2 = 0, 0
            } else {
                openEnds2 = 0
            }
        }
        if row1 > 0 {
            score1 = score1 + getScore(row1, openEnds1, player == AI)
        } else if row2 > 0 {
            score2 = score2 + getScore(row2, openEnds2, player == HUMAN)
        }
        row1, row2, openEnds1, openEnds2 = 0, 0, 0, 0
    }

    // Diagonal 1.2
    for tempY = 1; tempY < BoardHeight; tempY++ {
        for y, x = tempY, 0; y < BoardHeight && x < BoardWidth; y, x = y+1, x+1 {
            if board[y][x] == AI {
                row1 = row1 + 1
            } else if board[y][x] == EMPTY && row1 > 0 {
                openEnds1 = openEnds1 + 1
                score1 = score1 + getScore(row1, openEnds1, player == AI)
                row1, openEnds1 = 0, 1
            } else if board[y][x] == EMPTY {
                openEnds1 = 1
            } else if row1 > 0 {
                score1 = score1 + getScore(row1, openEnds1, player == AI)
                row1, openEnds1 = 0, 0
            } else {
                openEnds1 = 0
            }

            if board[y][x] == HUMAN {
                row2 = row2 + 1
            } else if board[y][x] == EMPTY && row2 > 0 {
                openEnds2 = openEnds2 + 1
                score2 = score2 + getScore(row2, openEnds2, player == HUMAN)
                row2, openEnds2 = 0, 1
            } else if board[y][x] == EMPTY {
                openEnds2 = 1
            } else if row2 > 0 {
                score2 = score2 + getScore(row2, openEnds2, player == HUMAN)
                row2, openEnds2 = 0, 0
            } else {
                openEnds2 = 0
            }
        }
        if row1 > 0 {
            score1 = score1 + getScore(row1, openEnds1, player == AI)
        } else if row2 > 0 {
            score2 = score2 + getScore(row2, openEnds2, player == HUMAN)
        }
        row1, row2, openEnds1, openEnds2 = 0, 0, 0, 0
    }

    // Diagonal 2.1
    for tempX = 0; tempX < BoardWidth; tempX++ {
        for y, x = 0, tempX; y < BoardHeight && x >= 0; y, x = y+1, x-1 {
            if board[y][x] == AI {
                row1 = row1 + 1
            } else if board[y][x] == EMPTY && row1 > 0 {
                openEnds1 = openEnds1 + 1
                score1 = score1 + getScore(row1, openEnds1, player == AI)
                row1, openEnds1 = 0, 1
            } else if board[y][x] == EMPTY {
                openEnds1 = 1
            } else if row1 > 0 {
                score1 = score1 + getScore(row1, openEnds1, player == AI)
                row1, openEnds1 = 0, 0
            } else {
                openEnds1 = 0
            }

            if board[y][x] == HUMAN {
                row2 = row2 + 1
            } else if board[y][x] == EMPTY && row2 > 0 {
                openEnds2 = openEnds2 + 1
                score2 = score2 + getScore(row2, openEnds2, player == HUMAN)
                row2, openEnds2 = 0, 1
            } else if board[y][x] == EMPTY {
                openEnds2 = 1
            } else if row2 > 0 {
                score2 = score2 + getScore(row2, openEnds2, player == HUMAN)
                row2, openEnds2 = 0, 0
            } else {
                openEnds2 = 0
            }
        }
        if row1 > 0 {
            score1 = score1 + getScore(row1, openEnds1, player == AI)
        } else if row2 > 0 {
            score2 = score2 + getScore(row2, openEnds2, player == HUMAN)
        }
        row1, row2, openEnds1, openEnds2 = 0, 0, 0, 0
    }

    // Diagonal 2.2
    for tempY = 1; tempY < BoardHeight; tempY++ {
        for y, x = tempY, BoardWidth-1; y < BoardHeight && x >= 0; y, x = y+1, x-1 {
            if board[y][x] == AI {
                row1 = row1 + 1
            } else if board[y][x] == EMPTY && row1 > 0 {
                openEnds1 = openEnds1 + 1
                score1 = score1 + getScore(row1, openEnds1, player == AI)
                row1, openEnds1 = 0, 1
            } else if board[y][x] == EMPTY {
                openEnds1 = 1
            } else if row1 > 0 {
                score1 = score1 + getScore(row1, openEnds1, player == AI)
                row1, openEnds1 = 0, 0
            } else {
                openEnds1 = 0
            }

            if board[y][x] == HUMAN {
                row2 = row2 + 1
            } else if board[y][x] == EMPTY && row2 > 0 {
                openEnds2 = openEnds2 + 1
                score2 = score2 + getScore(row2, openEnds2, player == HUMAN)
                row2, openEnds2 = 0, 1
            } else if board[y][x] == EMPTY {
                openEnds2 = 1
            } else if row2 > 0 {
                score2 = score2 + getScore(row2, openEnds2, player == HUMAN)
                row2, openEnds2 = 0, 0
            } else {
                openEnds2 = 0
            }
        }
        if row1 > 0 {
            score1 = score1 + getScore(row1, openEnds1, player == AI)
        } else if row2 > 0 {
            score2 = score2 + getScore(row2, openEnds2, player == HUMAN)
        }
        row1, row2, openEnds1, openEnds2 = 0, 0, 0, 0
    }

    return score1 - score2
}

func minimax(player, depth int, debug *Debug, alpha, beta int) Move {
    var bestScore int
    var pos *Position = nil
    var move Move
    score := 0

    if player == AI {
        bestScore = -10000000000
    } else {
        bestScore = 10000000000
    }

    possibleMoves := generateMoves(player)

    movesLen := possibleMoves.Len()
    for i := 0; movesLen > 0 && i < MovesCheck; movesLen, i = movesLen-1, i+1 {
        move = heap.Pop(&possibleMoves).(Move)
        board[move.pos.Y][move.pos.X] = player
        if move.pos.Capture != nil {
            board[move.pos.Capture.Pos[0].Y][move.pos.Capture.Pos[0].X] = EMPTY
            board[move.pos.Capture.Pos[1].Y][move.pos.Capture.Pos[1].X] = EMPTY
            captures[player] += 2
        }
        if debugMode {
            debug.Debug = append(debug.Debug, &Debug{move.score, 0, move.pos, player, -1, []*Debug{}})
        }
        if depth == 1 {
            if move.pos.Capture != nil {
                score1 := getCaptureScore(AI) - getCaptureScore(HUMAN)
                score2 := finalScore(changePlayer(player))
                if (player == AI && score1 > score2) ||
                    (player == HUMAN && score1 < score2) {
                    score = score1
                } else {
                    score = score2
                }
            } else {
                score = finalScore(changePlayer(player))
            }
        } else {
            if debugMode {
                score = minimax(changePlayer(player), depth-1, debug.Debug[i], alpha, beta).score
            } else {
                score = minimax(changePlayer(player), depth-1, nil, alpha, beta).score
            }
        }
        if move.pos.Capture != nil {
            captures[player] -= 2
            board[move.pos.Capture.Pos[0].Y][move.pos.Capture.Pos[0].X] = move.pos.Capture.Enemy
            board[move.pos.Capture.Pos[1].Y][move.pos.Capture.Pos[1].X] = move.pos.Capture.Enemy
        }
        board[move.pos.Y][move.pos.X] = EMPTY
        if (player == AI && score > bestScore) ||
            (player == HUMAN && score < bestScore) {
            bestScore = score
            pos = move.pos
            if debugMode {
                debug.Index = i
            }
        }
        if debugMode {
            debug.Debug[i].BestScore = bestScore
        }

        if player == AI && bestScore > alpha {
            alpha = bestScore
        } else if player == HUMAN && bestScore < beta {
            beta = bestScore
        }

        if beta <= alpha {
            break
        }
    }

    if pos != nil && pos.Capture != nil && pos.Capture.Enemy == player {
        pos.Capture = nil
    }

    if depth == Depth && pos == nil {
        pos = move.pos
    }

    return Move{pos, bestScore}
}
