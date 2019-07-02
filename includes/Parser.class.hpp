#ifndef __AVM_PARSER__
#define __AVM_PARSER__

#include <iostream>
#include <fstream>
#include <ostream>

class Parser
{
    private:
        std::string     _filename;

    public:
        Parser();
        Parser(std::string  filename);
        Parser(Parser const &);
        Parser & operator=(Parser const &);
        ~Parser();

        void    readFile() const;
        void    readFile(std::string file);
};

#endif