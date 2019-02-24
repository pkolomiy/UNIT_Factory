from math import sqrt
from Heuristics.Manhattan import Manhattan


class Euclidean(Manhattan):
    def __init__(self, size):
        super().__init__(size)

    @staticmethod
    def distance_map(size):
        dist_map = {}
        for k in range(size):
            for l in range(size):
                dist_map[(k * size) + l] = [
                    sqrt((i - k)**2 + (j - l)**2)
                    for i in range(size)
                    for j in range(size)
                ]
        return dist_map
