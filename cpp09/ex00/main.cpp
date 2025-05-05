#include "BitcoinExchange.hpp"

void BitcoinExchange::trim(std::string& str)
{
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) {
        str = "";
        return;
    }

    size_t last = str.find_last_not_of(" \t\r\n");
    str = str.substr(first, (last - first + 1));
}

bool BitcoinExchange::validateValue(std::string& valueStr, float* value)
{
    trim(valueStr);
    if (valueStr[0] == '\0') {
        std::cout << "Error: no number given.\n";
        return false;
    }
    if (valueStr[0] == '-') {
        std::cout << "Error: not a positive number.\n";
        return false;
    }

    char *endptr;
    *value = std::strtof(valueStr.c_str(), &endptr);
    while (*endptr && !std::isspace(*endptr))
        ++endptr;

    if (*endptr != '\0') {
        std::cout << "Error: bad input => " << valueStr << "\n";
        return false;
    }

    if (*value > 1000.0f) {
        std::cout << "Error: too large a number\n";
        return false;
    }

    return true;
}

std::map<std::string, float>::iterator BitcoinExchange::findClosestDate(
    std::map<std::string, float>& database, std::string& target)
{
    std::map<std::string, float>::iterator it = database.lower_bound(target);
    if ((it != database.end() && it->first == target) || it == database.begin())
        return it;
    return --it;
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

        std::string valueStr;
        float value;
        std::getline(iss, valueStr);
        if (!validateValue(valueStr, &value)) {
            continue ;
        }

        std::map<std::string, float>::iterator it = findClosestDate(_database, date);
        std::cout << date << " => " << value << " = " << value * it->second << "\n";
    }
}

int main()
{
    BitcoinExchange btc;

    btc._database = btc.loadDatabase("data.csv");
    btc.processInput("input.txt");
    // std::map<std::string, float> database = BitcoinExchange::loadDatabase("small-data.csv");
    // for (std::map<std::string, float>::iterator it = btc._database.begin(); it != btc._database.end(); ++it) {
    //     std::cout << "Date: " << it->first << " | Price: " << it->second << "\n";
    // }

    return 0;
}
