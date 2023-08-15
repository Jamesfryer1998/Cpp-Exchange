#include <iostream>
#include <ordersInit/Order.h>

Order::Order(
    std::string _timestamp,
    Type _orderType,
    std::string _product,
    std::string _user,
    double _price,
    double _amount)

: timestamp(_timestamp),
  type(_orderType),
  product(_product),
  user(_user),
  price(_price),
  amount(_amount)
{

};

Type Order::OrderStringConversion(std::string orderString){
    if (orderString == "bid"){
        return Type::Buy;
    }
    if (orderString == "ask"){
        return Type::Sell;
    }
    return Type::Unknown; // Must handle a Unknown order Type
};

void Order::init(){
    
};

void Order::TestFunc(){
    std::cout << "This test comes from OrderInit." << std::endl;
};


