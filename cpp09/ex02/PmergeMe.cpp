#include "PmergeMe.hpp"

void PmergeMe::trim(std::string& str)
{
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) {
        str = "";
        return;
    }

    size_t last = str.find_last_not_of(" \t\r\n");
    str = str.substr(first, (last - first + 1));
}

bool PmergeMe::isPositiveInteger(const std::string& str)
{
    if (str.empty())
        return false;

    for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

void PmergeMe::initVector(char* av[])
{
    while (*av) {
        std::string numStr(*av);
        trim(numStr);
        if (!isPositiveInteger(numStr)) {
            std::cerr << "Error: not a positive integer\n";
            return;
        }
        long longInt = std::strtol(numStr.c_str(), NULL, 10);
        if (longInt < INT_MIN || longInt > INT_MAX) {
            std::cerr << "Error: integer overflow\n";
            return;
        }
        _vector.push_back(static_cast<int>(longInt));
        av++;
    }
}

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& src)
{
    (void)src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
    if (this != &src) {
        _vector = src._vector;
    }

    return *this;
}

int PmergeMe::jacobsthalNumber(int n)
{
    return round((std::pow(2, n + 1) + std::pow(-1, n)) / 3);
}
