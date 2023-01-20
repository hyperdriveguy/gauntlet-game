#ifndef __PLAYER_HEADER_INCLUDED__ // Start guard
#define __PLAYER_HEADER_INCLUDED__

// Essential imports
#include "contestant.h"


class Player : public Contestant {
	public:
		/**
		* @var experience
		* The player's experience points.
		*/
		int experience;

		/**
		* @var inventory
		* A map of the player's inventory items.
		*/
		std::unordered_map<string, int> inventory;

		/**
		* @brief Constructor
		* @param nam A pointer to the name of the player.
		* @param lev The level of the player.
		* @param b_stats A pointer to the map of the player's base stats.
		* @return A new instance of Player.
		*/
		Player(string *nam, int lev, std::unordered_map<string, int>* b_stats) :
			Contestant(nam, lev, b_stats), experience(0) {}
};

#endif // End guard
