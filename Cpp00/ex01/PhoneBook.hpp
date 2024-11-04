#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <cstring>
#include <iostream>
#include <string>
#include "Contact.hpp"

#define CONTACT_NB 8

enum Command {
    ADD,
    SEARCH,
    EXIT,
    INVALID,
};

class PhoneBook {
   public:
    PhoneBook();
    static Command prompt_user();
    void process_command(Command command);

   private:
    Contact contacts[CONTACT_NB];
    int len;

    void add(const Contact& to_add);
    void search() const;
    int get_contact_index(const Contact contact);
    int get_nb_contact_stored();
    void display_saved_contacts() const;
};

#endif
