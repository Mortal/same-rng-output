#include <algorithm>
#include <cstdint>
#include <random>
#include <sstream>
#include <iostream>

int main(int argc, char ** argv) {
	size_t n;
	uint32_t seed;

	if (argc < 3) return 1;
	std::stringstream(argv[1]) >> n;
	std::stringstream(argv[2]) >> seed;

	std::mt19937 rng(seed);
	for (size_t i = 0; i < n; ++i) std::cout << rng() << std::endl;
	return 0;
}

