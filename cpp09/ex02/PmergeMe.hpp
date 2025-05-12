#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>

class PmergeMe
{
    private:
        std::vector<unsigned int> _vector;

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe& operator=(const PmergeMe& src);
        PmergeMe(const PmergeMe& src);
};

#endif