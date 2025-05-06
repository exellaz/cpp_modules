#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
    : _database()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
    : _database(src._database)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
    if (this != &src)
        this->_database = src._database;

    return *this;
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::map<std::string, float> database;

    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file\n";
        return ;
    }

    std::string header;
    std::getline(file, header);
    if (header != "date,exchange_rate") {
        std::cerr << "Error: incorrect header\n";
        return ;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::string date;
        float price;
        if (!parseLine(line, date, price)) {
            std::cerr << "Error: invalid line format: `" << line << "`\n";
            continue;
        }
        database[date] = price;
    }
    _database = database;
}

void BitcoinExchange::processInput(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open input file\n";
        return ;
    }

    std::string header;
    std::getline(file, header);
    if (header != "date | value") {
        std::cout << header << "\n";
        std::cerr << "Error: incorrect header\n";
        return ;
    }

    std::string line;
    while (std::getline(file, line)) {
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
    while (*endptr && std::isspace(*endptr))
        ++endptr;

    if (*endptr != '\0') {
        std::cout << "Error: bad input => " << valueStr << "\n";
        return false;
    }
    if (*value > 1000.0f) {
        std::cout << "Error: too large a number.\n";
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

bool BitcoinExchange::isValidDate(std::string& date)
{
    trim(date);
    if (date.length() != 10)
        return false;

    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7)
            continue ;
        if (!std::isdigit(date[i]))
            return false;
    }

    int year, month, day;
    char sep1, sep2;
    std::istringstream iss(date);
    iss >> year >> sep1 >> month >> sep2 >> day;

    if (iss.fail() || sep1 != '-' || sep2 != '-')
        return false;
    if (month < 1 || month > 12)
        return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
        return false;

    return true;
}

bool BitcoinExchange::parseLine(const std::string& line, std::string& date, float& price)
{
    std::istringstream ss(line);
    std::getline(ss, date, ',');
    if (!isValidDate(date)) {
        return false;
    }

    std::string priceStr;
    std::getline(ss, priceStr);
    std::istringstream priceStream(priceStr);
    priceStream >> price;
    if (priceStream.fail())
        return false;

    return true;
}
