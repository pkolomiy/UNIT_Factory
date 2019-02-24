from argparse import ArgumentParser, FileType, RawTextHelpFormatter
from Validation.Validator import Validator
import random


class Parser:
    def __init__(self):
        self.args = self.get_arguments()
        self.size = None
        self.puzzle = []
        if self.args.file:
            self.file = Validator.read_file(self.args.file.name)
            self.read_puzzle_from_file()
        elif self.args.random_number:
            self.size = self.args.random_number
        else:
            Validator.print_error_message("No puzzle - no program, sorry")
        self.puzzle_len = self.size ** 2
        self.target = [0 for _ in range(self.puzzle_len)]
        self.create_target()
        self.moves = self.get_moves()
        if len(self.puzzle) == 0:
            self.puzzle = self.target[:]
            self.create_random_puzzle()
        elif not self.solvable():
            Validator.print_error_message("Puzzle not solvable")

    @staticmethod
    def get_arguments():
        parser = ArgumentParser(add_help=False, usage=Parser.usage(),
                                formatter_class=RawTextHelpFormatter)
        parser.add_argument('-f', '--file', type=FileType())
        parser.add_argument('-a', '--algorithm', type=int, choices=[1, 2, 3, 4],
                            action="store", dest="algorithm_number", default=1,
                            required=False)
        parser.add_argument('-w', '--weight', type=int, action="store",
                            dest="heuristic_weight", default=1)
        parser.add_argument('-h', '--heuristic', type=int,
                            choices=[1, 2, 3, 4, 5], action="store",
                            dest="heuristic_number", default=1)
        parser.add_argument('-r', '--random', type=Validator.valid_random,
                            dest="random_number", required=False)
        return parser.parse_args()

    @staticmethod
    def usage():
        return '''
arguments:
  -f, --file FILE
  -r, --random NUMBER
          where NUMBER is size for generating random puzzle
optional:
  -a, --algorithm {1, 2, 3, 4} (default 1)
          where 1: A*: f = g + h
                2: A* with weight: f = g + h * w
                3: Only transition: f = g
                4: Only heuristic: f = h
  -w NUMBER (default 1)
          where NUMBER is weight for '-a 2' algorithm
  -h, --heuristic {1, 2, 3, 4, 5} (default 1)
          where 1: Hamming
                2: Out of row and column
                3: Euclidean distance
                4: Manhattan distance
                5: Manhattan distance with linear conflict'''

    def read_puzzle_from_file(self):
        for row in self.file:
            row = row.strip()
            if row.startswith("#"):
                continue
            arr = row.split()
            if self.size is None:
                if len(arr) == 1:
                    self.size = Validator.parse_int(arr[0])
                    continue
                else:
                    if arr[1].startswith("#"):
                        self.size = Validator.parse_int(arr[0])
                        continue
                    else:
                        Validator.print_error_message("Cannot parse matrix size")
            if self.size < 3:
                Validator.print_error_message("Matrix size should be more or equal to 3")
            if self.size != 0:
                if len(arr) < self.size:
                    Validator.print_error_message("Not valid puzzle")
                if len(arr) > self.size and not arr[self.size].startswith("#"):
                    Validator.print_error_message("Not valid puzzle")
                for index, value in enumerate(arr[0:self.size]):
                    num = Validator.validate_element(Validator.parse_int(value), self.size)
                    if num in self.puzzle:
                        Validator.print_error_message("Not valid puzzle")
                    self.puzzle.append(Validator.validate_element(num, self.size))

    def solvable(self):
        inversions = 0
        for i in range(self.puzzle_len - 1):
            for j in range(i + 1, self.puzzle_len):
                if self.puzzle[i] != 0 and self.puzzle[j] != 0 and \
                        self.puzzle[j] < self.puzzle[i]:
                    inversions += 1
                if self.target[i] != 0 and self.target[j] != 0 and \
                        self.target[j] < self.target[i]:
                    inversions += 1
        if self.size % 2 == 0:
            inversions += (self.puzzle.index(0) // self.size)
            inversions += (self.target.index(0) // self.size)
        return inversions % 2 == 0

    def create_target(self):
        i, j = 0, 0
        step_i, step_j = 0, 1
        for n in range(1, self.puzzle_len):
            self.target[i * self.size + j] = n
            new_i = i + step_i
            new_j = j + step_j
            if 0 <= new_i < self.size and \
               0 <= new_j < self.size and \
               self.target[new_i * self.size + new_j] == 0:
                i = new_i
                j = new_j
            else:
                step_j, step_i = -step_i, step_j
                i = i + step_i
                j = j + step_j

    def get_moves(self):
        moves = {}
        for i in range(self.puzzle_len):
            moves[i] = []
            if (i % self.size) + 1 < self.size:
                moves[i].append(1)
            if (i % self.size) - 1 >= 0:
                moves[i].append(-1)
            if i + self.size < self.puzzle_len:
                moves[i].append(self.size)
            if i - self.size >= 0:
                moves[i].append(-self.size)
        return moves

    def create_random_puzzle(self):
        for _ in range(10000):
            zero_position = self.puzzle.index(0)
            new_position = random.choice(self.moves[zero_position])
            new_position += zero_position
            self.puzzle[zero_position] = self.puzzle[new_position]
            self.puzzle[new_position] = 0
