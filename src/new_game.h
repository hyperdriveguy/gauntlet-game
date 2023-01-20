#ifndef __NEW_GAME_HEADER_INCLUDED__ // Start guard
#define __NEW_GAME_HEADER_INCLUDED__

// Essential imports
#include <iomanip>
#include <unordered_map>
#include "prompts.h"
#include "player.h"

// String is part of the namespace
using std::string;

void print_base_stats_table(std::unordered_map<string, int>& base_stats);

std::unordered_map<string, int> distribute_stats();

Player* new_game();

#endif // End guard
