#include <algorithm>
#include <cstdint>
#include <random>
#include <sstream>
#include <iostream>

int main(int argc, char ** argv) {
	uint32_t seed;

	if (argc < 2) return 1;
	std::stringstream(argv[1]) >> seed;

	std::mt19937 rng(seed);
	std::mt19937::result_type * state = reinterpret_cast<std::mt19937::result_type *>(&rng);
	std::cout << "(3, (";
	for (size_t i = 0; i < std::mt19937::state_size; ++i)
		std::cout << state[i] << ", ";
	std::cout << std::mt19937::state_size << "), None)" << std::endl;
	return 0;
}

