/* The Gauntlet - A small battle gauntlet game to demonstrate C++ knowledge.
(c) 2023 Carson Bush - MIT License */

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

#include "player.h"
#include "new_game.h"

using std::string;

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
	Player* p = new_game();
	std::cout << "Chosen speed: " << p->base_stats["speed"] << std::endl;
	std::cout << "Your name: " << p->name << std::endl;
	Contestant new_e = *generate_enemy(rand() % 100);
	std::cout << "New enemy approaches: " << new_e.name << ", L:" << new_e.level << " HP:" << new_e.base_stats["health"] << std::endl;
	return 0;
}
