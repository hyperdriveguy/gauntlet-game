/* The Gauntlet - A small battle gauntlet game to demonstrate C++ knowledge.
(c) 2023 Carson Bush - MIT License */

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <limits>
#include <cstdlib>
#include <time.h>

#include "include/prompts.h"

using std::string;

// Defines are for some game configuration
#define CHARACTER_POINTS 25
#define MAX_NUM_ATTACKS 4


// Define status effects
// An enum is for ease of use in switch-case
enum class StatusEffect {
	Normal,
	Poisoned,
	Burned,
	Frozen,
	Paralyzed,
	Andrenaline,
	Asleep,
	Dazed
};
// An array is used for ease of display
const char* StatusEffectString[] = {
	"Normal",
	"Poisoned",
	"Burned",
	"Frozen",
	"Paralyzed",
	"Andrenaline",
	"Asleep",
	"Dazed"
};


// Constants and defines related to attacks

/* Attacks are formatted like so:
	Name of attack (string),
	attacking stat (string),
	attack accuracy (0-100 int),
	status inflict (enum),
	status inflict chance (0-100 int)*/
struct Attack {
    string name;
    string attacking_stat;
    int attack_accuracy;
    StatusEffect status_inflict;
    int status_inflict_chance;
};
// Not to be confused with "Attack" above
enum class Attacks {
	Slap,
	GetNeighNeighed,
	SpicyCheese,
	RibPoke,
	BackInNam,
};

Attack ATTACK_LIST[] = {
	{"Slap", "strength", 100, StatusEffect::Normal, 20},
	{"Get Neigh Neighed", "speed", 85, StatusEffect::Burned, 50},
	{"Spicy Cheese", "skill", 65, StatusEffect::Burned, 50},
	{"Rib Poke", "strength", 90, StatusEffect::Normal, 0},
	{"Back In 'Nam", "stamina", 70, StatusEffect::Dazed, 90}
};


// Constants and defines related to enemies
#define NUM_ENEMIES 3
enum class Enemies {
	SpicyDorito,
	SkellyBoi,
	BabyBoomer
};

const char* ENEMY_NAMES[] = {"Spicy Dorito", "Skelly Boi", "Baby Boomer"};

// TODO: This uses a relatively high amount of RAM, make this more compact
const std::unordered_map<string, int> ENEMY_BASE_STATS[] = {
	{{"health", 2}, {"strength", 2}, {"skill", 6}, {"stamina", 10}, {"speed", 10}}, // Spicy Dorito
	{{"health", 10}, {"strength", 2}, {"skill", 6}, {"stamina", 2}, {"speed", 10}}, // Skelly Boi
	{{"health", 6}, {"strength", 6}, {"skill", 10}, {"stamina", 6}, {"speed", 2}}   // Baby Boomer
};

const Attacks ENEMY_ATTACKS[NUM_ENEMIES][MAX_NUM_ATTACKS] = {
	{Attacks::SpicyCheese, Attacks::GetNeighNeighed},
	{Attacks::Slap, Attacks::RibPoke},
	{Attacks::Slap, Attacks::BackInNam}
};



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
	// TODO: Methods
	public:

};

class Player : public Contestant {
	public:
		int experience;
		std::unordered_map<string, int> inventory;
		Player(string *nam, int lev, std::unordered_map<string, int>* b_stats) :
			Contestant(nam, lev, b_stats), experience(0) {}
};


void print_base_stats_table(std::unordered_map<string, int>& base_stats) {
	std::cout << std::left << std::setw(15) << "Attribute"
				<< std::setw(45) << "Description"
				<< std::right << std::setw(15) << "Level" << std::endl;
	std::cout << std::setfill('-') << std::setw(15 + 45 + 15) << "" << std::endl;
	std::cout << std::setfill(' ');

	std::cout << std::left << std::setw(15) << "Health"
				<< std::setw(45) << "How much damage you can take before you die"
				<< std::right << std::setw(15) << base_stats["health"] << std::endl;
	std::cout << std::left << std::setw(15) << "Strength"
				<< std::setw(45) << "Your brute power without weapons"
				<< std::right << std::setw(15) << base_stats["strength"] << std::endl;
	std::cout << std::left << std::setw(15) << "Skill"
				<< std::setw(45) << "How practiced you are in your talents"
				<< std::right << std::setw(15) << base_stats["skill"] << std::endl;
	std::cout << std::left << std::setw(15) << "Stamina"
				<< std::setw(45) << "How long it takes before you get exhausted"
				<< std::right << std::setw(15) << base_stats["stamina"] << std::endl;
	std::cout << std::left << std::setw(15) << "Speed"
				<< std::setw(45) << "How fast your movement and reactions are"
				<< std::right << std::setw(15) << base_stats["speed"] << std::endl;
}


std::unordered_map<string, int> distribute_stats() {
	std::unordered_map<string, int> base_stats;
	// Define shortcut letters
	std::unordered_map<string, string> option_map = {
		{"h", "health"},
		{"s", "strength"},
		{"k", "skill"},
		{"t", "stamina"},
		{"p", "speed"}
	};
	string confirm = "";
	do {
		int points_to_distribute = CHARACTER_POINTS;
		base_stats = {{"health", 1}, {"strength", 1}, {"skill", 1}, {"stamina", 1}, {"speed", 1}};
		while (points_to_distribute > 0) {
			clear_output();
			print_base_stats_table(base_stats);
			std::cout << "You have " << points_to_distribute << " points to distribute." << std::endl;

			// Stat increase prompt
			string stat_choice = prompt("Which stat would you like to increase? (Health, Strength, sKill, sTamina, sPeed)", true);
			// Error and shortcut handling
			if (stat_choice.length() == 1) {
				if (option_map.find(stat_choice) == option_map.end()) {
					message_wait("Not a valid stat shortcut, please try again.");
					continue;
				}
				stat_choice = option_map[stat_choice];
			}
			else if (base_stats.find(stat_choice) == base_stats.end()) {
				message_wait("Not a valid stat, please try again.");
				continue;
			}

			// Prompt for number of points
			int points_to_add = prompt_int("How many points would you like to add to this stat?");
			// Error check based on number of points available
			if(points_to_add > points_to_distribute) {
				message_wait("You don't have that many points to distribute.");
				continue;
			}

			// Distribute to respective stat
			base_stats[stat_choice] += points_to_add;
			points_to_distribute -= points_to_add;
		}
		// Show final stats before confirmation
		clear_output();
		print_base_stats_table(base_stats);
		confirm = prompt("Are you sure you want to distribute your points in this way? [y/N]", true);
	} while (confirm != "y");
	return base_stats;
}

Player new_game() {
	string confirm_name = "";
	string player_name = "";
	do {
		clear_output();
		player_name = prompt("What is your name?", true, true);
		std::cout << "So, " << player_name << " is your name? [y/N]";
		// Empty string is used for this prompt to avoid temporary variables
		confirm_name = prompt("", true);
	} while (confirm_name != "y");
	std::unordered_map<string, int> player_stats = distribute_stats();
	Player player(&player_name, 1, &player_stats);
	std::cout << "Chosen health: " << player.base_stats["health"] << std::endl;
	return player;
}

Contestant* generate_enemy(int level) {
	int enemy_index = rand() % NUM_ENEMIES;
	const string enemy_name = ENEMY_NAMES[enemy_index];
	std::unordered_map<string, int> enemy_bst = ENEMY_BASE_STATS[enemy_index];
	Contestant* enemy = new Contestant(&enemy_name, level, &enemy_bst);
	return enemy;
}

int main() {
	// Initialize random seeed
	srand(time(0));
	// Initialize player via new game sequence
	Player p = new_game();
	std::cout << "Chosen speed: " << p.base_stats["speed"] << std::endl;
	std::cout << "Your name: " << p.name << std::endl;
	Contestant new_e = *generate_enemy(rand() % 100);
	std::cout << "New enemy approaches: " << new_e.name << ", L:" << new_e.level << " HP:" << new_e.base_stats["health"] << std::endl;
	return 0;
}
