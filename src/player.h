#ifndef __PLAYER_HEADER_INCLUDED__ // Start guard
#define __PLAYER_HEADER_INCLUDED__

// Essential imports
#include "contestant.h"
#include <iomanip>
#include <unordered_map>
#include "prompts.h"

// String is part of the namespace
using std::string;


class Player : public Contestant {
	private:
		/**
		* @var attacks
		* A a standard vector containing of all the Player's attacks.
		*/
		std::vector<Attacks> attacks;

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

		/**
		 * @param stat Key for accessing the base_stats unordered_map.
		 * Note: base_stats *is* the stat for the player.
		 * @return The stat corresponding to the key.
		 */
		float getStat(string stat) override;

		/**
		 * @param new_atk New attack to add to the player's moveset
		 */
		void addAttack(const Attacks new_atk);
};


/**
 * Prints out a table with base statistics of the player
 * @param base_stats A reference to an unordered map of base statistics with attributes as keys and levels as values
 */
void print_base_stats_table(std::unordered_map<string, int>& base_stats);

/**
 * Prompts the user to distribute points to base statistics of the player
 * @return A map of base statistics with attributes as keys and levels as values
 */
std::unordered_map<string, int> distribute_stats(const std::unordered_map<string, int> &init_stats = {{"health", 1}, {"strength", 1}, {"skill", 1}, {"stamina", 1}, {"speed", 1}});

/**
 * Creates a new player object and prompts the user for information
 * @return A pointer to the new player object
 */
Player* new_game();


#endif // End guard
