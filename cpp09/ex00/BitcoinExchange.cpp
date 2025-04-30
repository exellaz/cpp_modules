#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
    : _database()
{

}

BitcoinExchange::~BitcoinExchange()
{

}

bool BitcoinExchange::isValidDate(const std::string& date)
{
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
        std::cout << "Not a valid date\n";
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

std::map<std::string, float> BitcoinExchange::loadDatabase(const std::string& filename)
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
        std::string date;
        float price;
        if (!parseLine(line, date, price))
            std::cerr << "Error: " << line << "\n";
        database[date] = price;
        // std::cout << "Date: " << date << " | Price: " << price << "\n";
        //Parse line function to get date and price
    }
    return database;
}
