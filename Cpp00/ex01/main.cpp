#include "PhoneBook.hpp"

int main() {
    PhoneBook phonebook;
    std::cout << "Welcome to your PhoneBook!" << std::endl;
    while (1) {
        Command command = phonebook.prompt_user();
        if (command == EXIT || std::cin.eof()) {
            break;
        }
        phonebook.process_command(command);
    }
    return 0;
}
