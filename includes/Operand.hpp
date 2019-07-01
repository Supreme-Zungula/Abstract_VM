/* #ifndef __OPERAND__
#define __OPERAND__

#include "IOperand.interface.hpp"
#include "Factory.class.hpp"

class Operand : public IOperand
{
    private:
        Factory             _factoryObj;
        eOperandType        _type;
        std::string         _value;

        Operand(){};

    public:
        Operand(eOperandType type, std::string value);
        Operand(Operand const &cpyOP);
        Operand& operator=(Operand const &newOP);
        ~Operand(){};

        int getPrecision(void) const ; // Precision of the type of the instance
        eOperandType getType(void) const ; // Type of the value i.e int8, int16, int32, float and double
		std::string const &toString(void) const; // return a string represention of the value
      
        IOperand const *operator+(IOperand const &rhs) const;
        IOperand const *operator-(IOperand const &rhs) const;
        IOperand const *operator*(IOperand const &rhs) const;
        IOperand const *operator/(IOperand const &rhs) const;
        IOperand const *operator%(IOperand const &rhs) const;
};

#endif 
*/