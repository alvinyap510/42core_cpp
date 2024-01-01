#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::setContact(std::string _firstName, std::string _lastName,
                         std::string _nickName, std::string _phoneNumber,
                         std::string _darkestSecret)
{
    this->firstName = _firstName;
    this->lastName = _lastName;
    this->nickName = _nickName;
    this->phoneNumber = _phoneNumber;
    this->darkestSecret = _darkestSecret;
}

void Contact::displayContactDetails() const
{
    std::cout << "First Name: " << this->firstName << std::endl;
    std::cout << "Last Name: " << this->lastName << std::endl;
    std::cout << "Nickname: " << this->nickName << std::endl;
    std::cout << "Phone Number: " << this->phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << this->darkestSecret << std::endl;
}

std::string Contact::getFirstName() const
{
    return this->firstName;
}

std::string Contact::getLastName() const
{
    return this->lastName;
}

std::string Contact::getNickName() const
{
    return this->nickName;
}

std::string Contact::getPhoneNumber() const
{
    return this->phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return this->darkestSecret;
}