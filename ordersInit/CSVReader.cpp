#include "CSVReader.h"
#include "Order.h"
#include "OrderBook.h"

#include <iostream>
#include <fstream>

CSVReader::CSVReader()
{

}

std::vector<Order> CSVReader::readCSV(std::string fileName)
{
    std::vector<Order> entries;
    std::ifstream csvFile{fileName};
    std::string line;
    std::vector<std::string> tokens;
    CSVReader csv;

    
    if (csvFile.is_open())
    {
        std::cout << "File open." << std::endl;
        while (std::getline(csvFile, line))
        {
            try{
                Order OBE = csv.csvStringToOBE(tokenise(line, ','));
                entries.push_back(OBE);
            }catch(const std::exception& e)
            {
                // std::cout << "CSVReader::readCSV bad data processed"  << std::endl;
            }
        }
    }

    std::cout << "CSVReader::readCSV read" << entries.size() << "files" << std::endl;
    return entries;
}

std::vector<std::string> CSVReader::tokenise(std::string csvLine, char separator)
{
    std::vector<std::string> tokens;
    
    // double start, end;
    std::string::size_type start, end;
    std::string token;
    start = csvLine.find_first_not_of(separator, 0);

    do{
        end = csvLine.find_first_of(separator, start);
        if (start == csvLine.length() || start == end) break;
        if (end >= 0 ) token = csvLine.substr(start, end - start);
        else token = csvLine.substr(start, csvLine.length() - start);
        tokens.push_back(token);
        start = end + 1;
    }while(end != std::string::npos);

    return tokens;
}

Order CSVReader::csvStringToOBE(std::vector<std::string> tokens)
{
    double price, amount;

    if (tokens.size() != 5) 
    {
        throw std::exception{};
    }
    try{
        std::string timestamp = tokens[0];
        std::string product = tokens[1];
        std::string orderType = tokens[2];
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
    }catch(const std::exception& e)
    {
        std::cout << "Bad data." << std::endl;
        throw;
    }
    // Get current orderId
    int currentOrderId = OrderBook::getCurrentOrderId();

    // Update orderId + 1
    OrderBook::updateCurrentOrderId(currentOrderId);

    Order OBE{  currentOrderId,                          // orderId
                tokens[0],                               // timestamp
                Order::OrderStringConversion(tokens[2]), // Type 
                tokens[1],                               // product
                price,                                   // price
                amount  };                               // amount
    return OBE;
}

Order CSVReader::stringToOBE(std::string timestamp,
                             std::string product, 
                             Type type,
                             std::string priceString,
                             std::string amountString)
{
    double price, amount;
    try{
        price = std::stod(priceString);
        amount = std::stod(amountString);
    }catch(const std::exception& e)
    {
        std::cout << "CSVReader::csvStringToOBE Bad data." << std::endl;
        throw;
    }

    // Get current orderId
    int currentOrderId = OrderBook::getCurrentOrderId();

    // Update orderId + 1
    // This could be optimised, just update the orderId by the length of the CSV at the end...
    OrderBook::updateCurrentOrderId(currentOrderId);

    Order OBE{  currentOrderId,
                timestamp,
                type,
                product,
                price,
                amount  };
    return OBE;
}
