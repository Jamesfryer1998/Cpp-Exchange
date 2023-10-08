#include <run/ExchangeMain.h>
#include <interface/Interface.h>

ExchangeMain::ExchangeMain(){

}

void ExchangeMain::init(){
    interface.Init();
    orderbook.loadOrderBook("20200317.csv");
}