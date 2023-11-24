#include <run/ExchangeMain.h>
#include <interface/Interface.h>


ExchangeMain::ExchangeMain(){

};

void ExchangeMain::init(){
    orderbook.loadOrderBook("20200317.csv");
    interface.Init(orderbook);
};