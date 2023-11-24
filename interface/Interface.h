#pragma once 
#include <iostream>
#include <ordersInit/OrderBook.h>


class Interface{
    public:
        Interface();
        void Init(OrderBook orderBook);

        static void printMenu();
        static void printStats(std::string type);
        static void printUserStats();
        static void printExchangeStats();
        void invalidChoice();
        void processUserInput(int userInput);
        void ExchangeStatus();

    private:
        int getUserInput();
        void makeOrder();

        OrderBook orderBook;

};