#ifndef __CONTESTANT_HEADER_INCLUDED__ // Start guard
#define __CONTESTANT_HEADER_INCLUDED__

#include <string>
#include <unordered_map>

#include "constants.h"

using std::string;

class Contestant {
	public:
		string name;
		// One level scales all stats by 1.2x
		int level;
		std::unordered_map<string, int> base_stats;
		StatusEffect status;
		Attacks* all_attacks;
		Contestant(const string* nam, int lev, std::unordered_map<string, int>* b_stats) :
			name(*nam), level(lev), base_stats(*b_stats), status(StatusEffect::Normal) {}
		Contestant(const string* nam, int lev, std::unordered_map<string, int>* b_stats, Attacks atks[MAX_NUM_ATTACKS]) :
			name(*nam), level(lev), base_stats(*b_stats), all_attacks(atks), status(StatusEffect::Normal) {}
		Contestant() : name("Contestant"), level(1), status(StatusEffect::Normal), base_stats({{"health", 1}, {"strength", 1}, {"skill", 1}, {"stamina", 1}, {"speed", 1}}) {}
		// TODO: Constructor that doesn't require passing in an unordered_map pointer
};

#endif // End guard
