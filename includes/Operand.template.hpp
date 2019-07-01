#ifndef __OPERAND_TP__
#define __OPERAND_TP__

#include "Exceptions.class.hpp"
#include "IOperand.interface.hpp"
#include "Factory.class.hpp"

template <typename T>
class Operand : public IOperand
{
    private:
        Factory             _factoryObj;
        eOperandType        _type;
        std::string         _value;

        Operand(/* args */){};

    public:
        Operand(eOperandType type, std::string value): _type(type), _value (value){}
        Operand(Operand const &cpyOP)
		{ 
			if (this != &cpyOP ) 
			{ *this = cpyOP; } 
		}

        Operand& operator=(Operand const &newOP)
        {
            if (this != &newOP)
            {
                this->_type = newOP.getType();
                this->_value = newOP.toString();
            }
            return (*this);
        }
        ~Operand(){};

        int getPrecision(void) const { return (this->_type); }; // Precision of the type of the instance
        eOperandType getType(void) const { return (this->_type); }; // Type of the value i.e int8, int16, int32, float and double
		std::string const &toString(void) const { return (this->_value); }; // return a string represention of the value
        
        /*-------------------- Sum -------------------------*/
        IOperand const *operator+(IOperand const &rhs) const
        {
			eOperandType 	type;
			Operand			result;
			T				sum;
			type = (this->_type > rhs.getPrecision() ? this->_type : rhs.getType());
			
			switch (type)
			{
				case INT8:
					sum = std::atoi(_value.c_str()) + std::atoi(rhs.toString().c_str());
					break;
				case INT16:
					sum = std::atoi(this->_value.c_str()) + std::atoi(rhs.toString().c_str());
					break;
				case INT32:
					sum = std::atoi(this->_value.c_str()) + std::atoi(rhs.toString().c_str());
					break;
				case FLOAT:
					sum = std::atof(this->_value.c_str()) + std::atoi(rhs.toString().c_str());
					break;
				case DOUBLE:
					sum = std::stod(this->_value) + std::stod(rhs.toString());
					break;
				default:
					// throw InstructionUnknownException();
					break;
			}
			return (_factoryObj.createOperand(type, std::to_string(sum)));
        }
		/******** End of operator+(IOperand const &rhs ) **********/

        /*----------------- Difference --------------------*/
        IOperand const *operator-(IOperand const &rhs) const
        {
			eOperandType 	type;
			Operand			result;
			T				difference;

			type = (this->_type > rhs.getPrecision() ? this->_type : rhs.getType());
			
			switch (type)
			{
				case INT8:
					difference = std::atoi(_value.c_str()) - std::atoi(rhs.toString().c_str());
					break;
				case INT16:
					difference = std::atoi(this->_value.c_str()) - std::atoi(rhs.toString().c_str());
					break;
				case INT32:
					difference = std::atoi(this->_value.c_str()) - std::atoi(rhs.toString().c_str());
					break;
				case FLOAT:
					difference = std::atof(this->_value.c_str()) - std::atoi(rhs.toString().c_str());
					break;
				case DOUBLE:
					difference = std::stod(this->_value) - std::stod(rhs.toString());
					break;
				default:
					// throw InstructionUnknownException();
					break;
			}
			return (_factoryObj.createOperand(type, std::to_string(difference)));
        }
		/********** END of operator-(IOperand const &rhs) **********/
		
		/*--------------- Product ------------------*/
        IOperand const *operator*(IOperand const &rhs) const
		{
			eOperandType 	type;
			Operand			result;
			T				product;

			type = (this->_type > rhs.getPrecision() ? this->_type : rhs.getType());
			
			switch (type)
			{
				case INT8:
					product = std::atoi(_value.c_str()) * std::atoi(rhs.toString().c_str());
					break;
				case INT16:
					product = std::atoi(this->_value.c_str()) * std::atoi(rhs.toString().c_str());
					break;
				case INT32:
					product = std::atoi(this->_value.c_str()) * std::atoi(rhs.toString().c_str());
					break;
				case FLOAT:
					product = std::atof(this->_value.c_str()) * std::atoi(rhs.toString().c_str());
					break;
				case DOUBLE:
					product = std::stod(this->_value) * std::stod(rhs.toString());
					break;
				default:
					// throw InstructionUnknownException();
					break;
			}
			return (_factoryObj.createOperand(type, std::to_string(product)));
			
		}
		/******** End of operator*(IOperand const &rhs ) **********/


		/*------------ Quotient -------------------*/
        IOperand const *operator/(IOperand const &rhs) const
		{
			eOperandType 	type;
			Operand			result;
			T				qoutient;

			type = (this->_type > rhs.getPrecision() ? this->_type : rhs.getType());
			
			/* if ((rhs.getType() == INT8 || rhs.getType() == INT16 || rhs.getType() == INT32) && !std::atoi(rhs.toString().c_str()))
			{
				throw DivisionByZeroException();
			}
			else if ((rhs.getType() == FLOAT || rhs.getType() == DOUBLE) && !std::stod(rhs.toString()))
			{
				throw DivisionByZeroException();
			} */
			
			type = (this->_type > rhs.getPrecision() ? this->_type : rhs.getType());
			
			switch (type)
			{
				case INT8:
					qoutient = std::atoi(_value.c_str()) / std::atoi(rhs.toString().c_str());
					break;
				case INT16:
					qoutient = std::atoi(this->_value.c_str()) / std::atoi(rhs.toString().c_str());
					break;
				case INT32:
					qoutient = std::atoi(this->_value.c_str()) / std::atoi(rhs.toString().c_str());
					break;
				case FLOAT:
					qoutient = std::atof(this->_value.c_str()) / std::atoi(rhs.toString().c_str());
					break;
				case DOUBLE:
					qoutient = std::stod(this->_value) / std::stod(rhs.toString());
					break;
				default:
					// throw InstructionUnknownException();
					break;
			}
			return (_factoryObj.createOperand(type, std::to_string(qoutient)));
		}
		/******** End of operator/(IOperand const &rhs ) **********/

		/*---------------- Modulo ------------------*/
        IOperand const *operator%(IOperand const &rhs) const
		{
			eOperandType 	type;
			Operand			result;
			T				modulo;

			type = (this->_type > rhs.getPrecision() ? this->_type : rhs.getType());
			
			/* if ((rhs.getType() == INT8 || rhs.getType() == INT16 || rhs.getType() == INT32) && !std::atoi(rhs.toString().c_str()))
			{
				throw DivisionByZeroException();
			}
			else if ((rhs.getType() == FLOAT || rhs.getType() == DOUBLE) && !std::stod(rhs.toString()))
			{
				throw DivisionByZeroException();
			} */
			
			type = (this->_type > rhs.getPrecision() ? this->_type : rhs.getType());
			
			switch (type)
			{
				case INT8:
					modulo = std::atoi(_value.c_str()) % std::atoi(rhs.toString().c_str());
					break;
				case INT16:
					modulo = std::atoi(this->_value.c_str()) % std::atoi(rhs.toString().c_str());
					break;
				case INT32:
					modulo = std::atoi(this->_value.c_str()) % std::atoi(rhs.toString().c_str());
					break;
				case FLOAT:
					modulo = std::atol(this->_value.c_str()) % std::atol(rhs.toString().c_str());
					break;
				case DOUBLE:
					modulo = std::atoll(_value.c_str()) % std::atoll(rhs.toString().c_str());
					break;
				default:
					// throw InstructionUnknownException();
					break;
			}
			return (_factoryObj.createOperand(type, std::to_string(modulo)));
		} 
		/******** End of operator%(IOperand const &rhs ) **********/
};

#endif