#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <fstream>
# include <cstdlib>
# include <map>

void trim(std::string& str);
class BitcoinExchange
{
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        std::map<std::string, float> loadDatabase(const std::string& filename);
        void processInput(const std::string& filename);
        std::map<std::string, float> _database;


    private:
        static bool isValidDate(std::string& date);
        static bool parseLine(const std::string& line, std::string& date, float& price);
};

#endif
