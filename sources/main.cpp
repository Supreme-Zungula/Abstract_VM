#include <string>
#include <fstream>
#include <iostream>

#include "../includes/Factory.class.hpp"
#include "../includes/Parser.class.hpp"

int main(int argc, char const *argv[])
{

    Operand<int16_t> opInt16(INT16, "16");
    Operand<float> opFloat(FLOAT, "15.45");
    Parser parserObj;

    if (argc == 2)
    {
        parserObj.readFile(std::string(argv[1]));
    }
    std::cout << "-----INT16-----\n";
    std::cout << "Type: " << opInt16.getType() << '\n';
    std::cout << "Precision: " << opInt16.getPrecision() << '\n';
    std::cout << "Value: " << opInt16.toString() << '\n';

    std::cout << "----FLOAT-----\n";
    std::cout << "Type: " << opFloat.getType() << '\n';
    std::cout << "Precision: " << opFloat.getPrecision() << '\n';
    std::cout << "Value: " << opFloat.toString() << '\n';

    return 0;
}
