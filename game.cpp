/* The Gauntlet - A small battle gauntlet game to demonstrate C++ knowledge.
(c) 2023 Carson Bush - MIT License */

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <limits>

// Defines are for some game configuration
#define CHARACTER_POINTS 20

using std::string;

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

// TODO: use an array or map instead due to all being the same type
struct BaseStats {
	int health;
	int strength;
	int skill;
	int stamina;
	int speed;
};

class Contestant {
	public:
		string name;
		int level;
		std::unordered_map<string, int> base_stats;
		StatusEffect status;
		Contestant() : name("Contestant"), level(1), status(StatusEffect::Normal) {
			base_stats = {{"health", 1}, {"strength", 1}, {"skill", 1}, {"stamina", 1}, {"speed", 1}};
		}
		Contestant(string* nam, int lev, std::unordered_map<string, int>* b_stats) :
			name(*nam), level(lev), base_stats(*b_stats),
			status(StatusEffect::Normal) {}
	// TODO: Methods
};

class Player : public Contestant {
	public:
		std::unordered_map<string, int> inventory;
		Player(string *nam, int lev, std::unordered_map<string, int>* b_stats) :
			Contestant(nam, lev, b_stats) {}
};

void clear_output() {
	std::cout << "\033c";
}

void message_wait(const string message) {
    std::cout << message << std::endl;
    std::cout << "Press any key to continue...";
	std::cin.get();
    std::cin.ignore();
}

string prompt(const string prompt_text, const bool same_line = false, const bool case_sensitive = false) {
	string answer;
	std::cout << prompt_text;
	if (!same_line)
		std::cout << std::endl;
	else
		std::cout << ' ';
	std::cin >> answer;
	if (!case_sensitive)
		transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
	return answer;
}

int prompt_int(const string prompt_text, const bool same_line = true) {
	int answer;

	while (true) {
		std::cout << prompt_text;
		if (!same_line)
			std::cout << std::endl;
		else
			std::cout << ' ';

		if (std::cin >> answer) {
			return answer;
		} else {
			// This clears errors in the input stream and ignores all characters previously entered
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid value entered. Try again." << std::endl;
		}
	}
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
	clear_output();
	string player_name = prompt("What is your name?", true);
	std::unordered_map<string, int> player_stats = distribute_stats();
	Player player(&player_name, 1, &player_stats);
	return player;
}

int main() {
	new_game();
	return 0;
}
