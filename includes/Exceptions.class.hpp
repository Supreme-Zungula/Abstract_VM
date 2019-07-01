#ifndef __MYEXCEPTIONS__
#define __MYEXCEPTIONS__

class DivisionByZeroException
{
    private:
        /* data */
    public:
        DivisionByZeroException () throw();
        DivisionByZeroException (const DivisionByZeroException&) throw();
        DivisionByZeroException& operator= (const DivisionByZeroException&) throw();
        virtual ~DivisionByZeroException() throw();
        virtual const char* what() const throw();
};

class InstructionUnknownException {
    public:
    InstructionUnknownException () throw();
    InstructionUnknownException (const InstructionUnknownException&) throw();
    InstructionUnknownException& operator= (const InstructionUnknownException&) throw();
    virtual ~InstructionUnknownException() throw();
    virtual const char* what() const throw();
};


class SyntaxErrorException {
    public:
    SyntaxErrorException () throw();
    SyntaxErrorException (const SyntaxErrorException&) throw();
    SyntaxErrorException& operator= (const SyntaxErrorException&) throw();
    virtual ~SyntaxErrorException() throw();
    virtual const char* what() const throw();
};

class AssertInstructionException {
    public:
    AssertInstructionException () throw();
    AssertInstructionException (const AssertInstructionException&) throw();
    AssertInstructionException& operator= (const AssertInstructionException&) throw();
    virtual ~AssertInstructionException() throw();
    virtual const char* what() const throw();
};

class EmptyStackException {
    public:
    EmptyStackException () throw();
    EmptyStackException (const EmptyStackException&) throw();
    EmptyStackException& operator= (const EmptyStackException&) throw();
    virtual ~EmptyStackException() throw();
    virtual const char* what() const throw();
};

class ArithmaticException {
    public:
    ArithmaticException () throw();
    ArithmaticException (const ArithmaticException&) throw();
    ArithmaticException& operator= (const ArithmaticException&) throw();
    virtual ~ArithmaticException() throw();
    virtual const char* what() const throw();
};


class NoExitException {
    public:
    NoExitException () throw();
    NoExitException (const NoExitException&) throw();
    NoExitException& operator= (const NoExitException&) throw();
    virtual ~NoExitException() throw();
    virtual const char* what() const throw();
};

#endif