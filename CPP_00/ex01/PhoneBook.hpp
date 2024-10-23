#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <cstring>
#include <iostream>
#include "Contact.hpp"

class PhoneBook {
   public:
    PhoneBook();
    void add_contact(const Contact contact);
    void print_contact(const Contact contact);

   private:
    const Contact contacts[8];
    int get_contact_index(const Contact contact);
    int get_nb_contact_stored();
};

#endif
