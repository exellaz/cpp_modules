#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <limits>
# include <cstdlib>

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

        template<typename T> T nextElement(T it, int steps);
        template<typename T> void mergeInsertionSort(T& container, int depth);
        // template<typename T> bool compare(T a, T b);
        template<typename T> void swapElements(T it, int depth);

        private:

};

#endif

bool compare(int a, int b);

template<typename T> void PmergeMe::swapElements(T it, int depth)
{
    T start = nextElement(it, -depth + 1);
    T end = nextElement(start, depth);
    while (start != end) {
        std::iter_swap(start, nextElement(start, depth));
        start++;
    }
}

template<typename T> T PmergeMe::nextElement(T it, int steps)
{
    std::advance(it, steps);
    return it;
}

template<typename T> void PmergeMe::mergeInsertionSort(T& container, int depth)
{
    typedef typename T::iterator Iterator;

    int pairUnitsNbr = container.size() / depth;
    if (pairUnitsNbr < 2)
        return;

    bool isOdd = (pairUnitsNbr % 2 == 1) ? true : false;
    Iterator start = container.begin();
    Iterator last = nextElement(container.begin(), depth * pairUnitsNbr);
    Iterator end = nextElement(last, -(isOdd * depth));

    int step = 2 * depth;
    for (Iterator it = start; it != end; std::advance(it, step)) {
        Iterator a = nextElement(it, depth - 1);
        Iterator b = nextElement(it, depth * 2 - 1);
        if (compare(*a, *b))
            swapElements(a, depth);
    }
    mergeInsertionSort(container, depth * 2);
}
