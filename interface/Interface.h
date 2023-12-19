#pragma once 
#include <iostream>
#include <ordersInit/OrderBook.h>
#include <ordersInit/Order.h>
#include <usersInit/UserWallet.h>


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
        void exchangeStatus();
        void walletState();
        void processOrder();

    
    private:
        int getUserInput();
        void makeOrder();
        void displayOrderOptions();
        void getUserOrderType();
        void getToSymbol();
        void getFromSymbol();
        void getProductAmount();
        void getProductPrice();
        void handleInvalidOrderType();
        void handleInvalidProduct();
        void getOrderDetails();


        OrderBook orderBook;
        Wallet wallet;

        std::string to;
        std::string from;
        std::string product;
        std::string orderTypeInput;
        Type orderType = Type::Unknown;
        std::string prodAmount;
        std::string prodPrice;

};