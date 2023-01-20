#ifndef __CONTESTANT_HEADER_INCLUDED__ // Start guard
#define __CONTESTANT_HEADER_INCLUDED__

#include <string>
#include <unordered_map>

#include "constants.h"

using std::string;

class Contestant {
	public:
		/**
		* @var name
		* The name of the Contestant.
		*/
		string name;

		/**
		* @var level
		* The level of the Contestant.
		* One level scales all stats by 1.2x
		*/
		int level;

		/**
		* @var base_stats
		* A map of the Contestant's base stats.
		*/
		std::unordered_map<string, int> base_stats;

		/**
		* @var status
		* The current status effect of the Contestant.
		*/
		StatusEffect status;

		/**
		* @var all_attacks
		* A pointer to an array of all the Contestant's attacks.
		*/
		Attacks* all_attacks;

		/**
		* @brief Constructor
		* @param nam A pointer to the name of the Contestant.
		* @param lev The level of the Contestant.
		* @param b_stats A pointer to the map of the Contestant's base stats.
		* @return A new instance of Contestant.
		*/
		Contestant(const string* nam, int lev, std::unordered_map<string, int>* b_stats) :
			name(*nam), level(lev), base_stats(*b_stats), status(StatusEffect::Normal) {}

		/**
		* @brief Constructor
		* @param nam A pointer to the name of the Contestant.
		* @param lev The level of the Contestant.
		* @param b_stats A pointer to the map of the Contestant's base stats.
		* @param atks An array of the Contestant's attacks.
		* @return A new instance of Contestant.
		*/
		Contestant(const string* nam, int lev, std::unordered_map<string, int>* b_stats, Attacks atks[MAX_NUM_ATTACKS]) :
			name(*nam), level(lev), base_stats(*b_stats), all_attacks(atks), status(StatusEffect::Normal) {}

		/**
		* @brief Default constructor
		* @return A new instance of Contestant with default values for name, level, status, and base_stats.
		*/
		Contestant() : name("Contestant"), level(1), status(StatusEffect::Normal), base_stats({{"health", 1}, {"strength", 1}, {"skill", 1}, {"stamina", 1}, {"speed", 1}}) {}

		// TODO: Constructor that doesn't require passing in an unordered_map pointer
};

#endif // End guard
