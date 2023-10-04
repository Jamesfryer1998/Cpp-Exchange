#include <run/ExchangeMain.h>
#include <interface/Interface.h>

ExchangeMain::ExchangeMain(){

}

void ExchangeMain::init(){
    Interface::printMenu();
    Interface::printStats("Exchange");
}