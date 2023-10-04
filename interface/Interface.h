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

    private:
        int getUserInput();


};