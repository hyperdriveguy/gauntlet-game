#ifndef __PROMPTS_HEADER_INCLUDED__ // Start guard
#define __PROMPTS_HEADER_INCLUDED__

// Essential includes
#include <string>
#include <iostream>
#include <algorithm>
#include <limits>

// String is part of the namespace
using std::string;

void clear_output();

void message_wait(const string message);

string prompt(const string prompt_text, const bool same_line = false, const bool case_sensitive = false);

int prompt_int(const string prompt_text, const bool same_line = true);

#endif // End guard
