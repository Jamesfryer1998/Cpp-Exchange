#include <iostream>
#include <string>
#include <interface/Interface.h>
#include <ordersInit/OrderBook.h>
#include <ordersInit/CSVReader.h>
#include <exchangeInit/MatchingSystem.h>
#include <usersInit/UserWallet.h>

Interface::Interface(){
    
};

void Interface::Init(OrderBook orderBook){
    system("clear");
    std::cout << "Welcome to the Fastest C++ Exchange out there!" << std::endl;
    Interface::orderBook = orderBook;
    int userInput;
    printMenu();

    while (true){
        userInput = getUserInput();
        processUserInput(userInput);
    }
};

void Interface::printMenu()
{
    std::cout << "Please choose from one of the options below:" << std::endl;
    std::cout << "\n==================" << std::endl;
    std::cout << "1: Account Stats" << std::endl; 
    std::cout << "2: Exchange Stats" << std::endl; 
    std::cout << "3: Submit an Order" << std::endl; 
    std::cout << "4: Wallet Stats" << std::endl; 
    std::cout << "5: Exchange Status" << std::endl; 
    std::cout << "==================\n" << std::endl;
    // std::cout << "Current time: " << currentTime << std::endl;
};

int Interface::getUserInput(){
    int userInput;
    std::string line;
    std::getline(std::cin, line);
    
    try{
        userInput = std::stoi(line);
    }catch(const std::exception& e)
    {
        throw(e);
    }

    std::cout << "Option: " << userInput << " Selected.\n" << std::endl;
    return userInput;

};

void Interface::printStats(std::string type){
    if (type == "User")
    {
        Interface::printUserStats();
    }
    else if (type == "Exchange")
    {
        Interface::printExchangeStats();
    }
};

void Interface::printUserStats(){
    std::cout << "This is the Users Stats." << std::endl;
    std::cout << "Username: X" << std::endl;
    std::cout << "Wallet amount: X" << std::endl;
    std::cout << "Trade count: X" << std::endl;
};

void Interface::printExchangeStats(){
    std::cout << "This is the Exchange Stats." << std::endl;
    std::cout << "Number of Users: X" << std::endl;
    std::cout << "OrderBook size: X" << std::endl;
    std::cout << "OrderBook Data Range: X" << std::endl;
    std::cout << "Total Trade count: X" << std::endl;
};

void Interface::exchangeStatus(){
    std::cout << "Info about the Exchange (uptime etc, will go here)" << std::endl;
};

void Interface::invalidChoice(){
    std::cout << "Invalid Choice. Please seletct a number from 1-5." << std::endl;
};

void Interface::makeOrder() {
    displayOrderOptions();
    getUserOrderType();

    try {
        if (std::stoi(orderTypeInput) == 1) {
            orderType = Type::Ask;
        } else if (std::stoi(orderTypeInput) == 2) {
            orderType = Type::Bid;
        } else {
            handleInvalidOrderType();
            return;
        }
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return;
    }

    getOrderDetails();

    if (!orderBook.lookupProduct(product)) {
        handleInvalidProduct();
        return;
    }

    processOrder();
}

void Interface::displayOrderOptions() {
    std::cout << "\nASK - 1" << std::endl;
    std::cout << "BID - 2" << std::endl;
    std::cout << "\nWould you like to make an ASK or BID." << std::endl;
    std::getline(std::cin, orderTypeInput);
}

void Interface::getToSymbol(){
    std::cout << "To symbol: ";
    std::getline(std::cin, to);
}

void Interface::getFromSymbol(){
    std::cout << "From symbol: ";
    std::getline(std::cin, from);
}

void Interface::getUserOrderType() {
    std::cout << "\nPlease enter the details below:" << std::endl;
    getToSymbol();
    getFromSymbol();

    product = CSVReader::productFormat(to, from);
}

void Interface::getProductAmount(){
    std::cout << "Product Amount: ";
    std::getline(std::cin, prodAmount);
}

void Interface::getProductPrice(){
    std::cout << "Product Price: ";
    std::getline(std::cin, prodAmount);
}

void Interface::getOrderDetails() {
    getProductAmount();
    getProductPrice();

    std::cout << "Matching your order, please wait..." << std::endl;
}

void Interface::handleInvalidOrderType() {
    std::cout << "Invalid order type. Please enter 1 for ASK or 2 for BID." << std::endl;
    makeOrder(); // Reattempt order
}

void Interface::handleInvalidProduct() {
    std::cout << product << " not found in order book." << std::endl;
    makeOrder(); // Reattempt order
}

void Interface::processOrder() {
    MatchingSystem::OrderEnteredByUser(
        orderBook.getCurrentOrderId(),
        orderType,
        product.c_str(),
        std::stod(prodPrice),
        std::stod(prodAmount)
    );
}


// void Interface::makeOrder() {
//     std::cout << "\nASK - 1" << std::endl;
//     std::cout << "BID - 2" << std::endl;
//     std::cout << "\nWould you like to make a ASK or BID." << std::endl;
//     std::getline(std::cin, orderTypeInput);

//     try{
//         if(std::stoi(orderTypeInput) == 1)
//         {
//             orderType = Type::Ask;      // User enters ask
//         }
//         else if (std::stoi(orderTypeInput) == 2)
//         {
//             orderType = Type::Bid;      // User enters bid
//         }
//         else
//         {
//             makeOrder();                // User enters undefined
//         };

//     }catch(const std::exception& e)
//     {
//         std::cerr << "An error occurred: " << e.what() << std::endl;
//     }

//     std::cout << "\nPlease enter the details below:" << std::endl;

//     std::cout << "To symbol: ";
//     std::getline(std::cin, to);
    
//     std::cout << "From symbol: ";
//     std::getline(std::cin, from);

//     product = CSVReader::productFormat(to, from);

//     if(!orderBook.lookupProduct(product)) {
//         std::cout << product << " not found in order book." << std::endl;
//         makeOrder();
//     }

//     std::cout << "Product Amount: ";
//     std::getline(std::cin, prodAmount);

//     std::cout << "Price: ";
//     std::getline(std::cin, prodPrice);

//     std::cout << "Matcing your order, please wait..." << std::endl;

//     MatchingSystem::OrderEnteredByUser(
//         orderBook.getCurrentOrderId(),
//         orderType,
//         product.c_str(),
//         std::stod(prodPrice),
//         std::stod(prodAmount)
//     );
// };

void Interface::walletState(){
    std::cout << "\n===================================" << std::endl;
    std::cout << "Welcome to your Wallet." << std::endl;
    std::cout << "Please select one of the following: " << std::endl;
    std::cout << "1. Currencies Amounts" << std::endl;
    std::cout << "2. Deposit" << std::endl;
    std::cout << "3. Withdraw" << std::endl;
    std::cout << "4. Save Wallet" << std::endl;
    std::cout << "4. Main Menu" << std::endl;
    std::cout << "=====================================\n" << std::endl;

    wallet = wallet.loadWallet("James01");
    int userInput = getUserInput();

    switch (userInput) {
        case 1:
            wallet.showCurrencies();
            break;
        case 2:
            getToSymbol();
            getProductAmount();
            wallet.insertCurrency(to, std::stod(prodAmount));
            break;
        case 3:
            getFromSymbol();
            getProductAmount();
            wallet.removeCurrency(from, std::stod(prodAmount));
            break;
        case 4:
            wallet.saveWallet("James01");
        case 5:
            printMenu();            
    }

    printMenu();
};

void Interface::processUserInput(int userInput){
    switch (userInput) {
        case 0:
            invalidChoice();
            break;
        case 1:
            printStats("User");
            break;
        case 2:
            printStats("Exchange");
            break;
        case 3:
            makeOrder();
            break;
        case 4:
            walletState();
            break;
        case 5:
            exchangeStatus();
            break;
        case 6:
            invalidChoice();
            break;
    }
};