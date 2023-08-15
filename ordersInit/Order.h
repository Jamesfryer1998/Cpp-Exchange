#pragma once
#include <iostream>
#include <vector>

// Defining Types of Orders
enum class Type {
    Buy,
    Sell,
    Unknown
};

class Order
{
    public:
        Order( std::string _timestamp,
               Type _orderType,
               std::string _product,
               std::string _user,
               double _price,
               double _amount
        );

        // Methods
        void init();
        Type OrderStringConversion(std::string orderString);

        // Testing Functions
        void TestFunc();

        // Variables
        std::string timestamp;
        Type type;
        std::string product;
        std::string user;
        double price;
        double amount;

    private:

};