#include "BitcoinExchange.hpp"

int main()
{
    BitcoinExchange btc;

    btc
    std::map<std::string, float> database = BitcoinExchange::loadDatabase("small-data.csv");
    for (std::map<std::string, float>::iterator it = btc._database.begin(); it != btc._database.end(); ++it) {
        std::cout << "Date: " << it->first << " | Price: " << it->second << "\n";
    }
    return 0;
}
