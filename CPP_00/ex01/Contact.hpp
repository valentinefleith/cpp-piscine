#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>

class Contact {
   public:
   Contact(const std::string& firstname,
            const std::string& lastname,
            const std::string& nickname,
            const std::string& phone_nb,
            const std::string& darkest_secret);
    std::string get_firstname(void) const;
    std::string get_lastname(void) const;
    std::string get_nickname(void) const;
    std::string get_phone_nb(void) const;
    std::string get_darkest_secret(void) const;

   private:
    const std::string firstname;
    const std::string lastname;
    const std::string nickname;
    const std::string phone_nb;
    const std::string darkest_secret;
};

#endif
