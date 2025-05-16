#include "PmergeMe.hpp"
#include <sys/time.h>
#include <iomanip>

int main(int ac, char *av[])
{
    if (ac < 2) {
        std::cerr << "Usage: ./PmergeMe <positive integers> ...\n";
        return 1;
    }

    try {
        PmergeMe PmergeMe;
        PmergeMe.compareContainers(ac, ++av);
    }
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}
