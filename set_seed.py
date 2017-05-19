import random
import argparse


def get_state(seed, state_size=624, w=32, f=1812433253):
    # See also:
    # http://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine/mersenne_twister_engine
    result = [seed]
    for i in range(1, state_size):
        x = result[-1]
        x ^= x >> (w - 2)
        x *= f
        x += i
        result.append(x % (2**w))
    result.append(state_size)
    return 3, tuple(result), None


def cxx_seed(seed):
    '''
    Run random.setstate in a manner equivalent to std::mt19937::seed in C++.

    For all seed values n, the following two programs have the same output.

    First, in Python:

        cxx_seed(n)
        for i in range(10000):
            print(random.getrandbits(32))

    Second, in C++:

        std::mt19937 rng(n);
        for (size_t i = 0; i < 10000; ++i)
            std::cout << rng() << std::endl;
    '''
    state = get_state(seed)
    # import subprocess
    # output = subprocess.check_output(('./get_seed', str(args.seed)))
    # state2 = eval(output)
    # assert state == state2
    random.setstate(state)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('n', type=int)
    parser.add_argument('seed', type=int)
    args = parser.parse_args()

    cxx_seed(args.seed)
    for i in range(args.n):
        print(random.getrandbits(32))


if __name__ == '__main__':
    main()
