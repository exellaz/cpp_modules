#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <limits>
# include <cstdlib>
# include <cmath>
# include <algorithm>

# define INT_MIN std::numeric_limits<int>::min()
# define INT_MAX std::numeric_limits<int>::max()

class PmergeMe
{
    public:
        std::vector<int> _vector;
        PmergeMe();
        ~PmergeMe();
        PmergeMe& operator=(const PmergeMe& src);
        PmergeMe(const PmergeMe& src);

        template<typename T>
        void	printContainer(T& container)
        {
            typename T::iterator lastComma = --container.end();

            std::cout << "{";
            for (typename T::iterator it = container.begin(); it != container.end(); ++it) {
                std::cout << *it;
                if (it != lastComma)
                    std::cout << ",";
            }
            std::cout << "}\n";
        }

        static bool isPositiveInteger(const std::string& str);
        static void trim(std::string& str);
        void initVector(char* av[]);
        static int jacobsthalNumber(int n);

        template<typename T> T next(T it, int steps);
        template<typename T> void mergeInsertionSort(T& container, int depth);
        template<typename T, typename Iterator> void sortGroups(T& container, Iterator& end, int depth);
        template<typename T> static bool compare(T a, T b);
        template<typename T> void swapElements(T it, int depth);

        private:

};

template<typename T> bool PmergeMe::compare(T a, T b)
{
    return *a < *b;
}

template<typename T> void PmergeMe::swapElements(T it, int depth)
{
    T start = next(it, -depth + 1);
    T end = next(start, depth);
    while (start != end) {
        std::iter_swap(start, next(start, depth));
        start++;
    }
}

template<typename T> T PmergeMe::next(T it, int steps)
{
    std::advance(it, steps);
    return it;
}

template<typename T, typename Iterator> void PmergeMe::sortGroups(T& container, Iterator& end, int depth)
{
    int step = 2 * depth;
    for (Iterator it = container.begin(); it != end; std::advance(it, step)) {
        Iterator a = next(it, depth - 1);
        Iterator b = next(it, depth * 2 - 1);
        if (!compare(a, b)) // Number of comparisons here is always once per group for each recursion
            swapElements(a, depth);
    }
}

// Depth also corresponds to the amount of elements per group
template<typename T> void PmergeMe::mergeInsertionSort(T& container, int depth)
{
    typedef typename T::iterator Iterator;

    int numOfGroups = container.size() / depth;
    if (numOfGroups < 2)
        return;

    bool isOdd = numOfGroups % 2 == 1; // Number of groups is odd
    Iterator lastGroup = next(container.begin(), depth * numOfGroups); // End iterator of last group
    Iterator end = next(lastGroup, -(isOdd * depth)); // Start iterator of last group

    sortGroups(container, end, depth);
    mergeInsertionSort(container, depth * 2);

    printContainer(container);

}

#endif
