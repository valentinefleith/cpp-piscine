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
    std::cout << "Please type a valid command" << std::endl;
}

void PhoneBook::add(const Contact& to_add) {
    if (!to_add.is_valid()) {
        std::cout << "Contact can't have empty fields." << std::endl;
        return;
    }
    contacts[len % CONTACT_NB] = to_add;
    len++;
}

static bool is_only_digits(std::string str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

void PhoneBook::search() const {
    if (len == 0) {
        std::cout << "PhoneBook is empty yet. You need to fill it!"
                  << std::endl;
        return;
    }
    this->display_saved_contacts();
    std::string index_str;
    std::cout << "Type the index of the contact you want to display:"
              << std::endl;
    getline(std::cin, index_str);
    if (!is_only_digits(index_str)) {
        std::cout << "Incorrect index format." << std::endl;
        return;
    }
    int index = std::atoi(index_str.c_str());
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
