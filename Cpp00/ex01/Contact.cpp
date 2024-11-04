#include "Contact.hpp"
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

Contact Contact::from_user() {
    std::cout << "firstname: " << std::endl;
    std::string firstname;
    std::getline(std::cin, firstname);
    std::cout << "lastname: " << std::endl;
    std::string lastname;
    std::getline(std::cin, lastname);
    std::cout << "nickname: " << std::endl;
    std::string nickname;
    std::getline(std::cin, nickname);
    std::cout << "phone nb: " << std::endl;
    std::string phone_nb;
    std::getline(std::cin, phone_nb);
    std::cout << "darkest secret: " << std::endl;
    std::string darkest_secret;
    std::getline(std::cin, darkest_secret);
    return Contact(firstname, lastname, nickname, phone_nb, darkest_secret);
}

bool Contact::is_valid() const {
    return !(firstname.empty() || lastname.empty() || nickname.empty() ||
             phone_nb.empty() || darkest_secret.empty());
}

void Contact::display() const {
    std::cout << "firstname: " << firstname << std::endl;
    std::cout << "lastname: " << lastname << std::endl;
    std::cout << "nickname: " << nickname << std::endl;
    std::cout << "phone nb: " << phone_nb << std::endl;
    std::cout << "darkest secret: " << darkest_secret << std::endl;
}

static std::string truncate(std::string to_truncate, size_t width) {
    if (to_truncate.length() <= width)
        return to_truncate;
    return to_truncate.substr(0, width - 1) + ".";
}

void Contact::display_truncated() const {
    std::cout << truncate(firstname, MAX_WIDTH) << "|";
    std::cout << truncate(lastname, MAX_WIDTH) << "|";
    std::cout << truncate(nickname, MAX_WIDTH);
}

bool Contact::operator==(const Contact& other) const {
    return (firstname == other.firstname) && (lastname == other.lastname) &&
           (nickname == other.nickname) && (phone_nb == other.phone_nb) &&
           (darkest_secret == other.darkest_secret);
}

bool Contact::operator!=(const Contact& other) const {
    return !(*this == other);
}
