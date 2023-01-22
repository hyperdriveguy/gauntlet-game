/* The Gauntlet - A small battle gauntlet game to demonstrate C++ knowledge.
(c) 2023 Carson Bush - MIT License */

#include <iostream>
#include <string>

#include "chance.h"
#include "constants.h"
#include "player.h"

using std::string;

Contestant* generate_enemy(int level, int enemy_index) {
	const string enemy_name = ENEMY_NAMES[enemy_index];
	std::unordered_map<string, int> enemy_bst = ENEMY_BASE_STATS[enemy_index];
	const std::vector<Attacks>* enemy_atks = &ENEMY_ATTACKS[enemy_index];
	Contestant* enemy = new Contestant(&enemy_name, level, &enemy_bst, enemy_atks);
	return enemy;
}

void print_battle_screen(Player* player, Contestant* enemy) {
	// Enemy statistics
	std::cout << enemy->name << " L:" << enemy->level << std::endl;
	std::cout << "HP: " << enemy->getCurrentHealth() << std:: endl;
	if (enemy->isNormalStatus())
		std::cout << enemy->getStatusEffect() << std::endl;
	std::cout << std::endl;
	// Player statistics
	std::cout << player->name << " L:" << player->level << std::endl;
	std::cout << "HP: " << player->getCurrentHealth() << std::endl;
	if (player->isNormalStatus())
		std::cout << player->getStatusEffect() << std::endl;
	std::cout << std::endl;
	// Player moves
	std::cout << "Available actions:" << std::endl;
	std::cout << player->getAvailableAttacks() << std::endl;
}



bool battle(Player* player, Contestant* enemy, Chance* chan) {
	bool player_turn;
	if (player->getStat("speed") > enemy->getStat("speed")) {
		player_turn = true;
	} else if (player->getStat("speed") < enemy->getStat("speed")) {
		player_turn = false;
	} else {
		player_turn = chan->coinFlip();
	}
	while (true) {
		clear_output();
		print_battle_screen(player, enemy);
		if (player_turn) {

		}
	}
	return true;
}

int main() {
	Chance chance;
	// Initialize player via new game sequence
	Player* p = new_game();
	std::cout << "Chosen speed: " << p->getStat("speed") << std::endl;
	std::cout << "Your name: " << p->name << std::endl;
	Contestant* new_e = generate_enemy(chance.range(0, 100), chance.enemyIndex());
	battle(p, new_e, &chance);
	return 0;
}
