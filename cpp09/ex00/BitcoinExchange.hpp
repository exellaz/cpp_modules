#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <fstream>
# include <cstdlib>
# include <map>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& src);
        BitcoinExchange& operator=(const BitcoinExchange& src);

        void loadDatabase(const std::string& filename);
        void processInput(const std::string& filename);

    private:
        std::map<std::string, float> _database;
        static bool isValidDate(std::string& date);
        static bool parseLine(const std::string& line, std::string& date, float& price);
        static void trim(std::string& str);
        static bool validateValue(std::string& valueStr, float* value);
        static std::map<std::string, float>::iterator findClosestDate(
            std::map<std::string, float>& database, std::string& target);
};

#endif
