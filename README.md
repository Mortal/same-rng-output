Getting the same output from C++ and Python Mersenne Twister
============================================================

Both Python and C++ have a Mersenne Twister engine in their standard library
for outputting pseudo-random 32-bit numbers.

However, the initialization of the states of the two PRNG implementations is
different.

With some care, a PRNG initialized in Python can be mimicked in C++,
and vice-versa.

The programs in this repository are:

* `rng.py`/`cpp` - straightforward generation of n random numbers
* `get_seed.py`/`cpp` - outputting the Mersenne Twister state after straightforward initialization
* `set_seed.py`/`cpp` - setting the MT state from the state in a foreign language

For example, the two programs output the same sequence of pseudorandom numbers,
for all values of `$N` and `$SEED`:

* `g++ -o rng rng.cpp && ./rng $N $SEED`
* `python3 set_seed.py $N $SEED`
