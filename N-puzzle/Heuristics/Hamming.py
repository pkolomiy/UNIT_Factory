class Hamming:
    def __init__(self, size):
        self.size = size
        self.puzzle_len = size ** 2

    def get_h(self, puzzle, target_puzzle):
        h = 0
        for i in range(self.puzzle_len):
            if puzzle[i] != target_puzzle[i] and puzzle[i] != 0:
                h += self.heuristic(puzzle, target_puzzle, i)
        return h

    def heuristic(self, puzzle, target_puzzle, i):
        return 1
