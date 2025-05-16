#include "PmergeMe.hpp"

template<typename Container>
void PmergeMe::initIntContainer(Container& container, char* av[])
{
    std::set<int> seen;

    while (*av) {
        std::string numStr(*av);
        trim(numStr);

        if (!isPositiveInteger(numStr))
            throw std::logic_error("not a positive integer");

        long longInt = std::strtol(numStr.c_str(), NULL, 10);
        if (longInt < INT_MIN || longInt > INT_MAX)
            throw std::logic_error("integer overflow");

        int value = static_cast<int>(longInt);
        if (seen.find(value) != seen.end())
            throw std::logic_error("contains duplicate number");

        seen.insert(value);
        container.push_back(value);
        av++;
    }
}

template<typename T>
void PmergeMe::mergeInsertionSort(T& container, int groupSize)
{
    typedef typename T::iterator Iterator;

    int numOfGroups = container.size() / groupSize;
    if (numOfGroups < 2)
        return;

    bool isOdd = numOfGroups % 2 == 1; // Number of groups is odd
    Iterator lastGroup = next(container.begin(), groupSize * numOfGroups); // End iterator of last group
    Iterator end = next(lastGroup, -(isOdd * groupSize)); // Start iterator of last group

    sortGroups(container, end, groupSize);
    mergeInsertionSort(container, groupSize * 2);

    std::vector<Iterator> main, pend;
    initMainAndPend(container, main, pend, groupSize, numOfGroups);
    insertJacobsthalGroups<Iterator>(main, pend);
    insertRemainingPend<Iterator>(main, pend, isOdd);
    reconstructSortedContainer<Iterator>(container, main, groupSize);
}

template<typename T, typename Iterator>
void PmergeMe::sortGroups(T& container, Iterator& end, int groupSize)
{
    int step = 2 * groupSize;
    for (Iterator it = container.begin(); it != end; std::advance(it, step)) {
        Iterator a = next(it, groupSize - 1);
        Iterator b = next(it, groupSize * 2 - 1);
        if (!comp(a, b)) // Number of comparisons is always once per group for each recursion
            swapElements(a, groupSize);
    }
}

template<typename T, typename ItVec>
void PmergeMe::initMainAndPend(T& container, ItVec& main, ItVec& pend, int groupSize, int numOfGroups)
{
    main.push_back(next(container.begin(), groupSize - 1)); // Push b1
    main.push_back(next(container.begin(), groupSize * 2 - 1)); // Push a1

    for (int i = 3; i <= numOfGroups; i++) {
        if (i % 2 == 1)
            pend.push_back(next(container.begin(), groupSize * i - 1));
        else
            main.push_back(next(container.begin(), groupSize * i - 1));
    }
}

template<typename Iterator, typename ItVec>
void PmergeMe::insertJacobsthalGroups(ItVec& main, ItVec& pend)
{
    int prevJacobsthal = jacobsthalNumber(1);
    // insertedNumbers only updates after all of the numbers from each group
    // has been inserted. Used to define the boundary for insertion
    int insertedNumbers = 0;
    for (int k = 2;; k++) {
        int currJacobsthal = jacobsthalNumber(k);
        int jacobsthalDiff = currJacobsthal - prevJacobsthal;
        // Break if remaining number of elements in pend is less than the jacobsthalDiff
        if (jacobsthalDiff > static_cast<int>(pend.size()))
            break;
        // pendIt is the end Iterator of the current group
        typename ItVec::iterator pendIt = next(pend.begin(), jacobsthalDiff - 1);
        // boundIt is the bound for the Binary Insertion in the main chain
        typename ItVec::iterator boundIt = next(main.begin(), currJacobsthal + insertedNumbers);
        int offset = 0;
        for (int nbrOfInsertions = 0; nbrOfInsertions < jacobsthalDiff; nbrOfInsertions++) {
            //upper_bound uses Binary Insertion, passing it the compare function overloads the comparator
            typename ItVec::iterator idx = std::upper_bound(main.begin(), boundIt, *pendIt, comp<Iterator>);
            typename ItVec::iterator inserted = main.insert(idx, *pendIt);
            pend.erase(pendIt); // Remove the inserted iterator from pend
            std::advance(pendIt, -1); // Move the iterator backwards
            offset += (inserted - main.begin()) == currJacobsthal + insertedNumbers;
            boundIt = next(main.begin(), currJacobsthal + insertedNumbers - offset);
        }
        prevJacobsthal = currJacobsthal;
        insertedNumbers += jacobsthalDiff;
    }
}

template<typename Iterator, typename ItVec>
void PmergeMe::insertRemainingPend(ItVec& main, ItVec& pend, bool isOdd)
{
    for (int i = pend.size() - 1; i >= 0; i--) {
        typename std::vector<Iterator>::iterator currPend = next(pend.begin(), i);
        typename std::vector<Iterator>::iterator currBound = next(main.begin(), main.size() - pend.size() + i + isOdd);
        typename std::vector<Iterator>::iterator idx = std::upper_bound(main.begin(), currBound, *currPend, comp<Iterator>);
        main.insert(idx, *currPend);
    }
}

template<typename Iterator, typename T, typename ItVec>
void PmergeMe::reconstructSortedContainer(T& container, ItVec& main, int groupSize)
{
    std::vector<int> copy;
    copy.reserve(container.size());
    for (typename std::vector<Iterator>::iterator it = main.begin(); it != main.end(); it++) {
        for (int i = 0; i < groupSize; i++) {
            Iterator pairStart = *it;
            std::advance(pairStart, -groupSize + i + 1);
            copy.insert(copy.end(), *pairStart);
        }
    }
    std::copy(copy.begin(), copy.end(), container.begin());
}

template<typename T>
void PmergeMe::printContents(T& container)
{
    typename T::iterator end = container.end();
    if (TRUNCATE && container.size() > 10)
        end = next(container.begin(), 4);

    typename T::iterator it = container.begin();
    while (it != end) {
        std::cout << *it;
        if (it != end)
            std::cout << " ";
        ++it;
    }

    if (TRUNCATE && end != container.end())
        std::cout << "[...]";
    std::cout << std::endl;
}

template<typename T>
void PmergeMe::swapElements(T it, int groupSize)
{
    T start = next(it, -groupSize + 1);
    T end = next(start, groupSize);
    while (start != end) {
        std::iter_swap(start, next(start, groupSize));
        start++;
    }
}

template<typename T>
T PmergeMe::next(T it, int steps)
{
    std::advance(it, steps);
    return it;
}

template<typename T>
bool PmergeMe::comp(T a, T b)
{
    _comparisons++;
    return *a < *b;
}
