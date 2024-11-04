#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>

#define MAX_WIDTH 10

class Contact {
   public:
    Contact();
    static Contact from_user();
    bool is_valid() const;
    void display() const;
    void display_truncated() const;
    bool operator==(const Contact& other) const;
    bool operator!=(const Contact& other) const;

   private:
    Contact(const std::string& firstname,
            const std::string& lastname,
            const std::string& nickname,
            const std::string& phone_nb,
            const std::string& darkest_secret);
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string phone_nb;
    std::string darkest_secret;
};

#endif
