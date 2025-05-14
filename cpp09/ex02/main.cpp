#include "PmergeMe.hpp"

int main(int ac, char *av[])
{
    if (ac < 2) {
        std::cout << "Usage: ./PmergeMe <positive integers> ...\n";
        return 1;
    }
    PmergeMe PmergeMe;
    PmergeMe.initVector(++av);
    PmergeMe.printContainer(PmergeMe._vector);
    PmergeMe.mergeInsertionSort(PmergeMe._vector, 1);
    PmergeMe.printContainer(PmergeMe._vector);
    return 0;
}
