#ifndef __AVM_PARSER__
#define __AVM_PARSER__

#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
#include "Exceptions.class.hpp"

class Parser
{
    private:
        std::vector<std::string> _commandsVec;

    public:
        Parser();
        Parser(Parser const &);
        Parser & operator=(Parser const &);
        ~Parser();

        void        readFile(std::string file);
        // void        readTerminal() const;
        bool            hasComment(std::string line) const;
        bool            hasCommand(std::string line) const;
        void            displayCommands() const;
        bool            isValidCommand(std::string line) const;
        bool            isValidCommandName(std::string command);
        bool            isValidDataType(std::string dataType) const;
        bool            isValidDataValue(std::string data);
        std::string     getCommand(std::string line) const;
        std::string     getDataType(std::string line) const;
        
};

#endif