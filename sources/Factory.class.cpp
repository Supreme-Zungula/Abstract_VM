#include <string>
#include "../includes/Exceptions.class.hpp"
#include "../includes/Factory.class.hpp"

function_selector_t Factory::_operandsVector[] = {
    &Factory::createInt8,
    &Factory::createInt16,
    &Factory::createInt32,
    &Factory::createFloat,
    &Factory::createDouble};

Factory::Factory()
{
}

Factory::Factory(Factory const &cpyFactory)
{
    if (this != &cpyFactory)
    {
        *this = cpyFactory;
    }
}

Factory &Factory::operator=(Factory const &inFactory)
{
    if (this != &inFactory)
    {
        Factory newFactory(inFactory);
        return (newFactory);
    }
    else
    {
        return (*this);
    }
}

Factory::~Factory()
{
}

IOperand const *Factory::callOperand(eOperandType type, std::string val) const
{
    function_selector_t fun = _operandsVector[type];
    return ((*this).*(fun))(val);
}

IOperand const *Factory::createOperand(eOperandType type, std::string const &value) const
{
    switch (type)
    {
    case INT8:
        return (callOperand(type, value));
        break;
    case INT16:
        return (callOperand(type, value));
        break;
    case INT32:
        return (callOperand(type, value));
        break;
    case FLOAT:
        return (callOperand(type, value));
        break;
    case DOUBLE:
        return (callOperand(type, value));
        break;
    default:
        throw InstructionUnknownException();
        break;
    }
}

IOperand const *Factory::createInt8(std::string const &value) const
{
    return (new Operand<int8_t>(INT8, value));
}

IOperand const *Factory::createInt16(std::string const &value) const
{
    return ( new Operand<int16_t>(INT16, value) );
}

IOperand const *Factory::createInt32(std::string const &value) const
{
    return ( new Operand<int32_t>(INT32, value) );
}

IOperand const *Factory::createFloat(std::string const &value) const
{
    return ( new Operand<float>(FLOAT, value) );
}

IOperand const *Factory::createDouble(std::string const &value) const
{
    return ( new Operand<double>(DOUBLE, value) );
}
