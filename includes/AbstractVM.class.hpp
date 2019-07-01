#ifndef __ABSTRACT_VM__
#define __ABSTRACT_VM__

#include <stack>
#include "Operand.template.hpp"
class AbstractVM
{
    private:
        /* data */
        std::stack<IOperand const&> avm_stack;
        
    public:
        AbstractVM(/* args */);
        ~AbstractVM();
        void pop();
        void push(IOperand const &);
        void dump();
        void assert_value(IOperand const &);
        void add();
        void sub();
        void mul();
        void div();
        void mod();
        void print();
        void exit();
};

#endif