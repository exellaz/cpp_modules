#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>

std::map<std::string, float> loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    std::map<std::string, float> database;

    if (!file.is_open()) {
        std::cerr << "Error: could not open database file\n";
        return database;
    }

    std::string line;
    std::getline(file, line); // Skip file header
    while (std::getline(file, line)) {
        //Parse line function to get date and price
    }

}

int main()
{
    std::map<std::string, float> bitcoinPrices = loadDatabase()
}