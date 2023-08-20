#pragma once
#include <iostream>
#include <vector>

// Defining Types of Orders
enum class Type {
    Bid,
    Ask,
    Unknown
};

class Order
{
    public:
        Order( int orderId,
               std::string _timestamp,
               Type _orderType,
               std::string _product,
               double _price,
               double _amount
        );

        // Methods
        void init();
        static Type OrderStringConversion(std::string orderString);

        // Testing Functions
        void TestFunc();

        // Variables
        int orderId;
        std::string timestamp;
        Type type;
        std::string product;
        double price;
        double amount;
};