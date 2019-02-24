class Algorithms:
    A_STAR = 1
    A_STAR_WITH_WEIGHT = 2
    ONLY_H = 3
    ONLY_G = 4
    Name = {
        A_STAR: 'A*: f = g + h',
        A_STAR_WITH_WEIGHT: 'A* with weight: f = g + h * w',
        ONLY_G: 'Use only transition value: f = g',
        ONLY_H: 'Use only value of heuristic: f = h',
    }
