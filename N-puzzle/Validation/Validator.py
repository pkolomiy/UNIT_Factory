from argparse import ArgumentTypeError


class Validator:
    @staticmethod
    def print_error_message(error_message):
        print(error_message)
        exit(1)

    @staticmethod
    def parse_int(string):
        try:
            return int(string)
        except:
            Validator.print_error_message("Cannot cast to int '%s'" % string)

    @staticmethod
    def valid_random(string):
        value = Validator.parse_int(string)
        if value < 3:
            raise ArgumentTypeError("%r must be >= 3" % string)
        return value

    @staticmethod
    def read_file(file_name):
        try:
            return open(file_name, 'r')
        except:
            Validator.print_error_message("Error open file")

    @staticmethod
    def validate_element(number, arr_size):
        if 0 <= number < arr_size * arr_size:
            return number
        else:
            Validator.print_error_message("Number '%d' is invalid" % number)
