import random
import argparse


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('seed', type=int)
    parser.add_argument('n', type=int)
    args = parser.parse_args()

    random.seed(args.seed)
    for i in range(args.n):
        print(random.getrandbits(32))


if __name__ == '__main__':
    main()
