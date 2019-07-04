#ifndef __AVM_PARSER__
#define __AVM_PARSER__

#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>

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
        bool        hasComment(std::string line) const;
        bool        hasCommand(std::string line) const;
        bool        isValidCommand(std::string line) const;
        void        displayCommands() const;
        std::string getCommand(std::string line) const;
        std::string getDataType(std::string line) const;
        
};

#endif