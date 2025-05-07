#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <iostream>
# include <sstream>
# include <limits>

class RPN
{
    public:
        RPN();
        RPN(const RPN& src);
        RPN& operator=(const RPN& src);
        ~RPN();

        void calculate(const std::string& expression);
        void doOperation(const char c);

        class DivisionByZeroException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class IntegerOverflowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class InvalidOperandException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class InvalidExpressionException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };


    private:
        std::stack<int> _stack;
};

#endif
