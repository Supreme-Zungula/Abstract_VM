#include "../includes/Parser.class.hpp"

Parser::Parser() {}

Parser::Parser(std::string filename) : _filename(filename){}

Parser::Parser(Parser const &parserCpy)
{
    if (this != &parserCpy)
    {
        *this = parserCpy;
    }
}

Parser & Parser::operator=(Parser const &parser)
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

Parser::~Parser(){}

void Parser::readFile() const
{
    std::fstream    filestream(_filename);
    std::string     line;

    if (filestream.is_open())
    {
        while (std::getline(filestream, line))
        {
            std::cout << line;
        }
    }
    else
    {
        std::cout << "File not opened.\n"; 
    }
}

void Parser::readFile(std::string file)
{
    std::fstream    filestream(file);
    std::string     line;

    if (filestream.is_open())
    {
        while (std::getline(filestream, line))
        {
            std::cout << line << '\n';
        }
    }
    else
    {
        std::cout << "File not opened.\n"; 
    }
}