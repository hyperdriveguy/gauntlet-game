#ifndef __CONSTANTS_HEADER_INCLUDED__ // Start guard
#define __CONSTANTS_HEADER_INCLUDED__

// Essential includes
#include <string>
#include <vector>
#include <unordered_map>

using std::string;

// Defines are for some game configuration
#define CHARACTER_POINTS 25


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
// An array is used for ease of displaying strings
extern const char* StatusEffectString[];


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
	BackInNam
};

const Attack ATTACK_LIST[] = {
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

extern const char* ENEMY_NAMES[];


// TODO: This uses a relatively high amount of RAM, make this more compact
const std::unordered_map<string, int> ENEMY_BASE_STATS[] = {
	{{"health", 2}, {"strength", 2}, {"skill", 6}, {"stamina", 10}, {"speed", 10}}, // Spicy Dorito
	{{"health", 10}, {"strength", 2}, {"skill", 6}, {"stamina", 2}, {"speed", 10}}, // Skelly Boi
	{{"health", 6}, {"strength", 6}, {"skill", 10}, {"stamina", 6}, {"speed", 2}}   // Baby Boomer
};

const std::vector<Attacks> ENEMY_ATTACKS[NUM_ENEMIES] = {
	{Attacks::SpicyCheese, Attacks::GetNeighNeighed},
	{Attacks::Slap, Attacks::RibPoke},
	{Attacks::Slap, Attacks::BackInNam}
};

#endif // End guard
