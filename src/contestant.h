#ifndef __CONTESTANT_HEADER_INCLUDED__ // Start guard
#define __CONTESTANT_HEADER_INCLUDED__

// Essential includes
#include "constants.h"
#include <string>
#include <vector>
#include <unordered_map>

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
		* One level scales all stats by adding an additional 0.2x for enemies
		*/
		int level;

	protected:
		/**
		* @var base_stats
		* A map of the Contestant's base stats such as health, strength, skill, stamina, and speed.
		*/
		std::unordered_map<string, int> base_stats;

		/**
		 * @var current_health
		 * The current health of the Contestant, based on base stats.
		 */
		int current_health;

		/**
		* @var status
		* The current status effect of the Contestant.
		*/
		StatusEffect status;

	private:
		/**
		 * @var all_attacks
		 * A pointer to a standard vector of all the Contestant's attacks.
		 */
		const std::vector<Attacks>* all_attacks;

	public:
		/**
		* @brief Constructor
		* @param nam A pointer to the name of the Contestant.
		* @param lev The level of the Contestant.
		* @param b_stats A pointer to the map of the Contestant's base stats.
		* @return A new instance of Contestant.
		*/
		Contestant(const string* nam, int lev, std::unordered_map<string, int>* b_stats) :
			name(*nam), level(lev), base_stats(*b_stats), current_health(getStat("health")), status(StatusEffect::Normal), all_attacks() {}

		/**
		* @brief Constructor
		* @param nam A pointer to the name of the Contestant.
		* @param lev The level of the Contestant.
		* @param b_stats A pointer to the map of the Contestant's base stats.
		* @param atks An array of the Contestant's attacks.
		* @return A new instance of Contestant.
		*/
		Contestant(const string* nam, int lev, std::unordered_map<string, int>* b_stats, const std::vector<Attacks>* atks) :
			name(*nam), level(lev), base_stats(*b_stats), current_health(getStat("health")), status(StatusEffect::Normal), all_attacks(atks) {}

		/**
		* @brief Default constructor
		* @return A new instance of Contestant with default values for name, level, status, and base_stats.
		*/
		Contestant() : name("Contestant"), level(1), base_stats({{"health", 1}, {"strength", 1}, {"skill", 1}, {"stamina", 1}, {"speed", 1}}), current_health(getStat("health")), status(StatusEffect::Normal), all_attacks() {}

		/**
		 * @param stat Key for accessing the base_stats unordered_map.
		 * @return The scaled stat corresponding to the key.
		 */
		virtual float getStat(string stat);

		/**
		 * @return Current health of the contestant.
		 */
		int getCurrentHealth();

		/**
		 * @return Whether StatusEffect::Normal is contained in status or not.
		 */
		bool isNormalStatus();

		/**
		 * @return Current StatusEffect as a string.
		 */
		string getStatusEffect();
};

#endif // End guard
