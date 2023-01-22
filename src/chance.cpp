#include "chance.h"

bool Chance::percent(int threshold) {
	std::uniform_int_distribution<> distr(0, 100);
	int roll = distr(engine);
	return (roll <= threshold);
}

bool Chance::percent(uint threshold) {
	std::uniform_int_distribution<> distr(0, 100);
	uint roll = distr(engine);
	return (roll <= threshold);
}

int Chance::range(int min, int max) {
	std::uniform_int_distribution<> distr(min, max);
	return distr(engine);
}

uint Chance::range(uint min, uint max) {
	std::uniform_int_distribution<> distr(min, max);
	return distr(engine);
}

double Chance::range(double min, double max) {
	std::uniform_real_distribution<> distr(min, max);
	return distr(engine);
}

int Chance::enemyIndex() {
	std::uniform_int_distribution<> distr(0, NUM_ENEMIES - 1);
	return distr(engine);
}
