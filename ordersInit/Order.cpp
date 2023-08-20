#include <iostream>
#include "ordersInit/Order.h"

// The user will make the link between which order they own. <---!!!!!

Order::Order(int _orderId,
             std::string _timestamp,
             Type _orderType,
             std::string _product,
             double _price,
             double _amount)
    : orderId(_orderId),
      timestamp(_timestamp),
      type(_orderType),
      product(_product),
      price(_price),
      amount(_amount)
{
    
}

Type Order::OrderStringConversion(std::string orderString){
    if (orderString == "bid"){
        return Type::Bid;
    }
    if (orderString == "ask"){
        return Type::Ask;
    }
    return Type::Unknown; // Must handle a Unknown order Type
};

void Order::init(){
    
};

void Order::TestFunc(){
    std::cout << "This test comes from OrderInit." << std::endl;
};


