#include "PmergeMe.hpp"

int PmergeMe::_comparisons = 0;

void PmergeMe::compareContainers(int ac, char **av)
{
    initIntContainer(_vector, av);
    double vecStart = getMicroseconds();
    mergeInsertionSort(_vector, 1);
    double vecEnd = getMicroseconds();

    initIntContainer(_list, av);
    double listStart = getMicroseconds();
    mergeInsertionSort(_list, 1);
    double listEnd = getMicroseconds();

    std::cout << "Before: ";
    printBeforeSort(ac, av);
    std::cout << "After:  ";
    printContents(_vector);

    std::cout << std::fixed;
    std::cout << "Time to process range of " << _vector.size() \
        << " elements with std::vector : " << vecEnd - vecStart << " µs\n";
    std::cout << "Time to process range of " << _list.size() \
        << " elements with std::list   : " << listEnd - listStart << " µs\n\n";

    std::cout << "Number of comparisons: " << _comparisons / 2 << "\n";
    std::cout << "Theoretical max comparisons: " << getTheoreticalMax(ac - 1) << "\n";
}

void PmergeMe::printBeforeSort(int ac, char **av)
{
    int i = 0;
    int max = ac - 1;

    if (max > 10 && TRUNCATE)
        max = 4;

    while (i < max) {
        std::cout << std::atoi(av[i]);
        if (i != max)
            std::cout << " ";
        ++i;
    }
    if (TRUNCATE && max != ac - 1)
        std::cout << "[...]";
    std::cout << "\n";
}

// Measures in nanoseconds but returns microseconds as a double
double PmergeMe::getMicroseconds()
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return static_cast<double>(ts.tv_sec) * 1e6 + static_cast<double>(ts.tv_nsec) / 1e3;
}

bool PmergeMe::isPositiveInteger(const std::string& str)
{
    if (str.empty())
        return false;

    for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

void PmergeMe::trim(std::string& str)
{
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) {
        str = "";
        return;
    }

    size_t last = str.find_last_not_of(" \t\r\n");
    str = str.substr(first, (last - first + 1));
}

int PmergeMe::jacobsthalNumber(int n)
{
    return round((std::pow(2, n + 1) + std::pow(-1, n)) / 3);
}

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& src)
    : _vector(src._vector), _list(src._list)
{
    _comparisons = src._comparisons;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
    if (this != &src) {
        _vector = src._vector;
        _list = src._list;
        _comparisons = src._comparisons;
    }
    return *this;
}

long PmergeMe::getTheoreticalMax(long n)
{
    long sum = 0;
    for (long k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<long>(ceil(log2(value)));
    }
    return sum;
}
