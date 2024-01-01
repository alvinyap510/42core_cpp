#include <iostream>
#include <string>

std::string toUpper(std::string const &string)
{
    std::string upperStr = "";

    for (unsigned long i = 0; i < string.length(); i++)
    {
        upperStr += std::toupper(string[i]);
    }
    return upperStr;
}

int main(int argc, char **argv)
{
    // Guard Clause
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    // Concat strings
    std::string str = "";

    for (int i = 1; i < argc; i++)
        str = str + toUpper(argv[i]);

    std::cout << str << std::endl;
}