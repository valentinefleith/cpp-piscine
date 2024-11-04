#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    len = 0;
}

Command PhoneBook::prompt_user() {
    std::cout << "Type a command: ADD, SEARCH or EXIT" << std::endl;
    std::string command;
    std::getline(std::cin, command);
    if (command == "ADD")
        return ADD;
    if (command == "SEARCH")
        return SEARCH;
    if (command == "EXIT")
        return EXIT;
    return INVALID;
}

void PhoneBook::process_command(Command command) {
    if (command == ADD)
        return this->add(Contact::from_user());
    if (command == SEARCH)
        return this->search();
    else {
        std::cout << "Please type a valid command" << std::endl;
    }
}

void PhoneBook::add(const Contact& to_add) {
    contacts[len % CONTACT_NB] = to_add;
    len++;
}

void PhoneBook::search() const {
    if (len == 0) {
        std::cout << "PhoneBook is empty yet. You need to fill it!" << std::endl;
        return;
    }
    this->display_saved_contacts();
    int index;
    std::cout << "Type the index of the contact you want to display:"
              << std::endl;
    std::cin >> index;
    if (index >= len) {
        std::cout << "Index out of range." << std::endl;
        return;
    }
    contacts[index].display();
}

void PhoneBook::display_saved_contacts() const {
    for (int i = 0; i < len % CONTACT_NB; i++) {
        std::cout << i << "|";
        contacts[i].display_truncated();
        std::cout << std::endl;
    }
}
