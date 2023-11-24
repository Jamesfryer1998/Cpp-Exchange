#include <iostream>
#include <string>
#include <interface/Interface.h>
#include <ordersInit/CSVReader.h>
#include <exchangeInit/MatchingSystem.h>

Interface::Interface(){
    
};

void Interface::Init(){
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
    std::cout << "3: Make A Ask" << std::endl; 
    std::cout << "4: Make A Bid" << std::endl; 
    std::cout << "5: Wallet" << std::endl; 
    std::cout << "6: Exchange Status" << std::endl; 
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
    std::cout << "Invalid Choice. Please seletct a number from 1-6." << std::endl;
};

void Interface::makeAsk() {
    std::string to;
    std::string from;
    std::string correct;
    std::string product;
    
    std::cout << "\nTo make an Ask enter the details below:" << std::endl;
    
    // Prompt for "To" and "From" on the same line
    std::cout << "To: ";
    std::getline(std::cin, to);
    
    std::cout << "From: ";
    std::getline(std::cin, from);

    product = CSVReader::productFormat(
        CSVReader::toUpperCase(to),
        CSVReader::toUpperCase(from)
    );

    std::cout << "Is " << product << " correct? [y/n]" << std::endl;
    std::getline(std::cin, correct);

    // do a product check
    // This will involve the order book,

    if(correct == "y")
    {
        // proceed to make a Ask using the matching system
        std::cout << "Matcing your order, please wait..." << std::endl;
    }
    else{ makeAsk(); } // Recursively restart the process
};

void Interface::makeBid(){
    
};

void Interface::processUserInput(int userInput){
    if (userInput == 0) // bad input
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
        makeAsk();
    }

    if (userInput == 4)
    {
        makeBid();
    }

    if (userInput == 5)
    {
        // MerkelMain::walletState();
    }

    if (userInput == 6)
    {
        ExchangeStatus();
    }

    if (userInput > 7) // bad input
    {
        invalidChoice();
    }
};