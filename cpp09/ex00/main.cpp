#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>\n";
        return 1;
    }

    BitcoinExchange btc;
    btc.loadDatabase("data.csv");
    btc.processInput(argv[1]);
    return 0;
}
