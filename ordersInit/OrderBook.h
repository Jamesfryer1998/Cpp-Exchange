#pragma once

#include "ordersInit/Order.h"
#include <set>

class PriceLevel{
    public:
        double price;
        std::vector<Order*> orders;
};


class OrderBook
{
    public:
        OrderBook();

        // OrderBook Methods
        void loadOrderBook(std::string fileName);
        static void insertOrder(const Order& order, double price, Type type); // If type == sell/buy
        static void updateOrder(int orderId, double newProductAmount);
        static void deleteOrder(int orderId);
        Order* lookupOrder(int orderId);
        void updateProductList();
        bool lookupProduct(std::string);

        // Matching system
        std::vector<Order> getMatchingOrders(const Order& order) const;

        // DECIDE ON THE STRUCTURE OF THE ORDERBOOK
        static std::unordered_map<int, Order> orders;
        std::vector<std::string> productList; // List is all products
        static std::vector<PriceLevel> bidLevels; // Buy
        static std::vector<PriceLevel> askLevels; // Sell
        std::unordered_map<int, int> userOrderReference;

        // Getter
        static int getCurrentOrderId(){
            return currentOrderId;
        }

        static double getHighPrice(const std::vector<PriceLevel>& levels) {
            double highPrice = std::numeric_limits<double>::min();

            for (const auto& level : levels) {
                for (const auto& order : level.orders) {
                    double price = order->price;
                    highPrice = std::max(highPrice, price);
                }
            }

            return highPrice;
        }

        static double getLowPrice(const std::vector<PriceLevel>& levels) {
            double lowPrice = std::numeric_limits<double>::max();

            for (const auto& level : levels) {
                for (const auto& order : level.orders) {
                    double price = order->price;
                    lowPrice = std::min(lowPrice, price);
                }
            }

            return lowPrice;
        }

        static double getAvgPrice(const std::vector<PriceLevel>& levels) {
            if (levels.empty()) {
                return 0.0; // Avoid division by zero
            }

            double sum = 0.0;
            int numOrders = 0;

            for (const auto& level : levels) {
                for (const auto& order : level.orders) {
                    sum += order->price;
                    numOrders++;
                }
            }

            return sum / numOrders;
        }

        // Setter
        static void updateCurrentOrderId(int OrderId){
            currentOrderId = OrderId + 1;
        }

        static void resetOrderId(){
            currentOrderId = 0;
        };

        static void clearOrderBook() {
            orders.clear();
            bidLevels.clear();
            askLevels.clear();
            std::cout << "Order book cleared." << std::endl;
        }

    private:
        // Varibles
        static int currentOrderId;


};