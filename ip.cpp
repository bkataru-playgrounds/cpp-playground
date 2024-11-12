#include <string>
#include <iostream>
#include <cmath>

std::string decimalToBinary(unsigned int decimal)
{
    if (decimal == 0) return "0";

    std::string binaryString;

    while (decimal > 0)
    {
        binaryString = std::to_string(decimal % 2) + binaryString;
        decimal /= 2;
    }

    return binaryString;
}

std::string padOctet(std::string octetString)
{
    while (octetString.length() < 8) octetString = "0" + octetString;

    return octetString;
}

unsigned int binaryToDecimal(std::string binary)
{
    unsigned int decimalVal = 0;

    for(size_t i = 0; i < binary.length(); i++)
    {
        decimalVal += (unsigned int) (pow(2, binary.length() - i - 1) * (binary[i] - '0'));    
    }

    return decimalVal;
}

std::string IPToBinary(std::string ipAddress)
{
    std::string binaryString;
    size_t ptr = 0;

    for(size_t i = 0; i <= ipAddress.length(); i++)
    {
        if (i == ipAddress.length() || ipAddress[i] == '.')
        {
            unsigned int octet = std::stoi(ipAddress.substr(ptr, i - ptr));

            binaryString += padOctet(decimalToBinary(octet));

            ptr = i + 1;
        }
    }

    return binaryString;
}

std::string binaryToIP(std::string binaryString)
{
    std::string ipAddress;

    for(int i = 0; i < 4; i++)
    {
        ipAddress += std::to_string(binaryToDecimal(binaryString.substr(i * 8, 8))) + (i < 3 ? "." : "");
    }

    return ipAddress;
}

int main()
{
    std::string testAddress = "192.168.1.1";

    std::cout << IPToBinary(testAddress) << ", length: " << IPToBinary(testAddress).length() << std::endl;

    std::cout << binaryToIP(IPToBinary(testAddress)) << std::endl;
}  