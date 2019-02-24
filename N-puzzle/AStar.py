from bisect import insort_left
from Algorithms import Algorithms
from Validation.Node import Node


class AStar:
    def __init__(self, n_puzzle):
        self.n_puzzle = n_puzzle
        self.closed_list = set()
        self.open_list = [n_puzzle.parent]
        self.open_dict = {n_puzzle.parent.key: n_puzzle.parent}
        self.goal = str(n_puzzle.target)
        self.size = 0

    def algorithm(self):
        while self.open_list:
            node = self.open_dict[(self.open_list.pop(0)).key]
            if node.key == self.goal:
                return self.show_results(node)
            del self.open_dict[node.key]
            if node.key not in self.closed_list:
                self.closed_list.add(node.key)
                for move in self.n_puzzle.moves[node.zero_pos]:
                    index = node.zero_pos + move
                    new_puzzle = node.puzzle[:]
                    new_puzzle[node.zero_pos], new_puzzle[index] = \
                        new_puzzle[index], new_puzzle[node.zero_pos]
                    key = str(new_puzzle)
                    if key == self.goal:
                        return self.show_results(Node(new_puzzle, node))
                    if key not in self.closed_list:
                        new_node = Node(new_puzzle, node)
                        self.n_puzzle.solve(new_node)
                        if (key not in self.open_dict) or \
                            (key in self.open_dict and
                             new_node.g < self.open_dict[key].g and
                             new_node.h < self.open_dict[key].h):
                            self.open_dict[key] = new_node
                            insort_left(self.open_list, new_node)
                            self.size += 1

    def show_results(self, node):
        self.show_path(node, self.n_puzzle.size)
        print('Complexity in time = ', len(self.closed_list))
        print('Complexity in size = ', self.size)
        print('Number of moves = ', node.g)
        print('Algorithm: ', Algorithms.Name[self.n_puzzle.algorithm])
        print('Heuristic: ', self.n_puzzle.heuristic_name)

    def show_path(self, node, size):
        if node.parent is not None:
            self.show_path(node.parent, size)
        print('-' * size * 2, node.g, '-' * size * 2)
        while node.puzzle:
            print(node.puzzle[:size])
            node.puzzle = node.puzzle[size:]
        print('')
