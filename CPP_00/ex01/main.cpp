#include <iostream>

int main() {
	std::cout << "Type a command: ADD, SEARCH or EXIT" << std::endl;
	std::string command;
	std::getline(std::cin, command);
	std::cout << "You entered: " << command << std::endl;
	return 0;
}
