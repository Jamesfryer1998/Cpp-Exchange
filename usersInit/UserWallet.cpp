#include <usersInit/UserWallet.h>
#include <ordersInit/CSVReader.h>
#include <ordersInit/Order.h>
#include <ordersInit/JsonReader.h>

#include <iostream>
#include <filesystem>


Wallet::Wallet()
{

}

bool Wallet::insertCurrency(std::string type, double amount)
{
    try{
        double balance;
        if (amount < 0)
        {
            return false;
        }
        if (currencies.count(type) == 0)
        {
            balance = 0;
        }
        else
        {
            balance = currencies[type];
        }
        balance += amount;
        currencies[type] = balance;
        return true;
    }catch(const std::exception& e)
    {
        return false;
    }
}

bool Wallet::removeCurrency(std::string type, double amount)
{
    try{
        if (amount < 0)
        {
            return false;
        }
        if (currencies.count(type) == 0)
        {
            return false;
        }
        else
        {
            if (containsCurrency(type, amount))
            {
                currencies[type] -= amount;
                return true;
            }
            else
                return false;
        }
    }catch(const std::exception& e)
    {
        return false;
    }
}

bool Wallet::containsCurrency(std::string type, double amount)
{
    if (currencies.count(type) == 0)
    {
        return false;
    }
    else
        return currencies[type] >= amount;
}

void Wallet::showCurrencies()
{
    if(currencies.size() == 0){
        std::cout << "No currencies found on account" << std::endl;
    }

    for(auto curr: currencies){
        std::cout << curr.first << ": " << curr.second << std::endl;
    }
    std::cout << '\n';
}

Wallet Wallet::loadWallet(const std::string& userName){
    if(!walletExists())
    {
        Wallet emptyWallet;
        return emptyWallet;
    }
    else{
        std::string fileName = userName + "-wallet.json";
        JSONHandler jsonHandler(fileName);
        std::map<std::string, double> jsonData;

        if (jsonHandler.parse(jsonData)) {
            Wallet wallet;

            // Deposited currencies to wallet
            for (const auto& entry : jsonData) {
                wallet.insertCurrency(entry.first, entry.second);
            }

            // Print deposited currencies
            for (const auto& entry : currencies) {
                std::cout << "Currency: " << entry.first << ", Amount: " << entry.second << std::endl;
            }

            return wallet;
        }
    }

    Wallet emptyWallet;
    return emptyWallet;
}

void Wallet::saveWallet(const std::string& userName){
    // loop thorugh currencies and save to file
    std::string fileName = userName + "-wallet.json";
    JSONHandler jsonHandler(fileName);

    if (jsonHandler.saveToJson(currencies)) {
        std::cout << "Successfully saved to JSON." << std::endl;
    }
}

bool Wallet::walletExists(){
    std::string fileName = userName + "-wallet.json";
    std::string filePath = "usersInit/wallets/" + fileName;

    return std::filesystem::exists(filePath);   
}

// std::string Wallet::toString()
// {   
//     std::string currencyString;
//     for (std::pair<std::string, double> pair: currencies)
//     {
//         std::string currencyName = pair.first;
//         double currencyAmount = pair.second;
//         currencyString += currencyName + " : " + std::to_string(currencyAmount) + "\n";
//     }
//     return currencyString;
// }

// bool Wallet::fulfillOrder(OrderBookEntry order)
// {
//     std::vector<std::string> currs = CSVReader::tokenise(order.product, '/');
//     if (order.type == Order::Ask)
//     {
//         double amount = order.amount;
//         std::string currency = currs[0];
//         std::cout << "Wallet::fulfillOrder " << currency << " : " << amount << std::endl; 
//         return containsCurrency(currency, amount);
//     }
//     if (order.type == Order::Bid)
//     {
//         double amount = order.amount * order.price;
//         std::string currency = currs[1];
//         std::cout << "Wallet::fulfillOrder " << currency << " : " << amount << std::endl; 
//         return containsCurrency(currency, amount);
//     }
//     return false;
// }

// void Wallet::processSale(OrderBookEntry sale)
// {
//     std::vector<std::string> currs = CSVReader::tokenise(sale.product, '/');
//     if (sale.type == OrderBookType::asksale)
//     {
//         double outgoingAmount = sale.amount;
//         std::string outgoingCurrency = currs[0];
//         double incomingAmount = sale.amount * sale.price;
//         std::string incomingCurrency = currs[1];

//         currencies[incomingCurrency] += incomingAmount;
//         currencies[outgoingCurrency] -= outgoingAmount;
//     }
//     if (sale.type == OrderBookType::bidsale)
//     {
//         double incomingAmount = sale.amount;
//         std::string incomingCurrency = currs[0];
//         double outgoingAmount = sale.amount * sale.price;
//         std::string outgoingCurrency = currs[1];

//         currencies[incomingCurrency] += incomingAmount;
//         currencies[outgoingCurrency] -= outgoingAmount;
//     }
// }