#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <iostream>
# include <sstream>

class RPN
{
    public:
        RPN();
        RPN(const RPN& src);
        RPN& operator=(const RPN& src);
        ~RPN();

        void calculate(const std::string& expression);
        std::stack<int> _stack;

    private:
};

#endif
