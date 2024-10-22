#include "PhoneBook.hpp"

Contact::Contact(const std::string& firstname,
            const std::string& lastname,
            const std::string& nickname,
            const std::string& phone_nb,
            const std::string& darkest_secret)
        : firstname(firstname),
          lastname(lastname),
          nickname(nickname),
          phone_nb(phone_nb),
          darkest_secret(darkest_secret){}

std::string Contact::get_firstname(void) const {
    return firstname;
}
