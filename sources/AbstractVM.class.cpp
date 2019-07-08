#include "../includes/AbstractVM.class.hpp"

AbstractVM::AbstractVM()
{
}

AbstractVM::AbstractVM(AbstractVM const &avm)
{
    if (this != &avm)
    {
        *this = avm;
    }
}

AbstractVM &AbstractVM::operator=(AbstractVM const &avm)
{
    if (this != &avm)
    {
        return (*new AbstractVM(avm));
    }
    else
    {
        return (*this);
    }
}

AbstractVM::~AbstractVM()
{
}

void AbstractVM::readFromFile(std::string filename)
{
    std::fstream filestream(filename);
    std::string line;

    if (filestream.is_open())
    {
        while (std::getline(filestream, line))
        {
            if (_parser.hasCommand(line) && _parser.isValidCommand(line))
            {
                _commandsList.push_back(line);
            }
        }
        displayCommands();
    }
    else
    {
        throw AVM_Exceptions::FileErrorException();
    }
}

void AbstractVM::displayCommands() const
{
    std::cout << "COMMANDS LIST:" << std::endl;
    for (std::string commnad :  _commandsList)
    {
        std::cout << commnad << '\n';
    }
}

void AbstractVM::push(IOperand const *newOP)
{
    if (newOP)
    {
        this->_avm_stack.push_front(newOP);
    }
}

void    AbstractVM::pop()
{
    if (this->_avm_stack.size() > 0)
    {
        _avm_stack.pop_front();
    }
    else
    {
        throw AVM_Exceptions::EmptyStackException();
    }
}

void  AbstractVM::dump() const
{
    for(const IOperand *op : _avm_stack)
    {
        std::cout << op << '\n';
    }
}

bool AbstractVM::assert_value(IOperand const *op)
{
    if (_avm_stack.empty())
    {
        return false;
    }
    else if ( op->toString().compare(_avm_stack.front()->toString()) != 0)
    {
        return (false);
    }
    else
    {
        return (true);
    }
}

void AbstractVM::add()
{
    if (_avm_stack.size()  >= 2)
    {
        IOperand const *firstOP(_avm_stack.front());
        _avm_stack.pop_front();

        IOperand const *secondOP(_avm_stack.front());
        _avm_stack.pop_front();
        _avm_stack.push_front(*firstOP + *secondOP);
    }
    else
    {
        throw AVM_Exceptions::ArithmaticException();
    }
}


void AbstractVM::sub()
{
    if (_avm_stack.size()  >= 2)
    {
        IOperand const *firstOP(_avm_stack.front());
        _avm_stack.pop_front();

        IOperand const *secondOP(_avm_stack.front());
        _avm_stack.pop_front();
        _avm_stack.push_front(*firstOP - *secondOP);
    }
    else
    {
        throw AVM_Exceptions::ArithmaticException();
    }
}

void AbstractVM::mul()
{
    if (_avm_stack.size()  >= 2)
    {
        IOperand const *firstOP(_avm_stack.front());
        _avm_stack.pop_front();

        IOperand const *secondOP(_avm_stack.front());
        _avm_stack.pop_front();
        _avm_stack.push_front((*firstOP) * (*secondOP));
    }
    else
    {
        throw AVM_Exceptions::ArithmaticException();
    }
}

void AbstractVM::div()
{
    if (_avm_stack.size()  >= 2)
    {
        IOperand const *firstOP(_avm_stack.front());
        _avm_stack.pop_front();

        IOperand const *secondOP(_avm_stack.front());
        _avm_stack.pop_front();
        _avm_stack.push_front((*firstOP) / (*secondOP));
    }
    else
    {
        throw AVM_Exceptions::ArithmaticException();
    }
}

void AbstractVM::mod()
{
    if (_avm_stack.size()  >= 2)
    {
        IOperand const *firstOP(_avm_stack.front());
        _avm_stack.pop_front();

        IOperand const *secondOP(_avm_stack.front());
        _avm_stack.pop_front();
        _avm_stack.push_front((*firstOP) % (*secondOP));
    }
    else
    {
        throw AVM_Exceptions::ArithmaticException();
    }
}