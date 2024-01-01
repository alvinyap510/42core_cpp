#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

int main()
{

    std::string command;
    PhoneBook *phoneBook = new PhoneBook();

    // Loop
    while (true)
    {
        std::cout << "Please enter a command - < ADD / SEARCH / EXIT > : ";
        std::getline(std::cin, command);

        if (command == "ADD")
        {
            std::string firstName;
            std::string lastName;
            std::string nickName;
            std::string phoneNumber;
            std::string darkestSecret;

            std::cout << "Please enter first name: ";
            std::getline(std::cin, firstName);
            while (firstName.empty())
            {
                std::cout << "Invalid input. Please enter first name: ";
                std::getline(std::cin, firstName);
            }

            std::cout << "Please enter last name: ";
            std::getline(std::cin, lastName);
            while (lastName.empty())
            {
                std::cout << "Invalid input. Please enter last name: ";
                std::getline(std::cin, lastName);
            }

            std::cout << "Please enter nickname: ";
            std::getline(std::cin, nickName);
            while (nickName.empty())
            {
                std::cout << "Invalid input. Please enter nickname: ";
                std::getline(std::cin, nickName);
            }

            std::cout << "Please enter phone number: ";
            std::getline(std::cin, phoneNumber);
            while (phoneNumber.empty())
            {
                std::cout << "Invalid input. Please enter phone number: ";
                std::getline(std::cin, phoneNumber);
            }

            std::cout << "Please enter darkest secret: ";
            std::getline(std::cin, darkestSecret);
            while (darkestSecret.empty())
            {
                std::cout << "Invalid input. Please enter darkest secret: ";
                std::getline(std::cin, darkestSecret);
            }

            phoneBook->saveContact(firstName, lastName, nickName, phoneNumber, darkestSecret);

            std::cout << "Successfully saved contact" << std::endl;
        }
        else if (command == "SEARCH")
        {
            // Display Headers
            std::cout << std::setw(46) << std::setfill('*') << "\n"
                      << std::setfill(' ');
            std::cout << "|" << std::setw(10) << std::right << "Index"
                      << "|" << std::setw(10) << std::right << "First Name"
                      << "|" << std::setw(10) << std::right << "Last Name"
                      << "|" << std::setw(10) << std::right << "Nickname"
                      << "|" << std::endl;

            // Display truncated all contacts
            phoneBook->displayAllTruncated();
            std::cout << std::setw(46) << std::setfill('*') << "\n"
                      << std::setfill(' ');

            // Get index to display
            std::string indexStr;
            std::cout << "Enter the contact index to display : ";
            std::getline(std::cin, indexStr);
            int index = std::stoi(indexStr);
            while (index < 0 || index > 7)
            {
                std::cout << "Invalid index. Please re-enter index : ";
                std::getline(std::cin, indexStr);
                index = std::stoi(indexStr);
            }
            std::cout << std::endl;
            Contact contact = phoneBook->getContactByIndex(index);
            if (contact.getFirstName().empty())
                std::cout << "THE CONTACT INDEX IS EMPTY" << std::endl;
            else
                contact.displayContactDetails();
            std::cout
                << std::endl;
        }
        else if (command == "EXIT")
        {
            std::cout << "Exiting PhoneBook..." << std::endl;
            break;
        }
        else
            std::cout << "ERROR: Invalid command" << std::endl;
    }

    delete phoneBook;
    return 0;
}