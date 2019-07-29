#include <string>
#include <fstream>
#include <iostream>

#include "../includes/Factory.class.hpp"
#include "../includes/Parser.class.hpp"
#include "../includes/AbstractVM.class.hpp"

int main(int argc, char const *argv[])
{

    // Operand<int16_t> opInt16(INT16, "16");
    // Operand<float> *opFloat = new Operand<float>(FLOAT, "15.56");
    // Operand<double> opDouble(DOUBLE, "20");

    Parser          parserObj;
    AbstractVM      avm;
    Factory         factory;
    
    /* 
    avm.push(factory.createOperand(INT8, "12"));
    avm.push(factory.createOperand(INT16, "123"));
    avm.push(factory.createOperand(INT32, "1234"));
    avm.push(factory.createOperand(FLOAT, "12.0"));
    avm.push(factory.createOperand(DOUBLE, "123.0"));
    avm.push(factory.createOperand(DOUBLE, "123.0"));
    avm.dump();
    */

    
/* 
    std::cout << "\nPOP\n";
    avm.pop();
    avm.dump();
    
    std::cout << "\nADD\n";
    avm.add();
    avm.dump();

    std::cout << "\nSUB\n";
    avm.sub();
    avm.dump();

    std::cout << "\nDIV\n";
    avm.div();
    avm.dump();

    std::cout << "\nMUL\n";
    avm.mul();
    avm.dump();

    try
    {
        avm.push(factory.createOperand(INT8, "120"));
        std::cout << "\nMOD\n";
        avm.mod();
        avm.dump();

        avm.push(factory.createOperand(INT8, "65"));
        std::cout << "\nPRINT\n";
        avm.dump();   
        avm.print();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
     */
    
    if (argc == 2)
    {
        try
        {
            avm.readFromFile(std::string(argv[1]));
            avm.runCommands();
        }
        catch(const AVM_Exceptions::SyntaxErrorException &ex)
        {
            std::cerr << ex.what() << '\n';
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }   
    }
    else
    {
        try
        {
            avm.readFromTerminal();
            avm.runCommands();
        }
        catch(const AVM_Exceptions::SyntaxErrorException &ex)
        {
            std::cerr << ex.what() << '\n';
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }   
    }
    
    
  /*   
    std::cout << "-----INT16-----\n";
    std::cout << "Type: " << opInt16.getType() << '\n';
    std::cout << "Precision: " << opInt16.getPrecision() << '\n';
    std::cout << "Value: " << opInt16.toString() << '\n';

    std::cout << "----FLOAT-----\n";
    std::cout << "Type: " << opFloat->getType() << '\n';
    std::cout << "Precision: " << opFloat->getPrecision() << '\n';
    std::cout << "Value: " << opFloat->toString() << '\n';

    std::cout << "----DOUBLE-----\n";
    std::cout << "Type: " << opDouble.getType() << '\n';
    std::cout << "Precision: " << opDouble.getPrecision() << '\n';
    std::cout << "Value: " << opDouble.toString() << '\n'; 

    Operand<double>     prod(*(opDouble - opDouble));
    std::cout << "Sum = " << (*opFloat + *opFloat)->toString() << '\n';
    std::cout << "prod = " << prod << '\n'; 
    */
    return 0;
}
