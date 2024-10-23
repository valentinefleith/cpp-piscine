#include "PhoneBook.hpp"

//PhoneBook::PhoneBook() {
//     for (int i = 0; i < CONTACT_NB; i++) {
//        contacts[i] = create_null_contact();
//    }
//}

int PhoneBook::get_contact_index(const Contact contact) {
    for (int i = 0; i < 8; i++) {
        if (contact == contacts[i])
            return i;
    }
    return -1;
}

void PhoneBook::add_contact(const Contact contact) {}

const Contact PhoneBook::create_null_contact() {
    const Contact null_contact = Contact("", "", "", "", "");
    return null_contact;
}
