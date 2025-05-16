#include "PmergeMe.hpp"

int main(int ac, char *av[])
{
    if (ac < 2) {
        std::cout << "Usage: ./PmergeMe <positive integers> ...\n";
        return 1;
    }

    PmergeMe PmergeMe;
    PmergeMe.initVector(++av);

    // std::vector<int>::iterator It = PmergeMe._vector.begin();
    // std::advance(It, 4);
    // std::cout << "After advance: " << *It << "\n";
    // std::advance(It, -2);
    // std::cout << "After neg advance: " << *It << "\n";

    // PmergeMe.printContainer(PmergeMe._vector);
    PmergeMe.mergeInsertionSort(PmergeMe._vector, 1);
    PmergeMe.printContainer(PmergeMe._vector);

    return 0;
}
