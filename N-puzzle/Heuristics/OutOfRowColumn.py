from Heuristics.Manhattan import Manhattan


class OutOfRowColumn(Manhattan):
    def __init__(self, size):
        super().__init__(size)
        self.map = self.row_column_map(self.puzzle_len, size)

    @staticmethod
    def row_column_map(puzzle_len, size):
        new_map = {}
        template = [2 for _ in range(puzzle_len)]
        for i in range(puzzle_len):
            new_map[i] = template[:]
            for j in range(1, size):
                new_map[i][((((i - j) + size) % size) +
                            ((i // size) * size))] = 1
                new_map[i][((i - (j * size)) % puzzle_len)] = 1
            new_map[i][i] = 0
        return new_map
