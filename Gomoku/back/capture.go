package main

func captureMove(y, x, player int) *Capture {
    if captureRule == false {
        return nil
    }

    enemy := changePlayer(player)
    poses := []int{enemy, enemy, player}

    allCoords := [8][]Coord{
        {{y, x - 1}, {y, x - 2}, {y, x - 3}},
        {{y, x + 1}, {y, x + 2}, {y, x + 3}},
        {{y - 1, x}, {y - 2, x}, {y - 3, x}},
        {{y + 1, x}, {y + 2, x}, {y + 3, x}},
        {{y - 1, x - 1}, {y - 2, x - 2}, {y - 3, x - 3}},
        {{y - 1, x + 1}, {y - 2, x + 2}, {y - 3, x + 3}},
        {{y + 1, x + 1}, {y + 2, x + 2}, {y + 3, x + 3}},
        {{y + 1, x - 1}, {y + 2, x - 2}, {y + 3, x - 3}},
    }

    for i := 0; i < 8; i++ {
        if validCoordsAndPoses(&allCoords[i], &poses) {
            return &Capture{enemy, allCoords[i][:2]}
        }
    }

    return nil
}

