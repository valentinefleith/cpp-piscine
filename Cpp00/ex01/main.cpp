#include "PhoneBook.hpp"

int main() {
    PhoneBook phonebook;
    while (1) {
        Command command = phonebook.prompt_user();
        if (command == EXIT) {
            break;
        }
        phonebook.process_command(command);
    }
    return 0;
}
