/* #include "../includes/Factory.class.hpp"
#include "../includes/Operand.hpp"

Operand::Operand()
{
}

Operand::Operand(eOperandType type, std::string value) : _type(type), _value(value)
{
}

Operand::Operand(Operand const &cpyOP)
{
    if (this != &cpyOP)
    {
        *this = cpyOP;
    }
}

Operand::~Operand()
{
}

Operand &Operand::operator=(Operand const &newOP)
{
    if (this != &newOP)
    {
        return (*new Operand(newOP));
    }
}

int Operand::getPrecision() const
{
    return (this->_type);
}

eOperandType Operand::getType() const
{
    return (this->_type);
}

std::string const &Operand::toString() const
{
    return (this->_value);
}

IOperand const *Operand::operator+(IOperand const &rhs) const
{
    eOperandType 	type;
			Operand			result;

			type = (this->_type > rhs.getPrecision() ? this->_type : rhs.getType());
			
			switch (type)
			{
				case INT8:
					result = this->_factoryObj.createOperand(type, std::to_string(std::atoi(_value.c_str()) + std::atoi(rhs.toString().c_str())));
					break;
				case INT16:
					result = this->_factoryObj.createOperand(type, std::to_string(std::atoi(this->_value.c_str()) + std::atoi(rhs.toString().c_str())));
					break;
				case INT32:
					result = this->_factoryObj.createOperand(type, std::to_string(std::atoi(this->_value.c_str()) + std::atoi(rhs.toString().c_str())));
					break;
				case FLOAT:
					result = this->_factoryObj.createOperand(type, std::to_string(std::atof(this->_value.c_str()) + std::atoi(rhs.toString().c_str())));
					break;
				case DOUBLE:
					result = this->_factoryObj.createOperand(type, std::to_string(std::stod(this->_value) + std::stod(rhs.toString())));
					break;
				default:
					throw InstructionUnknownException();
					break;
			}
			return (result);
} */