#!/Users/pkolomiy/.brew/bin/python3
import sys
from Validation.NPuzzle import NPuzzle
from Validation.Parser import Parser
from Validation.Validator import Validator
from AStar import AStar

if __name__ == '__main__':
    if len(sys.argv) < 2:
        Validator.print_error_message(Parser.usage())
    n_puzzle = NPuzzle()
    AStar(n_puzzle).algorithm()
