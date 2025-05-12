#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& src)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
    if (this != &src) {
        _vector = src._vector;
    }

    return *this;
}