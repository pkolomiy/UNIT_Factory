class Node:
    def __init__(self, puzzle, parent=None):
        self.puzzle = puzzle
        self.zero_pos = puzzle.index(0)
        self.key = str(puzzle)
        self.parent = parent
        self.g = parent.g + 1 if parent is not None else 0
        self.h = 0
        self.f = 0

    def __lt__(self, other):
        if self.f == other.f:
            if self.h == other.h:
                return self.g < other.g
            return self.h < other.h
        return self.f < other.f
