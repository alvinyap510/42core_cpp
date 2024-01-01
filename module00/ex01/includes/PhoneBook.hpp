#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

class PhoneBook
{
private:
    Contact contactMemory[8];
    int lastSaveIndex;

public:
    PhoneBook();
    ~PhoneBook();
    void saveContact(std::string _firstName, std::string _lastName,
                     std::string _nickName, std::string _phoneNumber,
                     std::string _darkestSecret);
    void displayAllTruncated() const;
    Contact const &getContactByIndex(int index);
    std::string getFirstName(int index);
    std::string getLastName(int index);
    std::string getNickName(int index);
    std::string getPhoneNumber(int index);
    std::string getDarkestSecret(int index);
};

#endif