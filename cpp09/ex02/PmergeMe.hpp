#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# ifndef TRUNCATE
#  define TRUNCATE 1
# endif

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
        PmergeMe();
        ~PmergeMe();
        PmergeMe& operator=(const PmergeMe& src);
        PmergeMe(const PmergeMe& src);

        void compareContainers(int ac, char **av);

        template<typename T>
        static bool comp(T a, T b);

    private:
        std::vector<int> _vector;
        std::list<int> _list;
        static int _comparisons;

        void printBeforeSort(int ac, char **av);
        double getMicroseconds();
        bool isPositiveInteger(const std::string& str);
        void trim(std::string& str);
        int jacobsthalNumber(int n);
        long getTheoreticalMax(long n);

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
        void printContents(T& container);

        template<typename T>
        void swapElements(T it, int groupSize);

        template<typename T>
        T next(T it, int steps);
};

# include "PmergeMe.tpp"


#endif
