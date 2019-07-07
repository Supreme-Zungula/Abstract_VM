#ifndef __AVM_PARSER__
#define __AVM_PARSER__

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "Exceptions.class.hpp"

class Parser
{
    private:
        std::vector<std::string> _commandsVec;
        bool            isValidDataType(std::string dataType) const;
        bool            isValidDataValue(std::string data) const;

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
        std::string     getCommand(std::string line) const;
        std::string     getDataType(std::string line) const;
        
};

#endif