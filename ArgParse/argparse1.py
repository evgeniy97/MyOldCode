import argparse

parser = argparse.ArgumentParser()
# Позиционный аргумент, то есть нужен всегда и имеет свой порядок
parser.add_argument("square", help="display a square of a given number",type=float)
# Дополнительный аргумент 
parser.add_argument("-v", "--verbose", default=False, help="increase output verbosity")
args = parser.parse_args()

def main():
    print(args.square**2)
    if args.verbose:
        print('verbose on')

if __name__ == '__main__':
    main()