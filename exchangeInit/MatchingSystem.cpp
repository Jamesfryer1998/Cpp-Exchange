#include <exchangeInit/MatchingSystem.h>
#include <interface/Interface.h>


MatchingSystem::MatchingSystem(){

}

void MatchingSystem::OrderEnteredByUser(
    int currentOrderId,
    Type orderType,
    std::string product,
    double price,
    double amount){

        Order OBE{
            currentOrderId,
            getCurrentTimestamp(),
            orderType,
            product,
            price,
            amount
        };
};

std::string MatchingSystem::getCurrentTimestamp(){
    return "test";
}