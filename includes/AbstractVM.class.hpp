#ifndef __ABSTRACT_VM__
#define __ABSTRACT_VM__

#include <list>
#include <fstream>
#include <iostream>
#include "Operand.template.hpp"
#include "Factory.class.hpp"
#include "Parser.class.hpp"

class AbstractVM
{
    private:
        /* data */
        std::list<IOperand const *>     _avm_stack;
        std::list<std::string>          _commandsList;
        Factory                         _factory;
        Parser                          _parser;

    public:
        AbstractVM();
        AbstractVM(AbstractVM const &);
        AbstractVM& operator=(AbstractVM const &);
        ~AbstractVM();

        void                readFromFile(std::string filename);
        void                readFromTerminal();
        void                displayCommands() const;
        void                runCommands();
        void                push(IOperand const *);
        void                pop();
        void                dump() const;
        bool                assert_value(IOperand const *);
        void                add();
        void                sub();
        void                mul();
        void                div();
        void                mod();
        void                print();
        void                exit();
};

#endif