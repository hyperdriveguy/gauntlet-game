#include "include/prompts.h"

void clear_output() {
	std::cout << "\033c";
}

void message_wait(const string message) {
	std::cout << message << std::endl;
	std::cout << "Press Enter to continue...";
	std::cin.get();
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

string prompt(const string prompt_text, const bool same_line, const bool case_sensitive) {
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

int prompt_int(const string prompt_text, const bool same_line) {
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

