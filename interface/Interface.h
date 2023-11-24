#pragma once 
#include <iostream>


class Interface{
    public:
        Interface();
        void Init();

        static void printMenu();
        static void printStats(std::string type);
        static void printUserStats();
        static void printExchangeStats();
        void invalidChoice();
        void processUserInput(int userInput);
        void ExchangeStatus();

    private:
        int getUserInput();
        void makeAsk();
        void makeBid();

};