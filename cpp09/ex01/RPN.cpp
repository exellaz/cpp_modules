#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& src)
    : _stack(src._stack)
{
}

RPN& RPN::operator=(const RPN& src)
{
    if (this != &src)
        _stack = src._stack;

    return *this;
}

RPN::~RPN()
{
}

void RPN::calculate(const std::string& expression)
{
    std::istringstream iss(expression);
    char c;
    while (iss >> c) {
        if (std::isdigit(c)) {
            _stack.push(c);
        }
    }
}
