/* #include "../includes/Operand.class.hpp"

template <typename T>
Operand<T>::Operand() : _value(0)
{
}

template <typename T>
Operand<T>::Operand(eOperandType type, T value) : _type(type), _value()
{
}

template <typename T>
Operand<T>::Operand(Operand const &operand)
{
    if (this != &operand)
    {
        *this = operand;
    }
}

template <typename T>
Operand<T>::~Operand()
{
}

template <typename T>
Operand<T> &Operand<T>::operator=(Operand const &newOP)
{
    if (this != &newOP)
    {
        this->_type = newOP.getType();
        this->_value = newOP.getValue();
    }
    return (*this);
}

template <typename T>
int Operand<T>::getPrecision()
{
    return (this->_type);
}

template <typename T>
T Operand<T>::getValue() const
{
    return (this->_value);
}

template <typename T>
eOperandType Operand<T>::getType()
{
    return (this->_type);
}

template <typename T>
IOperand const* Operand<T>::operator+(IOperand cosnt &rhs) const
{
    if (this.type > rhs.getType())
} */