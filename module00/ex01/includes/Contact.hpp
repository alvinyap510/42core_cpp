#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact();
    ~Contact();
    void setContact(std::string _firstName, std::string _lastName,
                    std::string _nickName, std::string _phoneNumber,
                    std::string _darkestSecret);
    void displayContactDetails() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickName() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
};
#endif