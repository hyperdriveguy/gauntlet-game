#ifndef __PROMPTS_HEADER_INCLUDED__ // Start guard
#define __PROMPTS_HEADER_INCLUDED__

// Essential includes
#include <string>
#include <iostream>
#include <algorithm>
#include <limits>

// String is part of the namespace
using std::string;

/**
 * This function clears the output console.
 */
void clear_output();

/**
 * This function prints a message to the console and waits for the user to press enter.
 * @param message - The message to display.
 */
void message_wait(const string &message);

/**
 * This function prompts the user for a string input.
 * @param prompt_text - The text to display as the prompt.
 * @param same_line - Whether to display the prompt and input on the same line or not.
 * @param case_sensitive - Whether to make the input case-sensitive or not.
 * @return The user's input.
 */
string prompt(const string &prompt_text, const bool same_line = false, const bool case_sensitive = false);

/**
 * This function prompts the user for an integer input.
 * @param prompt_text - The text to display as the prompt.
 * @param same_line - Whether to display the prompt and input on the same line or not.
 * @return The user's input as an integer.
 */
int prompt_int(const string &prompt_text, const bool same_line = true);

#endif // End guard
