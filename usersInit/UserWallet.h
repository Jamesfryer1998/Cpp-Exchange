#pragma once
#include <ordersInit/Order.h>
#include <string>
#include <map>

class Wallet
{
    public:
        Wallet();


        // Wallet Operations
        // std::string toString();
        // void processSale(Order sale);
        // bool fulfillOrder(Order order);
        bool removeCurrency(std::string, double amount);
        bool insertCurrency(std::string type, double amount);
        bool containsCurrency(std::string type, double amount);
        void showCurrencies();
        Wallet loadWallet(const std::string& userName);
        void saveWallet(const std::string& userName);

    private:
        // Variables
        std::map<std::string, double> currencies;
        std::string userName;

        bool walletExists();


};