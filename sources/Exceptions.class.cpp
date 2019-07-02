#include "../includes/Exceptions.class.hpp"

AVM_Exceptions::AVM_Exceptions() throw() {}
AVM_Exceptions::AVM_Exceptions(AVM_Exceptions const &cpyExcept)
{
    if (this != &cpyExcept)
    {
        *this = cpyExcept;
    }
}
AVM_Exceptions &AVM_Exceptions::operator=(AVM_Exceptions const &avmExcept) throw()
{
    if (this != &avmExcept)
    {
        return (*(new AVM_Exceptions(avmExcept)));
    }
    else
    {
        return (*this);
    }
}

AVM_Exceptions::~AVM_Exceptions() throw() {}

AVM_Exceptions::DivisionByZeroException::DivisionByZeroException() throw()
{
}

AVM_Exceptions::DivisionByZeroException::DivisionByZeroException(const DivisionByZeroException &cpyExcept) throw()
{
    if (this != &cpyExcept)
    {
        *this = cpyExcept;
    }
}

AVM_Exceptions::DivisionByZeroException::~DivisionByZeroException() throw()
{
}

AVM_Exceptions::DivisionByZeroException &AVM_Exceptions::DivisionByZeroException::operator=(const DivisionByZeroException &newExcept) throw()
{
    if (this != &newExcept)
    {
        return (*(new AVM_Exceptions::DivisionByZeroException(newExcept)));
    }
    else
    {
        return (*this);
    }
}

const char *AVM_Exceptions::DivisionByZeroException::what() const throw()
{
    return ("ERROR: division by zero is forbidden.");
}

AVM_Exceptions::InstructionUnknownException::InstructionUnknownException() throw()
{
}

AVM_Exceptions::InstructionUnknownException::InstructionUnknownException(const InstructionUnknownException &cpyExcept) throw()
{
    if (this != &cpyExcept)
    {
        *this = cpyExcept;
    }
}

AVM_Exceptions::InstructionUnknownException &AVM_Exceptions::InstructionUnknownException::operator=(const InstructionUnknownException &newExcept) throw()
{
    if (this != &newExcept)
    {
        return (*(new AVM_Exceptions::InstructionUnknownException(newExcept)));
    }
    else
    {
        return (*this);
    }
}

AVM_Exceptions::InstructionUnknownException::~InstructionUnknownException() throw()
{
}

const char *AVM_Exceptions::InstructionUnknownException::what() const throw()
{
    return ("ERROR: Unknown instruction.");
}

AVM_Exceptions::SyntaxErrorException::SyntaxErrorException() throw()
{
}

AVM_Exceptions::SyntaxErrorException::SyntaxErrorException(const SyntaxErrorException &cpyExcept) throw()
{
    if (this != &cpyExcept)
    {
        *this = cpyExcept;
    }
}

AVM_Exceptions::SyntaxErrorException &AVM_Exceptions::SyntaxErrorException::operator=(const SyntaxErrorException &newExcept) throw()
{
    if (this != &newExcept)
    {
        return (*(new AVM_Exceptions::SyntaxErrorException(newExcept)));
    }
    else
    {
        return (*this);
    }
}

AVM_Exceptions::SyntaxErrorException::~SyntaxErrorException() throw()
{
}

const char *AVM_Exceptions::SyntaxErrorException::what() const throw()
{
    return ("ERROR: invalid syntax");
}

AVM_Exceptions::AssertInstructionException::AssertInstructionException() throw()
{
}

AVM_Exceptions::AssertInstructionException::AssertInstructionException(const AssertInstructionException &assertExcept) throw()
{
    if (this != &assertExcept)
    {
        *this = assertExcept;
    }
}

AVM_Exceptions::AssertInstructionException::~AssertInstructionException() throw()
{
}

AVM_Exceptions::AssertInstructionException &AVM_Exceptions::AssertInstructionException::operator=(const AssertInstructionException &assertExcept) throw()
{
    if (this != &assertExcept)
    {
        return (*(new AVM_Exceptions::AssertInstructionException(assertExcept)));
    }
    else
    {
        return (*this);
    }
}

const char *AVM_Exceptions::AssertInstructionException::what() const throw()
{
    return ("ERROR: invalid assert value.");
}

AVM_Exceptions::EmptyStackException::EmptyStackException() throw()
{
}

AVM_Exceptions::EmptyStackException::EmptyStackException(const EmptyStackException &emptyStack) throw()
{
    if (this != &emptyStack)
    {
        *this = emptyStack;
    }
}

AVM_Exceptions::EmptyStackException::~EmptyStackException() throw()
{
}

AVM_Exceptions::EmptyStackException &AVM_Exceptions::EmptyStackException::operator=(const EmptyStackException &emptyStack) throw()
{
    if (this != &emptyStack)
    {
        return (*(new AVM_Exceptions::EmptyStackException(emptyStack)));
    }
    else
    {
        return( *this );
    }
}

const char *AVM_Exceptions::EmptyStackException::what() const throw()
{
    return ("ERROR: cannot run this action on a empty stack.");
}