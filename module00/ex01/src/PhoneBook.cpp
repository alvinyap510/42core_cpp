#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->lastSaveIndex = -1;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::saveContact(std::string _firstName, std::string _lastName,
                            std::string _nickName, std::string _phoneNumber,
                            std::string _darkestSecret)
{
    // Keep track of the most previous recod
    if (this->lastSaveIndex == 7)
        this->lastSaveIndex = -1;
    lastSaveIndex += 1;
    this->contactMemory[lastSaveIndex].setContact(_firstName, _lastName, _nickName,
                                                  _phoneNumber, _darkestSecret);
}

void PhoneBook::displayAllTruncated() const
{
    for (int i = 0; i < 8; i++)
    {
        if (!contactMemory[i].getFirstName().empty())
        {
            std::string firstName = contactMemory[i].getFirstName();
            if (firstName.length() >= 10)
            {
                firstName.resize(9);
                firstName += ".";
            }
            std::string lastName = contactMemory[i].getLastName();
            if (lastName.length() >= 10)
            {
                lastName.resize(9);
                lastName += ".";
            }
            std::string nickName = contactMemory[i].getNickName();
            if (nickName.length() >= 10)
            {
                nickName.resize(9);
                nickName += ".";
            }
            std::cout << "|" << std::setw(10) << i
                      << "|" << std::setw(10) << firstName
                      << "|" << std::setw(10) << lastName
                      << "|" << std::setw(10) << nickName
                      << "|" << std::endl;
        }
    }
}

Contact const &PhoneBook::getContactByIndex(int index)
{
    if (index < 0 || index > 7)
        throw "Invalid contact index";
    return this->contactMemory[index];
}

std::string PhoneBook::getFirstName(int index)
{
    if (index < 0 || index > 7)
        throw "Invalid contact index";
    return this->contactMemory[index].getFirstName();
}

std::string PhoneBook::getLastName(int index)
{
    if (index < 0 || index > 7)
        throw "Invalid contact index";
    return this->contactMemory[index].getLastName();
}

std::string PhoneBook::getNickName(int index)
{
    if (index < 0 || index > 7)
        throw "Invalid contact index";
    return contactMemory[index].getNickName();
}

std::string PhoneBook::getPhoneNumber(int index)
{
    if (index < 0 || index > 7)
        throw "Invalid contact index";
    return contactMemory[index].getPhoneNumber();
}

std::string PhoneBook::getDarkestSecret(int index)
{
    if (index < 0 || index > 7)
        throw "Invalid contact index";
    return contactMemory[index].getDarkestSecret();
}
