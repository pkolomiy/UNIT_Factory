from Algorithms import Algorithms
import AllHeuristics
from Validation.Node import Node
from Validation.Parser import Parser


class NPuzzle(Parser):
    def __init__(self):
        super().__init__()
        self.parent = Node(self.puzzle)
        nbr = self.args.heuristic_number
        self.heuristic = AllHeuristics.List[nbr]['class'](self.size)
        self.heuristic_name = AllHeuristics.List[nbr]['name']
        self.heuristic_weight = self.args.heuristic_weight
        self.algorithm = self.args.algorithm_number

    def solve(self, node):
        if self.algorithm == Algorithms.A_STAR:
            node.h = self.heuristic.get_h(node.puzzle, self.target)
            node.f = node.g + node.h
        elif self.algorithm == Algorithms.A_STAR_WITH_WEIGHT:
            node.h = self.heuristic.get_h(node.puzzle, self.target)
            node.f = node.g + (node.h * self.heuristic_weight)
        elif self.algorithm == Algorithms.ONLY_H:
            node.h = self.heuristic.get_h(node.puzzle, self.target)
            node.f = node.h
        elif self.algorithm == Algorithms.ONLY_G:
            node.f = node.g
