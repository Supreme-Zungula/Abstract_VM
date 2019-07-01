#ifndef __IOPERAND__
#define __IOPERAND__
#include <string>

#include "AVM.enums.hpp"
#include "Exceptions.class.hpp"
#include "../includes/Exceptions.class.hpp"

class IOperand
{
    public:
        virtual int getPrecision(void) const = 0;                         // Precision of the type of the instance
        virtual eOperandType getType(void) const = 0;
        virtual IOperand const *operator+(IOperand const &rhs) const = 0; // Sum
        virtual IOperand const *operator-(IOperand const &rhs) const = 0; // Difference
        virtual IOperand const *operator*(IOperand const &rhs) const = 0; // Product
        virtual IOperand const *operator/(IOperand const &rhs) const = 0; // Quotient
        virtual IOperand const *operator%(IOperand const &rhs) const = 0; // Modulo
        virtual std::string const &toString(void) const = 0;              // String representation of the instance
        virtual ~IOperand(void) {}
};
#endif