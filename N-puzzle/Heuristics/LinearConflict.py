from Heuristics.Manhattan import Manhattan


class LinearConflict(Manhattan):
    def __init__(self, size):
        super().__init__(size)
        self.linearMap = self.linear_map(self.puzzle_len, size)

    def conflict(self, puzzle, target_puzzle, i):
        linear = 0
        t_index = target_puzzle.index(puzzle[i])
        if t_index in self.linearMap[i]['row']:
            for index in self.linearMap[i]['row']:
                if (((t_index > i) and i < index <= t_index) or
                    ((t_index < i) and
                     t_index <= index < i)) and \
                        (target_puzzle.index(puzzle[index]) in
                         self.linearMap[i]['row'] or
                         target_puzzle.index(puzzle[index]) == i):
                    linear += 1
        if t_index in self.linearMap[i]['column']:
            for index in self.linearMap[i]['column']:
                if (((t_index > i) and i < index <= t_index) or
                    ((t_index < i) and
                     t_index <= index < i)) and \
                        (target_puzzle.index(puzzle[index]) in
                         self.linearMap[i]['column'] or
                         target_puzzle.index(puzzle[index]) == i):
                    linear += 1
        return linear

    def heuristic(self, puzzle, target_puzzle, i):
        return self.map[i][target_puzzle.index(puzzle[i])] + \
               self.conflict(puzzle, target_puzzle, i)

    @staticmethod
    def linear_map(puzzle_len, size):
        lin_map = []
        for i in range(puzzle_len):
            lin_map.append({'row': [], 'column': []})
            for j in range(1, size):
                lin_map[i]['column'].append((i + (size * j)) % puzzle_len)
                lin_map[i]['row'].append(((i // size) * size) +
                                         (((i % size) + j) % size))
        return lin_map
