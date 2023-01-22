#include "player.h"
#include "constants.h"

float Player::getStat(string stat) {
	return base_stats[stat];
}

void Player::addAttack(const Attacks new_atk) {
	attacks.push_back(new_atk);
}

string Player::getAvailableAttacks() {
	string avail_attacks = "";
	for (auto atk : attacks) {
		avail_attacks += ATTACK_LIST[int(atk)].name + ' ';
	}
	return avail_attacks;
}

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


std::unordered_map<string, int> distribute_stats(const std::unordered_map<string, int> &init_stats) {
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
		base_stats = init_stats;
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

Player* new_game() {
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
	Player* player = new Player(&player_name, 1, &player_stats);
	player->addAttack(Attacks::Slap);
	return player;
}
