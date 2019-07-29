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
            if (line.empty() || _parser.hasComment(line) )
            {
                continue;
            }
            else if (_parser.hasCommand(line))
            {
                if (_parser.isValidCommand(line))
                {
                    _commandsList.push_back(line);
                }
                else
                {
                    throw AVM_Exceptions::SyntaxErrorException();
                } 
            }
            else
            {
                throw AVM_Exceptions::SyntaxErrorException();
            }
            line.clear();
        }
    }
    else
    {
        throw AVM_Exceptions::FileErrorException();
    }
}

void AbstractVM::readFromTerminal()
{
    std::string     line;

    while (true)
    {
        std::getline(std::cin, line);
        if (line.compare(";;") == 0) 
        { 
            _commandsList.push_back("exit");
            break; 
        }
        else if (_parser.hasComment(line) || line.empty()) { continue;}
        else if (_parser.hasCommand(line))
        {
            if (_parser.isValidCommand(line))
            {
                _commandsList.push_back(line);
            }
            else
            {
                throw AVM_Exceptions::SyntaxErrorException();
            } 
        }
        else
        {
            throw AVM_Exceptions::SyntaxErrorException();
        }
        
    }
}

void AbstractVM::runCommands()
{
    if (_commandsList.empty()) throw AVM_Exceptions::NoCommandsException();

    for (std::string command : _commandsList)
    {
        if (_parser.getCommand(command).compare("push") == 0)
        {
            pushValueToStack(command);
        }
        else if (_parser.getCommand(command).compare("assert") == 0)
        {
            assertStackValue(command);
        }
        else if (_parser.getCommand(command).compare("pop") == 0)
        {
            this->pop();
        }
        else if (_parser.getCommand(command).compare("dump") == 0)
        {
            this->dump();
        }
        else if (_parser.getCommand(command).compare("add") == 0)
        {
            this->add();
        }
        else if (_parser.getCommand(command).compare("sub") == 0)
        {
            this->sub();
        }
        else if (_parser.getCommand(command).compare("mul") == 0)
        {
            this->mul();
        }
        else if (_parser.getCommand(command).compare("div") == 0)
        {
            this->div();
        }
        else if (_parser.getCommand(command).compare("mod") == 0)
        {
            this->mod();
        }
        else if (_parser.getCommand(command).compare("print") == 0)
        {
            this->print();
        }
        else if (_parser.getCommand(command).compare("exit") == 0)
        {
            this->exit();
        }
    }
    if (!hasExit()) throw AVM_Exceptions::NoExitException();
}

void AbstractVM::displayCommands() const
{
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
        std::cout << op->toString() << '\n';
    }
}

bool AbstractVM::assert_value(IOperand const *op)
{
    if (_avm_stack.empty())
    {
        return false;
    }
    else if (op->getType() != _avm_stack.front()->getType())
    {
        return (false);
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
        IOperand const *secondOP(_avm_stack.front());
        _avm_stack.pop_front();

        IOperand const *firstOP(_avm_stack.front());
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
        IOperand const *secondOP(_avm_stack.front());
        _avm_stack.pop_front();

        IOperand const *firstOP(_avm_stack.front());
        _avm_stack.pop_front();
        _avm_stack.push_front((*firstOP) % (*secondOP));
    }
    else
    {
        throw AVM_Exceptions::ArithmaticException();
    }
}

void AbstractVM::print()
{
    if (_avm_stack.front()->getType() == INT8)
    {
        std::cout << (char)std::atoi(_avm_stack.front()->toString().c_str()) << '\n';
    }
    else
    {
        throw AVM_Exceptions::AssertInstructionException();
    }
    
}

void AbstractVM::exit()
{
    std::exit(0);
}

void AbstractVM::pushValueToStack(std::string command)
{
    std::string dataType = _parser.getDataType(command);

    if (dataType.compare("int8") == 0 )
    {
        this->push(_factory.createOperand(INT8, _parser.getDataValue(command)));
    }
    else if (dataType.compare("int16") == 0)
    {
        this->push(_factory.createOperand(INT16, _parser.getDataValue(command)));
    }
    else if (dataType.compare("int32") == 0)
    {
        this->push(_factory.createOperand(INT32, _parser.getDataValue(command)));
    }
    else if (dataType.compare("float") == 0)
    {
        this->push(_factory.createOperand(FLOAT, _parser.getDataValue(command)));
    }
    else if (dataType.compare("double") == 0)
    {
        this->push(_factory.createOperand(DOUBLE, _parser.getDataValue(command)));
    }
    else
    {
        throw AVM_Exceptions::InstructionUnknownException();
    }
}

void AbstractVM::assertStackValue(std::string command)
{
    std::string dataType = _parser.getDataType(command);

    if (dataType.compare("int8") == 0 )
    {
        if( !assert_value(_factory.createOperand(INT8, _parser.getDataValue(command))))
            throw AVM_Exceptions::AssertInstructionException();
    }
    else if (dataType.compare("int16") == 0)
    {
        if( !assert_value(_factory.createOperand(INT16, _parser.getDataValue(command))))
            throw AVM_Exceptions::AssertInstructionException();
    }
    else if (dataType.compare("int32") == 0)
    {
        if( !assert_value(_factory.createOperand(INT32, _parser.getDataValue(command))))
            throw AVM_Exceptions::AssertInstructionException();
    }
    else if (dataType.compare("float") == 0)
    {
        if( !assert_value(_factory.createOperand(FLOAT, _parser.getDataValue(command))))
            throw AVM_Exceptions::AssertInstructionException();
    }
    else if (dataType.compare("double") == 0)
    {
        if( !assert_value(_factory.createOperand(DOUBLE, _parser.getDataValue(command))))
            throw AVM_Exceptions::AssertInstructionException();
    }
    else
    {
        throw AVM_Exceptions::InstructionUnknownException();
    }
}

bool AbstractVM::hasExit() const
{
    for (std::string command : _commandsList)
    {
        if (command.compare("exit") == 0)
        {
            return (true);
        }
    }
    return (false);
}