#include "../includes/Exceptions.class.hpp"

AVM_Exceptions::AVM_Exceptions() {}
AVM_Exceptions::AVM_Exceptions(AVM_Exceptions const &cpyExcept)
{
    if (this != &cpyExcept)
    {
        *this = cpyExcept;
    }
}
AVM_Exceptions& AVM_Exceptions::operator=(AVM_Exceptions const &avmExcept)
{
    if (this != &avmExcept)
    {
        AVM_Exceptions newExcept = AVM_Exceptions(avmExcept);
        return (newExcept);
    }
    else
    {
        return(*this);   
    }
}

AVM_Exceptions::~AVM_Exceptions() throw() {}

AVM_Exceptions::DivisionByZeroException::DivisionByZeroException()
{
}

AVM_Exceptions::DivisionByZeroException::DivisionByZeroException(const DivisionByZeroException &cpyExcept) 
{
    if (this != &cpyExcept)
    {
        *this = cpyExcept;
    }
}

AVM_Exceptions::DivisionByZeroException::~DivisionByZeroException() throw()
{
}

AVM_Exceptions::DivisionByZeroException &AVM_Exceptions::DivisionByZeroException::operator=(const DivisionByZeroException &newExcept)
{
    if (this != &newExcept)
    {
        this->what = newExcept.what();
    }
}

const char *AVM_Exceptions::DivisionByZeroException::what() const throw()
{
    return ("ERROR: division by zero is forbidden.");
}

AVM_Exceptions::InstructionUnknownException::InstructionUnknownException() throw()
{
}

AVM_Exceptions::InstructionUnknownException::InstructionUnknownException(const InstructionUnknownException &cpyExcept) 
{
    if (this != &cpyExcept)
    {
        *this = cpyExcept;
    }
}

AVM_Exceptions::InstructionUnknownException &AVM_Exceptions::InstructionUnknownException::operator=(const InstructionUnknownException &newExcept)
{
    if (this != &newExcept)
    {
        this->what = newExcept.what();
    }
}

AVM_Exceptions::InstructionUnknownException::~InstructionUnknownException() throw()
{
}

const char *AVM_Exceptions::InstructionUnknownException::what() const throw()
{
    return ("ERROR: Unknown instruction.");
}

AVM_Exceptions::SyntaxErrorException::SyntaxErrorException()
{
}

AVM_Exceptions::SyntaxErrorException::SyntaxErrorException(const SyntaxErrorException &cpyExcept)
{
    if (this != &cpyExcept)
    {
        *this = cpyExcept;
    }
}

AVM_Exceptions::SyntaxErrorException &AVM_Exceptions::SyntaxErrorException::operator=(const SyntaxErrorException &newExcept)
{
    if (this != &newExcept)
    {
        AVM_Exceptions::SyntaxErrorException syntaxExcept =  AVM_Exceptions::SyntaxErrorException(newExcept);
        return (syntaxExcept);
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

AVM_Exceptions::AssertInstructionException::AssertInstructionException() 
{
}

AVM_Exceptions::AssertInstructionException::AssertInstructionException(const AssertInstructionException &assertExcept)
{
    if (this != &assertExcept)
    {
        *this = assertExcept;
    }
}

AVM_Exceptions::AssertInstructionException::~AssertInstructionException() throw()
{
}

AVM_Exceptions::AssertInstructionException &AVM_Exceptions::AssertInstructionException::operator=(const AssertInstructionException &assertExcept)
{
    if (this != &assertExcept)
    {
        this->what = assertExcept.what();
    }
}

const char *AVM_Exceptions::AssertInstructionException::what() const throw()
{
    return ("ERROR: invalid assert value.");
}

AVM_Exceptions::EmptyStackException::EmptyStackException()
{
}

AVM_Exceptions::EmptyStackException::EmptyStackException(const EmptyStackException &emptyStack)
{
    if (this != &emptyStack)
    {
        *this = emptyStack;
    }
}

AVM_Exceptions::EmptyStackException::~EmptyStackException() throw()
{
}

AVM_Exceptions::EmptyStackException &AVM_Exceptions::EmptyStackException::operator=(const EmptyStackException &emptyStack)
{
    if (this != &emptyStack)
    {
        this->what = emptyStack.what();
    }
}

const char *AVM_Exceptions::EmptyStackException::what() const throw()
{
    return ("ERROR: cannot run this action on a empty stack.");
}