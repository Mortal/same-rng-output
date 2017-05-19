import random
import argparse


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('seed', type=int)
    args = parser.parse_args()

    random.seed(args.seed)
    print(random.getstate())


if __name__ == '__main__':
    main()
