#ifndef __NEW_GAME_HEADER_INCLUDED__ // Start guard
#define __NEW_GAME_HEADER_INCLUDED__

// Essential imports
#include <iomanip>
#include <unordered_map>
#include "prompts.h"
#include "player.h"

// String is part of the namespace
using std::string;

/**
 * Prints out a table with base statistics of the player
 * @param base_stats A reference to an unordered map of base statistics with attributes as keys and levels as values
 */
void print_base_stats_table(std::unordered_map<string, int>& base_stats);

/**
 * Prompts the user to distribute points to base statistics of the player
 * @return A map of base statistics with attributes as keys and levels as values
 */
std::unordered_map<string, int> distribute_stats();

/**
 * Creates a new player object and prompts the user for information
 * @return A pointer to the new player object
 */
Player* new_game();

#endif // End guard
