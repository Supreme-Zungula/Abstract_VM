#include "../includes/Parser.class.hpp"

Parser::Parser() {}

Parser::Parser(Parser const &parserCpy)
{
    if (this != &parserCpy)
    {
        *this = parserCpy;
    }
}

Parser &Parser::operator=(Parser const &parser)
{
    if (this != &parser)
    {
        return (*(new Parser(parser)));
    }
    else
    {
        return (*this);
    }
}

Parser::~Parser() {}

/* 
void Parser::readFile(std::string file)
{
    std::fstream filestream(file);
    std::string line;

    if (filestream.is_open())
    {
        while (std::getline(filestream, line))
        {
            if (hasComment(line))
            {
                std::cout << "comment" << '\n';
            }
            if (hasCommand(line))
            {
                if (isValidCommand(line))
                {
                    _commandsVec.push_back(getCommand(line));
                    if (getCommand(line).compare("push") == 0 ||  getCommand(line).compare("assert") == 0)
                    {
                        std::cout << getCommand(line) << "->value: " << getDataValue(line) << '\n';
                    }
                }
                else
                {
                    throw AVM_Exceptions::SyntaxErrorException();
                }
            }
        }
        displayCommands();
    }
    else
    {
        std::cout << "File not opened.\n";
    }
}
*/

/* Checks if given line has a comment on it. */
bool Parser::hasComment(std::string line) const
{
    if (line.find_first_of(';') != std::string::npos)
    {
        return (true);
    }
    return (false);
}
/* Checks if given line has a commnand */
bool Parser::hasCommand(std::string line) const
{
    if (line.find("push") != std::string::npos)
    {
        return (true);
    }
    else if (line.find("add") != std::string::npos)
    {
        return (true);
    }
    else if (line.find("mul") != std::string::npos)
    {
        return (true);
    }
    else if (line.find("sub") != std::string::npos)
    {
        return (true);
    }
    else if (line.find("div") != std::string::npos)
    {
        return (true);
    }
    else if (line.find("mod") != std::string::npos)
    {
        return (true);
    }
    else if (line.find("print") != std::string::npos)
    {
        return (true);
    }
    else if (line.find("dump") != std::string::npos)
    {
        return (true);
    }
    else if (line.find("assert") != std::string::npos)
    {
        return (true);
    }
    else if (line.find("exit") != std::string::npos)
    {
        return (true);
    }
    else
    {
        return (false);
    }
}

/* Checks if given command is a valid command  */
bool Parser::isValidCommand(std::string data) const
{
    std::string     command;

    command = data.substr(0, 3);
    if (command.compare("add") == 0 || command.compare("sub") == 0 || 
        command.compare("div") == 0 || command.compare("mul") == 0 ||
        command.compare("pop") == 0 || command.compare("mod") == 0 )
    {
        return (true);
    }

    command = data.substr(0, 4);
    if (command.compare("exit") == 0 || command.compare("dump") == 0) { return (true); }
    
    command = data.substr(0, 5);
    if (command.compare("print") == 0 ) { return (true); }

    command = data.substr(0, 4);
    if (command.compare("push") == 0 && isValidDataType(data) && isValidDataValue(data)) 
    { 
        return (true); 
    }

    command = data.substr(0, 6);
    if (command.compare("assert") == 0 && isValidDataType(data) && isValidDataValue(data)) 
    { 
        return (true); 
    }

    return (false);
}


/* Checks if the given string forms a valid data type i.e int8, int16, int32, float and double */
bool Parser::isValidDataType(std::string data) const
{
    size_t          start;
    size_t          end;
    std::string     dataType;

    start   = data.find_first_of(' ');
    end     = data.find_first_of('(');

    if (start == std::string::npos || end == std::string::npos) { return (false); }
    dataType = data.substr(start + 1, end-start - 1);

    if (dataType.compare("int8") == 0 || 
        dataType.compare("int16") == 0 || 
        dataType.compare("int32") == 0 ||
        dataType.compare("float") == 0 ||
        dataType.compare("double") == 0 )
    {
        return (true);
    }
    return (false);
}

bool Parser::isValidDataValue(std::string data) const
{
    size_t      start;
    size_t      end;
    size_t      dots = 0;
    size_t      i = 0;

    start = data.find_last_of('(');
    end = data.find_first_of(')');

    if (start == std::string::npos || end == std::string::npos)
    {
        return (false);
    }
    
    std::string bracketsValue;
    bracketsValue = data.substr(start + 1, end-start-1);
    while (i < bracketsValue.length())
    {
        if (bracketsValue.at(i) == '.' )
        {
            dots++;
            if (dots > 1) { return (false); }
            i++;
        }
        else if (bracketsValue.at(i) == '-' )
        {
            if (i > 0) { return (false); }
            i++;
        }
        else if (!isdigit(bracketsValue.at(i)))
        {
            return (false);
        }
        else
        {
            i++;
        }
    }
    return (true);
}

std::string Parser::getCommand(std::string line) const
{
    size_t start;
    size_t end;

    if (line.find("push") != std::string::npos)
    {
        start = line.find("push");
        end = line.find(' ');
        return (line.substr(start, end));
    }
    else if (line.find("pop") != std::string::npos)
    {
        start = line.find("pop");
        end = line.find(' ');
        return (line.substr(start, end));
    }
    else if (line.find("add") != std::string::npos)
    {
        start = line.find("add");
        end = line.find(' ');
        return (line.substr(start, end));
    }
    else if (line.find("mul") != std::string::npos)
    {
        start = line.find("mul");
        end = line.find(' ');
        return (line.substr(start, end));
    }
    else if (line.find("div") != std::string::npos)
    {
        start = line.find("div");
        end = line.find(' ');
        return (line.substr(start, end));
    }
    else if (line.find("sub") != std::string::npos)
    {
        start = line.find("sub");
        end = line.find(' ');
        return (line.substr(start, end));
    }
    else if (line.find("mod") != std::string::npos)
    {
        start = line.find("mod");
        end = line.find(' ');
        return (line.substr(start, end));
    }
    else if (line.find("print") != std::string::npos)
    {
        start = line.find("print");
        end = line.find(' ');
        return (line.substr(start, end));
    }
    else if (line.find("dump") != std::string::npos)
    {
        start = line.find("dump");
        end = line.find(' ');
        return (line.substr(start, end));
    }
    else if (line.find("assert") != std::string::npos)
    {
        start = line.find("assert");
        end = line.find(' ');
        return (line.substr(start, end));
    }
    else if (line.find("exit") != std::string::npos)
    {
        start = line.find("exit");
        end = line.find(' ');
        return (line.substr(start, end));
    }
    else
    {
        return ("");
    }
}


std::string Parser::getDataValue(std::string line) const
{
    size_t      start;
    size_t      end;

    start = line.find_first_of('(');
    end = line.find_first_of(')');

    return (line.substr(start+1, end-start-1));
} 

/* void Parser::displayCommands() const
{
    for (std::string command : _commandsVec)
    {
        std::cout << command << '\n';
    }
} */