#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <limits>
# include <cstdlib>
# include <cmath>
# include <algorithm>
# include <set>
# include <list>

# define INT_MIN std::numeric_limits<int>::min()
# define INT_MAX std::numeric_limits<int>::max()

class PmergeMe
{
    public:
        std::vector<int> _vector;
        std::list<int> _list;
        PmergeMe();
        ~PmergeMe();
        PmergeMe& operator=(const PmergeMe& src);
        PmergeMe(const PmergeMe& src);

        bool isPositiveInteger(const std::string& str);
        void trim(std::string& str);
        int jacobsthalNumber(int n);
        template<typename Container>
        void initIntContainer(Container& container, char* av[]);

        template<typename T>
        void mergeInsertionSort(T& container, int groupSize);

        template<typename T, typename Iterator>
        void sortGroups(T& container, Iterator& end, int groupSize);

        template<typename T, typename ItVec>
        void initMainAndPend(T& container, ItVec& main, ItVec& pend, int groupSize, int numOfGroups);

        template<typename Iterator, typename ItVec>
        void insertJacobsthalGroups(ItVec& main, ItVec& pend);

        template<typename Iterator, typename ItVec>
        void insertRemainingPend(ItVec& main, ItVec& pend, bool isOdd);

        template<typename Iterator, typename T, typename ItVec>
        void reconstructSortedContainer(T& container, ItVec& main, int groupSize);

        template<typename T>
        void swapElements(T it, int groupSize);

        template<typename T>
        T next(T it, int steps);

        template<typename T>
        static bool compare(T a, T b);

        private:

};

template<typename T>
void printContainer(T& container);

# include "PmergeMe.tpp"


#endif
