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
    std::string get_firstname() const;
    std::string get_lastname() const;
    std::string get_nickname() const;
    std::string get_phone_nb() const;
    std::string get_darkest_secret() const;
    bool operator==(const Contact& other) const;
    bool operator!=(const Contact& other) const;

   private:
    const std::string firstname;
    const std::string lastname;
    const std::string nickname;
    const std::string phone_nb;
    const std::string darkest_secret;
};

#endif
