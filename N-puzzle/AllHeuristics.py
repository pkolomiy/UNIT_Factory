from Heuristics.Hamming import Hamming
from Heuristics.Manhattan import Manhattan
from Heuristics.LinearConflict import LinearConflict
from Heuristics.Euclidean import Euclidean
from Heuristics.OutOfRowColumn import OutOfRowColumn

List = {
    1: {
        'class': Hamming,
        'name': 'Hamming Distance / Misplaced Tiles'
    },
    2: {
        'class': OutOfRowColumn,
        'name': 'Number of tiles Out of Row and Column'
    },
    3: {
        'class': Euclidean,
        'name': 'Euclidean Distance'
    },
    4: {
        'class': Manhattan,
        'name': 'Manhattan Distance / Taxicab geometry'
    },
    5: {
        'class': LinearConflict,
        'name': 'Manhattan + Linear Conflict'
    },
}
