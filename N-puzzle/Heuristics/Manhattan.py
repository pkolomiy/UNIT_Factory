from Heuristics.Hamming import Hamming


class Manhattan(Hamming):
    def __init__(self, size):
        super().__init__(size)
        self.map = self.distance_map(size)

    def heuristic(self, puzzle, target_puzzle, i):
        return self.map[i][target_puzzle.index(puzzle[i])]

    @staticmethod
    def distance_map(size):
        dist_map = {}
        for k in range(size):
            for l in range(size):
                dist_map[(k * size) + l] = [
                    abs(i - k) + abs(j - l)
                    for i in range(size)
                    for j in range(size)
                ]
        return dist_map
