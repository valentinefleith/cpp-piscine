#include "PhoneBook.hpp"

int PhoneBook::get_contact_index(const Contact contact) {
    for (int i = 0; i < 8; i++) {
        if (contact == contacts[i])
            return i;
    }
    return -1;
}

void PhoneBook::add_contact(const Contact contact) {}
