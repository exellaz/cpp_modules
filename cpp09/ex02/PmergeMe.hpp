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

    // printContainer(container);
    // std::cout << "Depth: " << depth << "\n";

    std::vector<Iterator> main;
    std::vector<Iterator> pend;

    // std::cout << "b1: " << *(next(container.begin(), depth - 1)) << "\n";
    main.push_back(next(container.begin(), depth - 1)); // Push b1
    // std::cout << "a1: " << *(next(container.begin(), depth * 2 - 1)) << "\n";
    main.push_back(next(container.begin(), depth * 2 - 1)); // Push a1

    for (int i = 3; i <= numOfGroups; i++) {
        if (i % 2 == 1)
            pend.push_back(next(container.begin(), depth * i - 1));
        else
            main.push_back(next(container.begin(), depth * i - 1));
    }

    // std::cout << "Pend: " ;
    // for (int i = 0; i < static_cast<int>(pend.size()); i++) {
    //     std::cout << *(pend[i]) << " ";
    // }
    // std::cout << "\n";
    // std::cout << "Main: " ;
    // for (int i = 0; i < static_cast<int>(main.size()); i++) {
    //     std::cout << *(main[i]) << " ";
    // }
    // std::cout << "\n";

    int prevJacobsthal = jacobsthalNumber(1);
    // insertedNumbers only updates after all of the numbers from each group
    // has been inserted. Used to define the boundary for insertion
    int insertedNumbers = 0;
    for (int k = 2;; k++) {
        int currJacobsthal = jacobsthalNumber(k);
        int jacobsthalDiff = currJacobsthal - prevJacobsthal;
        int offset = 0;
        if (jacobsthalDiff > static_cast<int>(pend.size()))
            break;
        // pendIt is the end Iterator of the current group
        typename std::vector<Iterator>::iterator pendIt = next(pend.begin(), jacobsthalDiff - 1);
        // boundIt is the bound for the Binary Insertion in the main chain
        typename std::vector<Iterator>::iterator boundIt = next(main.begin(), currJacobsthal + insertedNumbers);
        for (int nbrOfInsertions = 0; nbrOfInsertions < jacobsthalDiff; nbrOfInsertions++) {
            //upper_bound uses Binary Insertion, passing it the compare function overloads the comparator
            typename std::vector<Iterator>::iterator idx = std::upper_bound(main.begin(), boundIt, *pendIt, compare<Iterator>);
            typename std::vector<Iterator>::iterator inserted = main.insert(idx, *pendIt);
            pend.erase(pendIt); // Remove the inserted iterator from pend
            std::advance(pendIt, -1); // Move the iterator backwards

            // Offset here is to adjust the boundary by reducing it when the current iterator is
            // inserted before the next iterator
            offset += (inserted - main.begin()) == currJacobsthal + insertedNumbers;
            // The boundary is adjusted by the above offset and the insertedNumbers
            boundIt = next(main.begin(), currJacobsthal + insertedNumbers - offset);
        }
        prevJacobsthal = currJacobsthal;
        insertedNumbers += jacobsthalDiff;
    }

    // This will be used to insert
    for (int i = pend.size() - 1; i >= 0; i--) {
        typename std::vector<Iterator>::iterator currPend = next(pend.begin(), i);
        typename std::vector<Iterator>::iterator currBound = next(main.begin(), main.size() - pend.size() + i + isOdd);
        // std::cout << "currBound: " << currBound - main.begin() << "\n";
        typename std::vector<Iterator>::iterator idx = std::upper_bound(main.begin(), currBound, *currPend, compare<Iterator>);
        // std::cout << "idx: " << *(*currPend) << "\n";
        main.insert(idx, *currPend);
    }

    std::vector<int> copy;
    copy.reserve(container.size());
    for (typename std::vector<Iterator>::iterator it = main.begin(); it != main.end(); it++) {
        for (int i = 0; i < depth; i++) {
            Iterator pairStart = *it;
            std::advance(pairStart, -depth + i + 1);
            copy.insert(copy.end(), *pairStart);
        }
    }

    std::copy(copy.begin(), copy.end(), container.begin());
}

#endif
