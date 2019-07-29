#ifndef __FACTORY__
#define __FACTORY__
#include <vector>

#include "Operand.template.hpp"

class Factory;
typedef IOperand const *(Factory::*function_selector_t)(std::string const &) const;

class Factory
{
    private:
        // std::vector<function_selector_t>  _operandsVector;
        IOperand const *createInt8(std::string const &value) const;
        IOperand const *createInt16(std::string const &value) const;
        IOperand const *createInt32(std::string const &value) const;
        IOperand const *createFloat(std::string const &value) const;
        IOperand const *createDouble(std::string const &value) const;
        IOperand const *callOperand(eOperandType type, std::string val) const;
        bool hasNoneZero(std::string const value) const;

    public:
        Factory();
        Factory(const Factory &);
        ~Factory();
        Factory &operator=(Factory const &);

        static function_selector_t _operandsVector[];
        IOperand const *createOperand(eOperandType type, std::string const &value) const;
};

#endif