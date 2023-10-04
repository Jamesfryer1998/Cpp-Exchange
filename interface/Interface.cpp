#include <iostream>
#include <string>
#include <interface/Interface.h>

Interface::Interface(){

}

void Interface::Init(){

}

void Interface::printMenu()
{
    system("clear");
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
}

void Interface::invalidChoice(){
    std::cout << "Invalid Choice. Please seletct a number from 1-6." << std::endl;
}

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

}

void Interface::printStats(std::string type){
    if (type == "User")
    {
        Interface::printUserStats();
    }
    else if (type == "Exchange")
    {
        Interface::printExchangeStats();
    }
}

void Interface::printUserStats(){
    std::cout << "This is the Users Stats" << std::endl;
}

void Interface::printExchangeStats(){
    std::cout << "This is the Exchange Stats" << std::endl;
}

