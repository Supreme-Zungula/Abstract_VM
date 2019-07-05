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

void Parser::readFile(std::string file)
{
    std::fstream filestream(file);
    std::string line;

    if (filestream.is_open())
    {
        while (std::getline(filestream, line))
        {
            std::cout << line << '\n';
            if (hasComment(line))
            {
                std::cout << "comment" << '\n';
            }
            if (hasCommand(line))
            {
                if (isValidCommandName(getCommand(line)) && isValidDataType(line))
                {
                    _commandsVec.push_back(getCommand(line));
                }
                else
                {
                    throw AVM_Exceptions::SyntaxErrorException();
                }
            }
        }
        // displayCommands();
    }
    else
    {
        std::cout << "File not opened.\n";
    }
}

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
bool Parser::isValidCommandName(std::string command)
{
    if (command.compare("push") == 0)
    {
        return (true);
    }
    else if (command.compare("add") == 0)
    {
        return (true);
    }
    else if (command.compare("mul") == 0)
    {
        return (true);
    }
    else if (command.compare("dump") == 0)
    {
        return (true);
    }
    else if (command.compare("pop") == 0)
    {
        return (true);
    }
    else if (command.compare("assert") == 0)
    {
        return (true);
    }
    else if (command.compare("exit") == 0)
    {
        return (true);
    }
    else
    {
        return (false);
    }
}

/* Checks if the given string forms a valid data type i.e int8, int16, int32, float and double */
bool Parser::isValidDataType(std::string data) const
{
    size_t      start;
    size_t      end;
    
    start = data.find(' ');
    end = data.find('(');

    std::cout << "data: " << data.substr(start + 1, end -1 ) << '\n';
    if (start == std::string::npos || end == std::string::npos){ return false; }
    if (data.substr(start + 1,  end - 1).compare("int8") == 0)
    {
        return (true);
    }
    else if (data.substr(start + 1,  end-1).compare("int16") == 0)
    {
        return (true);
    }
    else if (data.substr(start + 1,  end-1).compare("int8") == 0)
    {
        return (true);
    }
    else if (data.substr(start + 1,  end-1).compare("int32") == 0)
    {
        return (true);
    }
    else if (data.substr(start + 1,  end-1).compare("float") == 0)
    {
        return (true);
    }
    else if (data.substr(start + 1,  end-1).compare("double") == 0)
    {
        return (true);
    }
    else
    {
        return (false);
    }    
}

void Parser::displayCommands() const
{
    for (std::string command : _commandsVec)
    {
        std::cout << command << '\n';
    }
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
    else if (line.find("add") != std::string::npos)
    {
        start = line.find("add");
        end = line.find(' ');
        return (line.substr(start, end));
    }
    else if (line.find("pop") != std::string::npos)
    {
        start = line.find("pop");
        end = line.find(' ');
        return (line.substr(start, end));
    }
    else if (line.find("mul") != std::string::npos)
    {
        start = line.find("mul");
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

/* 
std::string Parser::getDataType(std::string line) const
{
   
} 
*/