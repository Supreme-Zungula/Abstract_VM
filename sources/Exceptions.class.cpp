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

/* ---------------DIVISION BY ZERO------------------ */
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
/* --------------- END OF DIVISION BY ZERO------------------ */

/* ---------------UNKNOWN INSTRUCTION ERROR------------------ */
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
/* ---------------END OF UNKNOWN INSTRUCTION EXCEPTION------------------ */

/* ---------------SYNTAX ERROR EXCEPTION------------------ */
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

/* --------------- ASSERT INSTRUCTION EXCEPTION ------------------ */
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

/* --------------- EMPTY STACK EXCEPTION ------------------ */
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

/* ---------------FILE ERROR EXCEPTION ------------------ */
AVM_Exceptions::FileErrorException::FileErrorException() throw()
{
}

AVM_Exceptions::FileErrorException::FileErrorException(const FileErrorException &emptyStack) throw()
{
    if (this != &emptyStack)
    {
        *this = emptyStack;
    }
}

AVM_Exceptions::FileErrorException::~FileErrorException() throw()
{
}

AVM_Exceptions::FileErrorException &AVM_Exceptions::FileErrorException::operator=(const FileErrorException &emptyStack) throw()
{
    if (this != &emptyStack)
    {
        return (*(new AVM_Exceptions::FileErrorException(emptyStack)));
    }
    else
    {
        return( *this );
    }
}

const char *AVM_Exceptions::FileErrorException::what() const throw()
{
    return ("ERROR: Could not open or read file.");
}

/* --------------- ARITHMATIC EXCEPTION ------------------ */
AVM_Exceptions::ArithmaticException::ArithmaticException() throw()
{
}

AVM_Exceptions::ArithmaticException::ArithmaticException(const ArithmaticException &opExcept) throw()
{
    if (this != &opExcept)
    {
        *this = opExcept;
    }
}

AVM_Exceptions::ArithmaticException::~ArithmaticException() throw()
{
}

AVM_Exceptions::ArithmaticException &AVM_Exceptions::ArithmaticException::operator=(const ArithmaticException &opExcept) throw()
{
    if (this != &opExcept)
    {
        return (*(new AVM_Exceptions::ArithmaticException(opExcept)));
    }
    else
    {
        return( *this );
    }
}

const char *AVM_Exceptions::ArithmaticException::what() const throw()
{
    return ("ERROR: Cannot perform this arithmatic operation.");
}

/* --------------- NO COMMANDS EXCEPTION ------------------ */
AVM_Exceptions::NoCommandsException::NoCommandsException() throw()
{
}

AVM_Exceptions::NoCommandsException::NoCommandsException(const NoCommandsException &opExcept) throw()
{
    if (this != &opExcept)
    {
        *this = opExcept;
    }
}

AVM_Exceptions::NoCommandsException::~NoCommandsException() throw()
{
}

AVM_Exceptions::NoCommandsException &AVM_Exceptions::NoCommandsException::operator=(const NoCommandsException &opExcept) throw()
{
    if (this != &opExcept)
    {
        return (*(new AVM_Exceptions::NoCommandsException(opExcept)));
    }
    else
    {
        return( *this );
    }
}

const char *AVM_Exceptions::NoCommandsException::what() const throw()
{
    return ("ERROR: No commands provided.");
}


/* --------------- NO EXIT COMMAND EXCEPTION ------------------ */
AVM_Exceptions::NoExitException::NoExitException() throw()
{
}

AVM_Exceptions::NoExitException::NoExitException(const NoExitException &opExcept) throw()
{
    if (this != &opExcept)
    {
        *this = opExcept;
    }
}

AVM_Exceptions::NoExitException::~NoExitException() throw()
{
}

AVM_Exceptions::NoExitException &AVM_Exceptions::NoExitException::operator=(const NoExitException &opExcept) throw()
{
    if (this != &opExcept)
    {
        return (*(new AVM_Exceptions::NoExitException(opExcept)));
    }
    else
    {
        return( *this );
    }
}

const char *AVM_Exceptions::NoExitException::what() const throw()
{
    return ("ERROR: No exit command provided.");
}

/* --------------- OVERFLOW EXCEPTION ------------------ */
AVM_Exceptions::OverflowException::OverflowException() throw()
{
}

AVM_Exceptions::OverflowException::OverflowException(const OverflowException &opExcept) throw()
{
    if (this != &opExcept)
    {
        *this = opExcept;
    }
}

AVM_Exceptions::OverflowException::~OverflowException() throw()
{
}

AVM_Exceptions::OverflowException &AVM_Exceptions::OverflowException::operator=(const OverflowException &opExcept) throw()
{
    if (this != &opExcept)
    {
        return (*(new AVM_Exceptions::OverflowException(opExcept)));
    }
    else
    {
        return( *this );
    }
}

const char *AVM_Exceptions::OverflowException::what() const throw()
{
    return ("ERROR: value overflow.");
}

/* --------------- OVERFLOW and UNDERFLOW EXCEPTION ------------------ */
AVM_Exceptions::UnderflowException::UnderflowException() throw()
{
}

AVM_Exceptions::UnderflowException::UnderflowException(const UnderflowException &opExcept) throw()
{
    if (this != &opExcept)
    {
        *this = opExcept;
    }
}

AVM_Exceptions::UnderflowException::~UnderflowException() throw()
{
}

AVM_Exceptions::UnderflowException &AVM_Exceptions::UnderflowException::operator=(const UnderflowException &opExcept) throw()
{
    if (this != &opExcept)
    {
        return (*(new AVM_Exceptions::UnderflowException(opExcept)));
    }
    else
    {
        return( *this );
    }
}

const char *AVM_Exceptions::UnderflowException::what() const throw()
{
    return ("ERROR: value underflow.");
}