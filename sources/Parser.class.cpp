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
            if (hasComment(line))
            {
                std::cout << "comment" << '\n';
            }
            if (hasCommand(line))
            {
                _commandsVec.push_back(getCommand(line));
            }
        }
        displayCommands();
    }
    else
    {
        std::cout << "File not opened.\n";
    }
}

bool Parser::hasComment(std::string line) const
{
    if (line.find_first_of(';') != std::string::npos)
    {
        return (true);
    }
    return (false);
}

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