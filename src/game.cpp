/* The Gauntlet - A small battle gauntlet game to demonstrate C++ knowledge.
(c) 2023 Carson Bush - MIT License */

#include <iostream>
#include <string>

#include "chance.h"
#include "constants.h"
#include "player.h"
#include "prompts.h"

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
	clear_output();
	string approaches = "A new challenger approaches: " + enemy->name + ", level " + std::to_string(enemy->level);
	message_wait(approaches);
	bool player_turn;
	if (player->getStat("speed") > enemy->getStat("speed")) {
		player_turn = true;
	} else if (player->getStat("speed") < enemy->getStat("speed")) {
		player_turn = false;
	} else {
		player_turn = chan->coinFlip();
	}
	while (true) {
		if (player_turn) {
			uint player_action = 0;
			do {
				clear_output();
				print_battle_screen(player, enemy);
				player_action = prompt_int("Enter number for action:");
				if (player_action > player->getNumberAttacks()) {
					message_wait("Not a valid action number!");
				}
			} while (player_action > player->getNumberAttacks());
			int player_damage = player->getAttackDamage(player_action - 1);
			enemy->applyAttackDamage(player_damage);
			string player_damage_msg = player->name + " attacked with " + std::to_string(player_damage) + " power!";
			clear_output();
			message_wait(player_damage_msg);
		} else {
			int enemy_damage = enemy->getAttackDamage(chan->range(0, enemy->getNumberAttacks() - 1));
			player->applyAttackDamage(enemy_damage);
			string enemy_damage_msg = enemy->name + " attacked with " + std::to_string(enemy_damage) + " power!";
			clear_output();
			message_wait(enemy_damage_msg);
		}
		if (player->getCurrentHealth() <= 0)
			return false;
		else if (enemy->getCurrentHealth() <= 0)
			return true;
		player_turn = !player_turn;
	}
	return true;
}

int main() {
	Chance chance;
	// Initialize player via new game sequence
	Player* p = new_game();
	while (true) {
		Contestant* new_e = generate_enemy(chance.range(1, p->level + 3), chance.enemyIndex());
		bool won_battle = battle(p, new_e, &chance);
		clear_output();
		if (won_battle) {
			message_wait("You won the battle!");
		} else {
			message_wait("You lost the battle.");
			break;
		}
	}
	return 0;
}
