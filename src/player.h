#ifndef __PLAYER_HEADER_INCLUDED__ // Start guard
#define __PLAYER_HEADER_INCLUDED__

// Essential imports
#include "contestant.h"


class Player : public Contestant {
	public:
		int experience;
		std::unordered_map<string, int> inventory;
		Player(string *nam, int lev, std::unordered_map<string, int>* b_stats) :
			Contestant(nam, lev, b_stats), experience(0) {}
};

#endif // End guard
