#include "PmergeMe.hpp"

int main(int ac, char *av[])
{
    if (ac < 2) {
        std::cout << "Usage: ./PmergeMe <positive integers> ...\n";
        return 1;
    }

    PmergeMe PmergeMe;
    PmergeMe.initIntContainer(PmergeMe._vector, ++av);
    PmergeMe.initIntContainer(PmergeMe._list, av);
    PmergeMe.mergeInsertionSort(PmergeMe._vector, 1);
    PmergeMe.mergeInsertionSort(PmergeMe._list, 1);
    printContainer(PmergeMe._vector);
    printContainer(PmergeMe._list);

    return 0;
}
