#include <iostream>
#include <string>
#include <interface/Interface.h>
#include <ordersInit/Order.h>
#include <ordersInit/OrderBook.h>
#include <ordersInit/CSVReader.h>
#include <exchangeInit/MatchingSystem.h>

Interface::Interface(){
    
};

void Interface::Init(OrderBook orderBook){
    Interface::orderBook = orderBook;
    system("clear");
    int userInput;
    printMenu();

    while (true){
        userInput = getUserInput();
        processUserInput(userInput);
    }
};

void Interface::printMenu()
{
    std::cout << "Welcome to the Fastest C++ Exchange out there!" << std::endl;
    std::cout << "Please choose from one of the options below:" << std::endl;
    std::cout << "\n==================" << std::endl;
    std::cout << "1: Account Stats" << std::endl; 
    std::cout << "2: Exchange Stats" << std::endl; 
    std::cout << "3: Submit an Order" << std::endl; 
    std::cout << "4: Wallet Stats" << std::endl; 
    std::cout << "5: Exchange Status" << std::endl; 
    std::cout << "==================\n" << std::endl;
    // std::cout << "Current time: " << currentTime << std::endl;
};

int Interface::getUserInput(){
    int userInput;
    std::string line;
    std::getline(std::cin, line);
    
    try{
        userInput = std::stoi(line);
    }catch(const std::exception& e)
    {
        throw(e);
    }

    std::cout << "\nOption: " << userInput << " Selected." << std::endl;
    return userInput;

};

void Interface::printStats(std::string type){
    if (type == "User")
    {
        Interface::printUserStats();
    }
    else if (type == "Exchange")
    {
        Interface::printExchangeStats();
    }
};

void Interface::printUserStats(){
    std::cout << "This is the Users Stats." << std::endl;
    std::cout << "Username: X" << std::endl;
    std::cout << "Wallet amount: X" << std::endl;
    std::cout << "Trade count: X" << std::endl;
};

void Interface::printExchangeStats(){
    std::cout << "This is the Exchange Stats." << std::endl;
    std::cout << "Number of Users: X" << std::endl;
    std::cout << "OrderBook size: X" << std::endl;
    std::cout << "OrderBook Data Range: X" << std::endl;
    std::cout << "Total Trade count: X" << std::endl;
};

void Interface::ExchangeStatus(){
    std::cout << "Info about the Exchange (uptime etc, will go here)" << std::endl;
};

void Interface::invalidChoice(){
    std::cout << "Invalid Choice. Please seletct a number from 1-5." << std::endl;
};

void Interface::makeOrder() {
    std::string to;
    std::string from;
    std::string product;
    std::string orderTypeInput;
    Type orderType = Type::Unknown;
    std::string prodAmount;
    std::string prodPrice;

    std::cout << "ASK - 1" << std::endl;
    std::cout << "BID - 2" << std::endl;
    std::cout << "\nWould you like to make a ASK or BID." << std::endl;
    std::getline(std::cin, orderTypeInput);

    try{
        if(std::stoi(orderTypeInput) == 1)
        {
            orderType = Type::Ask;       // User enters ask
        }
        else if (std::stoi(orderTypeInput) == 2)
        {
            orderType = Type::Bid;      // User enters bid
        }
        else
        {
            makeOrder();                // User enters undefined
        };

    }catch(const std::exception& e)
    {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    std::cout << "\nPlease enter the details below:" << std::endl;

    std::cout << "To symbol: ";
    std::getline(std::cin, to);
    
    std::cout << "From symbol: ";
    std::getline(std::cin, from);

    product = CSVReader::productFormat(to, from);

    if(!orderBook.lookupProduct(product)) {
        std::cout << product << " not found in order book." << std::endl;
        makeOrder();
    }

    std::cout << "Product Amount: ";
    std::getline(std::cin, prodAmount);

    std::cout << "Price: ";
    std::getline(std::cin, prodPrice);

    std::cout << "Matcing your order, please wait..." << std::endl;

    MatchingSystem::OrderEnteredByUser(
        orderBook.getCurrentOrderId(),
        orderType,
        product.c_str(),
        std::stod(prodPrice),
        std::stod(prodAmount)
    );

};

void Interface::processUserInput(int userInput){
    if (userInput == 0) // Invalid input
    {
        invalidChoice();
    }

    if (userInput == 1)
    {
        printStats("User");
    }

    if (userInput == 2)
    {
        printStats("Exchange");
    }

    if (userInput == 3)
    {
        makeOrder();
    }

    if (userInput == 4)
    {
        // MerkelMain::walletState();
    }

    if (userInput == 5)
    {
        ExchangeStatus();
    }

    if (userInput > 6) // Invalid input
    {
        invalidChoice();
    }
};