#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: ./RPN <expression>\n";
        return 1;
    }

    RPN rpn;
    rpn.calculate(argv[1]);

    while (!rpn._stack.empty()) {
        std::cout << rpn._stack.top();
        rpn._stack.pop();
    }

    return 0;
}
