#include "PhoneBook.hpp"

int main() {
    while (1) {
        std::cout << "Type a command: ADD, SEARCH or EXIT" << std::endl;
        std::string command;
        std::getline(std::cin, command);
        if (command == "EXIT")
            break;
        std::cout << "You entered: " << command << std::endl;
    }
    return 0;
}
