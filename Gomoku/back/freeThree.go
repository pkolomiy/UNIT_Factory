package main

func validCoordsAndPoses(
    coords *[]Coord,
    poses *[]int,
) bool {
    for index, coord := range *coords {
        if coord.Y < 0 || coord.X < 0 ||
            coord.Y >= BoardHeight || coord.X >= BoardWidth ||
            board[coord.Y][coord.X] != (*poses)[index] {
            return false
        }
    }
    return true
}

func checkForFreeThree(y, x, player int) bool {
    poses := [3][]int{
        {EMPTY, player, player, player, EMPTY},
        {EMPTY, player, EMPTY, player, player, EMPTY},
        {EMPTY, player, player, EMPTY, player, EMPTY},
    }
    coords := [3][]Coord{
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
    }
    var tempY, tempX int

    // Horizontal
    for tempX = x - 4; tempX <= x; tempX++ {
        coords[0][0].Y, coords[0][1].Y, coords[0][2].Y, coords[0][3].Y, coords[0][4].Y, coords[1][0].Y, coords[1][1].Y, coords[1][2].Y, coords[1][3].Y, coords[1][4].Y, coords[1][5].Y, coords[2][0].Y, coords[2][1].Y, coords[2][2].Y, coords[2][3].Y, coords[2][4].Y, coords[2][5].Y, coords[0][0].X, coords[0][1].X, coords[0][2].X, coords[0][3].X, coords[0][4].X, coords[1][0].X, coords[1][1].X, coords[1][2].X, coords[1][3].X, coords[1][4].X, coords[1][5].X, coords[2][0].X, coords[2][1].X, coords[2][2].X, coords[2][3].X, coords[2][4].X, coords[2][5].X = y, y, y, y, y, y, y, y, y, y, y, y, y, y, y, y, y, tempX, tempX+1, tempX+2, tempX+3, tempX+4, tempX, tempX+1, tempX+2, tempX+3, tempX+4, tempX+5, tempX, tempX+1, tempX+2, tempX+3, tempX+4, tempX+5
        if validCoordsAndPoses(&coords[0], &poses[0]) || validCoordsAndPoses(&coords[1], &poses[1]) || validCoordsAndPoses(&coords[2], &poses[2]) {
            return true
        }
    }

    // Vertical
    for tempY = y - 4; tempY <= y; tempY++ {
        coords[0][0].Y, coords[0][1].Y, coords[0][2].Y, coords[0][3].Y, coords[0][4].Y, coords[1][0].Y, coords[1][1].Y, coords[1][2].Y, coords[1][3].Y, coords[1][4].Y, coords[1][5].Y, coords[2][0].Y, coords[2][1].Y, coords[2][2].Y, coords[2][3].Y, coords[2][4].Y, coords[2][5].Y, coords[0][0].X, coords[0][1].X, coords[0][2].X, coords[0][3].X, coords[0][4].X, coords[1][0].X, coords[1][1].X, coords[1][2].X, coords[1][3].X, coords[1][4].X, coords[1][5].X, coords[2][0].X, coords[2][1].X, coords[2][2].X, coords[2][3].X, coords[2][4].X, coords[2][5].X = tempY, tempY+1, tempY+2, tempY+3, tempY+4, tempY, tempY+1, tempY+2, tempY+3, tempY+4, tempY+5, tempY, tempY+1, tempY+2, tempY+3, tempY+4, tempY+5, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x
        if validCoordsAndPoses(&coords[0], &poses[0]) || validCoordsAndPoses(&coords[1], &poses[1]) || validCoordsAndPoses(&coords[2], &poses[2]) {
            return true
        }
    }

    // Diagonal 1
    for tempY, tempX = y-4, x-4; tempX <= x; tempY, tempX = tempY+1, tempX+1 {
        coords[0][0].Y, coords[0][1].Y, coords[0][2].Y, coords[0][3].Y, coords[0][4].Y, coords[1][0].Y, coords[1][1].Y, coords[1][2].Y, coords[1][3].Y, coords[1][4].Y, coords[1][5].Y, coords[2][0].Y, coords[2][1].Y, coords[2][2].Y, coords[2][3].Y, coords[2][4].Y, coords[2][5].Y, coords[0][0].X, coords[0][1].X, coords[0][2].X, coords[0][3].X, coords[0][4].X, coords[1][0].X, coords[1][1].X, coords[1][2].X, coords[1][3].X, coords[1][4].X, coords[1][5].X, coords[2][0].X, coords[2][1].X, coords[2][2].X, coords[2][3].X, coords[2][4].X, coords[2][5].X = tempY, tempY+1, tempY+2, tempY+3, tempY+4, tempY, tempY+1, tempY+2, tempY+3, tempY+4, tempY+5, tempY, tempY+1, tempY+2, tempY+3, tempY+4, tempY+5, tempX, tempX+1, tempX+2, tempX+3, tempX+4, tempX, tempX+1, tempX+2, tempX+3, tempX+4, tempX+5, tempX, tempX+1, tempX+2, tempX+3, tempX+4, tempX+5
        if validCoordsAndPoses(&coords[0], &poses[0]) || validCoordsAndPoses(&coords[1], &poses[1]) || validCoordsAndPoses(&coords[2], &poses[2]) {
            return true
        }
    }

    // Diagonal 2
    for tempY, tempX = y+4, x-4; tempX <= x; tempY, tempX = tempY-1, tempX+1 {
        coords[0][0].Y, coords[0][1].Y, coords[0][2].Y, coords[0][3].Y, coords[0][4].Y, coords[1][0].Y, coords[1][1].Y, coords[1][2].Y, coords[1][3].Y, coords[1][4].Y, coords[1][5].Y, coords[2][0].Y, coords[2][1].Y, coords[2][2].Y, coords[2][3].Y, coords[2][4].Y, coords[2][5].Y, coords[0][0].X, coords[0][1].X, coords[0][2].X, coords[0][3].X, coords[0][4].X, coords[1][0].X, coords[1][1].X, coords[1][2].X, coords[1][3].X, coords[1][4].X, coords[1][5].X, coords[2][0].X, coords[2][1].X, coords[2][2].X, coords[2][3].X, coords[2][4].X, coords[2][5].X = tempY, tempY-1, tempY-2, tempY-3, tempY-4, tempY, tempY-1, tempY-2, tempY-3, tempY-4, tempY-5, tempY, tempY-1, tempY-2, tempY-3, tempY-4, tempY-5, tempX, tempX+1, tempX+2, tempX+3, tempX+4, tempX, tempX+1, tempX+2, tempX+3, tempX+4, tempX+5, tempX, tempX+1, tempX+2, tempX+3, tempX+4, tempX+5
        if validCoordsAndPoses(&coords[0], &poses[0]) || validCoordsAndPoses(&coords[1], &poses[1]) || validCoordsAndPoses(&coords[2], &poses[2]) {
            return true
        }
    }

    return false
}

func resetFreeThrees() {
    freeThreeAI = false
    freeThreeHuman = false

    for y := 0; y < BoardHeight; y++ {
        for x := 0; x < BoardWidth; x++ {
            if freeThreeAI == true && freeThreeHuman == true {
                return
            }

            if freeThreeAI == false && board[y][x] == AI &&
                checkForFreeThree(y, x, AI) {
                freeThreeAI = true
            }

            if freeThreeHuman == false && board[y][x] == HUMAN &&
                checkForFreeThree(y, x, HUMAN) {
                freeThreeHuman = true
            }
        }
    }
}
