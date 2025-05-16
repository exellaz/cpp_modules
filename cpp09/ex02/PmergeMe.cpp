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
