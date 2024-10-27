#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <cstring>
#include <string>
#include <iostream>
#include "Contact.hpp"

#define CONTACT_NB 8

class PhoneBook {
   public:
    PhoneBook();
    void add_contact(const Contact contact);
    void print_contact(const Contact contact);

   private:
    const Contact contacts[CONTACT_NB];
    int get_contact_index(const Contact contact);
    int get_nb_contact_stored();
    const Contact create_null_contact();
};

#endif
