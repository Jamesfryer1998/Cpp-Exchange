#pragma once 

#include "Order.h"
#include <vector>

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

    private:
        Order csvStringToOBE(std::vector<std::string> inputString);
};