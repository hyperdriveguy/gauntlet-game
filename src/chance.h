#ifndef __CHANCE_HEADER_INCLUDED__ // Start guard
#define __CHANCE_HEADER_INCLUDED__

// Essential imports
#include <random>


class Chance {
	private:
		std::random_device rand_dev;
		std::mt19937 engine;
	public:
		Chance() : engine(rand_dev()) {}
		Chance(uint seed) : engine(seed) {}
		bool percent(int threshold);
		bool percent(uint threshold);
		int range(int min, int max);
		uint range(uint min, uint max);
		double range(double min, double max);
};


#endif // End guard
