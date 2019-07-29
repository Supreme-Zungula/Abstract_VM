#ifndef __OPERAND_TP__
#define __OPERAND_TP__

// #include "Factory.class.hpp"
#include "IOperand.interface.hpp"
// #include "Exceptions.class.hpp"

template <typename T>
class Operand : public IOperand
{
    private:
        eOperandType        _type;
        std::string         _value;

        Operand<T>(/* args */){};

    public:
        Operand<T>(eOperandType type, std::string value): _type(type), _value (value)
		{
			if (this->_value.compare(value) != 0) throw AVM_Exceptions::OverflowException();
		}
        Operand<T>(IOperand const &cpyOP)
		{ 
			if (this != &cpyOP ) 
			{ *this = cpyOP; } 
		}

        IOperand& operator=(IOperand const &newOP)
        {
            if (this != &newOP)
            {
                this->_type = newOP.getType();
                this->_value = newOP.toString();
            }
            return (*this);
        }
        ~Operand<T>(){};

        int getPrecision(void) const { return (this->_type); }; // Precision of the type of the instance
        eOperandType getType(void) const { return (this->_type); }; // Type of the value i.e int8, int16, int32, float and double
		std::string const &toString(void) const { return (this->_value); }; // return a string represention of the value
        
        /*-------------------- Sum -------------------------*/
        virtual IOperand const *operator+(IOperand const &rhs) const
        {
			eOperandType 	type;
			std::string 	result;

			type = (this->_type > rhs.getPrecision() ? this->_type : rhs.getType());
			
			switch (type)
			{
				case eOperandType::INT8:
				case eOperandType::INT16:
				case eOperandType::INT32:
					result = std::to_string(std::atoi(_value.c_str()) + std::stoi(rhs.toString()));
					break;
				case eOperandType::FLOAT:
					result = std::to_string(std::atof(_value.c_str()) + std::stof(rhs.toString()));
					break;
				case eOperandType::DOUBLE:
					result = std::to_string(std::stod(_value) + std::stod(rhs.toString()));
					break;
				default:
					throw AVM_Exceptions::InstructionUnknownException();
					break;
			}
			return (new Operand(type, result));
        }
		/******** End of operator+(IOperand const &rhs ) **********/

        /*----------------- Difference --------------------*/
        virtual IOperand const *operator-(IOperand const &rhs) const
        {
			eOperandType 	type;
			std::string 	result;

			type = (this->_type > rhs.getPrecision() ? this->_type : rhs.getType());
			
			switch (type)
			{ 
				case eOperandType::INT8:
				case eOperandType::INT16:
				case eOperandType::INT32:
					result = std::to_string(std::atoi(_value.c_str()) - std::stoi(rhs.toString().c_str()));
					break;
				case eOperandType::FLOAT:
					result = std::to_string(std::atof(_value.c_str()) - std::stof(rhs.toString().c_str()));
					break;
				case eOperandType::DOUBLE:
					result = std::to_string(std::stod(_value) - std::stod(rhs.toString().c_str()));
					break;
				default:
					throw AVM_Exceptions::InstructionUnknownException();
					break;
			}
			return (new Operand(type, result));
        }
		/********** END of operator-(IOperand const &rhs) **********/
		
		/*--------------- Product ------------------*/
        virtual IOperand const *operator*(IOperand const &rhs) const
		{
			eOperandType 	type;
			std::string 	result;

			type = (this->_type > rhs.getPrecision() ? this->_type : rhs.getType());
			
			switch (type)
			{
				case eOperandType::INT8:
				case eOperandType::INT16:
				case eOperandType::INT32:
					result = std::to_string(std::atoi(_value.c_str()) * std::stoi(rhs.toString().c_str()));
					break;
				case eOperandType::FLOAT:
					result = std::to_string(std::atof(_value.c_str()) * std::stof(rhs.toString().c_str()));
					break;
				case eOperandType::DOUBLE:
					result = std::to_string(std::stod(_value) * std::stod(rhs.toString().c_str()));
					break;
				default:
					throw AVM_Exceptions::InstructionUnknownException();
					break;
			}
			return (new Operand(type, result));
			
		}
		/******** End of operator*(IOperand const &rhs ) **********/


		/*------------ Quotient -------------------*/
        virtual IOperand const *operator/(IOperand const &rhs) const
		{
			eOperandType 	type;
			std::string 	result;

			type = (this->_type > rhs.getPrecision() ? this->_type : rhs.getType());

			
			if ((rhs.getType() == INT8 || rhs.getType() == INT16 || rhs.getType() == INT32) && std::atoi(rhs.toString().c_str()) == 0)
			{
				throw AVM_Exceptions::DivisionByZeroException();
			}
			else if ((rhs.getType() == FLOAT || rhs.getType() == DOUBLE) && std::stod(rhs.toString()) == 0.0)
			{
				throw AVM_Exceptions::DivisionByZeroException();
			}
			
			switch (type)
			{
				case eOperandType::INT8:
				case eOperandType::INT16:
				case eOperandType::INT32:
					result = std::to_string(std::atoi(_value.c_str()) / std::stoi(rhs.toString().c_str()));
					break;
				case eOperandType::FLOAT:
					result = std::to_string(std::atof(_value.c_str()) / std::stof(rhs.toString().c_str()));
					break;
				case eOperandType::DOUBLE:
					result = std::to_string(std::stod(_value) / std::stod(rhs.toString().c_str()));
					break;
				default:
					throw AVM_Exceptions::InstructionUnknownException();
					break;
			}
			return (new Operand(type, result));
		}
		/******** End of operator/(IOperand const &rhs ) **********/

		/*---------------- Modulo ------------------*/
        virtual IOperand const *operator%(IOperand const &rhs) const
		{
			eOperandType 	type;
			std::string 	result;

			type = (this->_type > rhs.getPrecision() ? this->_type : rhs.getType());
			
			if ((rhs.getType() == INT8 || rhs.getType() == INT16 || rhs.getType() == INT32) && !std::atoi	(rhs.toString().c_str()))
			{
				throw AVM_Exceptions::DivisionByZeroException();
			}
			else if ((rhs.getType() == FLOAT || rhs.getType() == DOUBLE) && 
					!std::stod(rhs.toString()))
			{
				throw AVM_Exceptions::DivisionByZeroException();
			}
			
			switch (type)
			{
				case eOperandType::INT8:
				case eOperandType::INT16:
				case eOperandType::INT32:
					result = std::to_string(std::atoi(_value.c_str()) / std::stoi(rhs.toString().c_str()));
					break;
				case eOperandType::FLOAT:
					result = std::to_string(std::atof(_value.c_str()) / std::stof(rhs.toString().c_str()));
					break;
				case eOperandType::DOUBLE:
					result = std::to_string(std::stod(_value.c_str()) / std::stod(rhs.toString().c_str()));
					break;
				default:
					throw AVM_Exceptions::InstructionUnknownException();
					break;
			}
			return (new Operand(type, result));
		} 
		/******** End of operator%(IOperand const &rhs ) **********/
};
template <typename T>
std::ostream &operator<<(std::ostream &os, Operand<T> const &srcObj)
{
    os << srcObj.toString();
    return (os);
}
#endif