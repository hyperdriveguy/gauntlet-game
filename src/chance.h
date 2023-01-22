#ifndef __CHANCE_HEADER_INCLUDED__ // Start guard
#define __CHANCE_HEADER_INCLUDED__

// Essential imports
#include <random>
#include "constants.h"


class Chance {
	private:
		std::random_device rand_dev;
		std::mt19937 engine;
	public:
		Chance() : engine(rand_dev()) {}
		Chance(uint seed) : engine(seed), rand_dev() {}
		bool percent(int threshold);
		bool percent(uint threshold);
		int range(int min, int max);
		uint range(uint min, uint max);
		double range(double min, double max);
		int enemyIndex();
};


#endif // End guard
