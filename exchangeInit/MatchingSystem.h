#pragma once 
#include <iostream>
#include <ordersInit/Order.h>
#include <ordersInit/OrderBook.h>


class MatchingSystem{
    public:
        MatchingSystem();
        static void OrderEnteredByUser(
            int currentOrderId,
            Type orderType,
            std::string product,
            double price,
            double amount
        );

        static std::string getCurrentTimestamp();

    private:
        Order OBE;

};