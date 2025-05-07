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

void RPN::doOperation(const char c)
{
    if (_stack.size() < 2)
        throw InvalidExpressionException();

    long rhs = _stack.top();
    _stack.pop();
    long lhs = _stack.top();
    _stack.pop();

    long value;
    if (c == '+')
        value = lhs + rhs;
    else if (c == '-')
        value = lhs - rhs;
    else if (c == '*')
        value = lhs * rhs;
    else {
        if (rhs == 0)
                throw DivisionByZeroException();
        value = lhs / rhs;
    }
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        throw IntegerOverflowException();

    _stack.push(static_cast<int>(value));
}

void RPN::calculate(const std::string& expression)
{
    std::istringstream iss(expression);
    char c;
    while (iss >> c) {
        if (std::isdigit(c))
            _stack.push(c - '0');
        else if (c == '+' || c == '-' || c == '*' || c == '/')
            doOperation(c);
        else
            throw InvalidOperandException();
    }
    if (_stack.size() != 1)
        throw InvalidExpressionException();
    std::cout << _stack.top() << "\n";
}

const char* RPN::DivisionByZeroException::what() const throw()
{
	return "Error: Division by zero.";
}

const char* RPN::IntegerOverflowException::what() const throw()
{
	return "Error: Integer overflow.";
}

const char* RPN::InvalidOperandException::what() const throw()
{
	return "Error: Invalid operand.";
}

const char* RPN::InvalidExpressionException::what() const throw()
{
	return "Error: Invalid expression.";
}
