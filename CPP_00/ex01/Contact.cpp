#include "PhoneBook.hpp"

Contact::Contact()
    : firstname(""),
      lastname(""),
      nickname(""),
      phone_nb(""),
      darkest_secret("") {}

Contact::Contact(const std::string& firstname,
                 const std::string& lastname,
                 const std::string& nickname,
                 const std::string& phone_nb,
                 const std::string& darkest_secret)
    : firstname(firstname),
      lastname(lastname),
      nickname(nickname),
      phone_nb(phone_nb),
      darkest_secret(darkest_secret) {}

std::string Contact::get_firstname() const {
    return firstname;
}

std::string Contact::get_lastname() const {
    return lastname;
}

std::string Contact::get_nickname() const {
    return nickname;
}

std::string Contact::get_phone_nb() const {
    return phone_nb;
}

std::string Contact::get_darkest_secret() const {
    return darkest_secret;
}

bool Contact::operator==(const Contact& other) const {
    return (firstname == other.firstname) && (lastname == other.lastname) &&
           (nickname == other.nickname) && (phone_nb == other.phone_nb) &&
           (darkest_secret == other.darkest_secret);
}

bool Contact::operator!=(const Contact& other) const {
    return !(*this == other);
}
