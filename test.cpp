#include <iostream>
#include <string>
#include <cctype>

std::string abbrevName(std::string);

int main()
{
    std::cout << abbrevName("penny lane") << std::endl;

    return 0;
}

// std::string abbrevName(std::string name)
// {
//     std::string abbr = std::string() + (char) toupper(name[0]);
//     abbr += ".";
//     abbr += std::string() + (char) toupper(name[name.find(" ") + 1]);

//     return abbr;
// }

std::string abbrevName(std::string name)
{
    std::string abbr{
        (char) toupper(name[0]),
        '.',
        (char) toupper(name[name.find(' ') + 1])
    };
    return abbr;
}