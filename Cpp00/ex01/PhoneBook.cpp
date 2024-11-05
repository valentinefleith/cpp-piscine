#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    len = 0;
}

Command PhoneBook::prompt_user() {
    std::cout << "\033[1;34mType a command: ADD, SEARCH or EXIT\033[0m"
              << std::endl;
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
        std::cout << "\033[1;31mContact can't have empty fields.\033[0m"
                  << std::endl;
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
        std::cout
            << "\033[1;31mPhoneBook is empty yet. You need to fill it!\033[0m"
            << std::endl;
        return;
    }
    std::cout << "List of available contacts:" << std::endl;
    this->display_saved_contacts();
    std::string index_str;
    std::cout << "Type the index of the contact you want to display:"
              << std::endl;
    getline(std::cin, index_str);
    if (!is_only_digits(index_str)) {
        std::cout << "\033[1;31mIncorrect index format.\033[0m" << std::endl;
        return;
    }
    int index = std::atoi(index_str.c_str());
    if (index >= len) {
        std::cout << "\033[1;31mIndex out of range.\033[0m" << std::endl;
        return;
    }
    contacts[index].display();
}

void PhoneBook::display_saved_contacts() const {
    std::cout << "\033[0;32m";
    int nb_lines = (len >= CONTACT_NB) ? CONTACT_NB : len;
    for (int i = 0; i < nb_lines; i++) {
        std::cout << i << "|";
        contacts[i].display_truncated();
        std::cout << std::endl;
    }
    std::cout << "\033[0m";
}
