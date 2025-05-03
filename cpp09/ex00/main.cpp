#include "BitcoinExchange.hpp"

void trim(std::string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos)
        str = "";

    size_t last = str.find_last_not_of(" \t\r\n");
    str = str.substr(first, (last - first + 1));
}

bool validateValue(std::string& date, std::string& value)
{
    trim(value);
    if (value[0] == '-') {
        std::cout << "Error: not a positive number.\n";
        return false;
    }

    (void)date;
    return true;
}

void BitcoinExchange::processInput(const std::string& filename)
{
    std::ifstream ss(filename.c_str());

    std::string header;
    std::getline(ss, header);
    if (header != "date | value") {
        std::cout << header << "\n";
        std::cerr << "Error: incorrect header\n";
        return ;
    }

    std::string line;
    while (std::getline(ss, line)) {
        std::istringstream iss(line);
        std::string date;
        std::getline(iss, date, '|');
        if (!isValidDate(date)) {
            std::cout << "Error: bad input => " << date << "\n";
            continue ;
        }

        std::string value;
        std::getline(iss, value);
        if (!validateValue(date, value)) {
            continue ;
        }
        std::cout << date << " => " << value << " = " << std::atoi(value.c_str()) * _database[date] << "\n";
    }
}

int main()
{
    BitcoinExchange btc;

    btc._database = btc.loadDatabase("small-data.csv");
    btc.processInput("input.txt");
    // std::map<std::string, float> database = BitcoinExchange::loadDatabase("small-data.csv");
    for (std::map<std::string, float>::iterator it = btc._database.begin(); it != btc._database.end(); ++it) {
        std::cout << "Date: " << it->first << " | Price: " << it->second << "\n";
    }

    return 0;
}
