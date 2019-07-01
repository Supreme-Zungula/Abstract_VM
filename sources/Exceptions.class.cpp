#include "../includes/Exceptions.class.hpp"

DivisionByZeroException::DivisionByZeroException() throw()
{
}

DivisionByZeroException::DivisionByZeroException(const DivisionByZeroException &cpyExcept) throw()
{
    if (this != &cpyExcept)
    {
        *this = cpyExcept;
    }
}

DivisionByZeroException::~DivisionByZeroException() throw()
{
}

DivisionByZeroException &DivisionByZeroException::operator=(const DivisionByZeroException &newExcept)
{
    if (this != &newExcept)
    {
        this->what = newExcept.what();
    }
}

const char *DivisionByZeroException::what() const throw()
{
    return ("ERROR: division by zero is forbidden.");
}

InstructionUnknownException::InstructionUnknownException() throw()
{
}

InstructionUnknownException::InstructionUnknownException(const InstructionUnknownException &cpyExcept) throw()
{
    if (this != &cpyExcept)
    {
        *this = cpyExcept;
    }
}

InstructionUnknownException &InstructionUnknownException::operator=(const InstructionUnknownException &newExcept) throw()
{
    if (this != &newExcept)
    {
        this->what = newExcept.what();
    }
}

InstructionUnknownException::~InstructionUnknownException() throw()
{
}

const char *InstructionUnknownException::what() const throw()
{
    return ("ERROR: Unknown instruction.");
}

SyntaxErrorException::SyntaxErrorException() throw()
{
}

SyntaxErrorException::SyntaxErrorException(const SyntaxErrorException &cpyExcept) throw()
{
    if (this != &cpyExcept)
    {
        *this = cpyExcept;
    }
}

SyntaxErrorException &SyntaxErrorException::operator=(const SyntaxErrorException &newExcept) throw()
{
    if (this != &newExcept)
    {
        this->what = newExcept.what();
    }
}

SyntaxErrorException::~SyntaxErrorException() throw()
{
}

const char *SyntaxErrorException::what() const throw()
{
    return ("ERROR: invalid syntax");
}

AssertInstructionException::AssertInstructionException() throw()
{
}

AssertInstructionException::AssertInstructionException(const AssertInstructionException &assertExcept) throw()
{
    if (this != &assertExcept)
    {
        *this = assertExcept;
    }
}

AssertInstructionException::~AssertInstructionException() throw()
{
}

AssertInstructionException &AssertInstructionException::operator=(const AssertInstructionException &assertExcept) throw()
{
    if (this != &assertExcept)
    {
        this->what = assertExcept.what();
    }
}

const char *AssertInstructionException::what() const throw()
{
    return ("ERROR: invalid assert value.");
}

EmptyStackException::EmptyStackException() throw()
{
}

EmptyStackException::EmptyStackException(const EmptyStackException &emptyStack) throw()
{
    if (this != &emptyStack)
    {
        *this = emptyStack;
    }
}

EmptyStackException::~EmptyStackException() throw()
{
}

EmptyStackException &EmptyStackException::operator=(const EmptyStackException &emptyStack) throw()
{
    if (this != &emptyStack)
    {
        this->what = emptyStack.what();
    }
}

const char *EmptyStackException::what() const throw()
{
    return ("ERROR: cannot run this action on a empty stack.");
}