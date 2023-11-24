#pragma once 

#include "Order.h"
#include <vector>
#include <string>

class CSVReader{

    public:
        CSVReader();

        // CSV Input Operations
        static std::unordered_map<int, Order> readCSV(std::string fileName);
        static std::vector<std::string> tokenise(std::string csvline, char seperator);
        static Order stringToOBE(std::string timestamp,
                                 std::string product, 
                                 Type type,
                                 std::string price,
                                 std::string amount);

        static std::string toUpperCase(std::string string);
        static std::string productFormat(std::string prod1, std::string prod2);

    private:
        Order csvStringToOBE(std::vector<std::string> inputString);
};