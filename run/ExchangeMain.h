#pragma once 

#include <ordersInit/CSVReader.h>
#include <ordersInit/OrderBook.h>
#include <interface/Interface.h>

class ExchangeMain{
    public:
        ExchangeMain();
        void init();

    private:
        OrderBook orderbook;
        Interface interface;

};
