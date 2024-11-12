#include <string>
#include <iostream>

std::string decimalToBinary(int decimal)
{
    std::string binaryString;

    while (decimal > 0)
    {
        binaryString.push_back((char) decimal % 2);
        decimal /= 2;
    }

    return binaryString;
}

int IPToBinary(std::string ipAddress)
{
    size_t ptr = 0;
    for(size_t i = 0; i < ipAddress.length(); i++)
    {
        if (ipAddress[i] == '.' || i == ipAddress.length() - 1)
        {
            std::cout << ipAddress.substr(ptr, i - ptr) << std::endl;

            int octet = std::stoi(ipAddress.substr(ptr, i));

            // std::cout << octet << std::endl;

            ptr = i + 1;
        }
    }

    return 0;
}

int main()
{
    std::string testAddress = "192.168.1.1";

    std::cout << decima

    IPToBinary(testAddress);

    // std::cout << IPToBinary(testAddress) << std::endl;
}  