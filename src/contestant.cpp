#include "contestant.h"

float Contestant::getStat(string stat) {
	return (level - 1) * 0.2 + base_stats[stat];
}
