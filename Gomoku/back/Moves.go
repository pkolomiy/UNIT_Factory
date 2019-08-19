package main

// Moves class
type Moves []Move

func (moves Moves) Len() int {
    return len(moves)
}

func (moves *Moves) Less(i, j int) bool {
    return (*moves)[i].score > (*moves)[j].score
}

func (moves Moves) Swap(i, j int) {
    moves[i], moves[j] = moves[j], moves[i]
}

func (moves *Moves) Push(el interface{}) {
    *moves = append(*moves, el.(Move))
}

func (moves *Moves) Pop() interface{} {
    item := (*moves)[moves.Len()-1]
    *moves = (*moves)[0 : moves.Len()-1]
    return item
}
