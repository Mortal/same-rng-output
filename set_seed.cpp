#include <algorithm>
#include <cstdint>
#include <random>
#include <sstream>
#include <iostream>

struct my_naive_seed {
	std::vector<uint32_t> seeds;

	template <typename IT>
	void generate(IT b, IT e) {
		if (std::distance(b, e) != seeds.size()) {
			std::cout << std::distance(b, e) << std::endl;
			std::cout << seeds.size() << std::endl;
			throw std::runtime_error("Wrong number of seeds");
		}
		std::copy(seeds.begin(), seeds.end(), b);
	}
};

int main(int argc, char ** argv) {
	size_t n;
	my_naive_seed seed;

	if (argc < 2) return 1;
	std::stringstream(argv[1]) >> n;

	uint32_t x;
	while (std::cin >> x) seed.seeds.push_back(x);

	std::mt19937 rng(seed);
	for (size_t i = 0; i < n; ++i) std::cout << rng() << std::endl;
	return 0;
}
