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
        void insertOrder(const Order& order, double price, Type type); // If type == sell/buy
        void updateOrder(int orderId, double newProductAmount);
        void deleteOrder(int orderId);
        Order* lookupOrder(int orderId);

        // Matching system
        std::vector<Order> getMatchingOrders(const Order& order) const;

        // DECIDE ON THE STRUCTURE OF THE ORDERBOOK
        std::unordered_map<int, Order> orders;
        std::vector<PriceLevel> bidLevels; // Buy
        std::vector<PriceLevel> askLevels; // Sell

        // Getter
        static int getCurrentOrderId(){
            return currentOrderId;
        }

        // Setter
        static void updateCurrentOrderId(int OrderId){
            currentOrderId = OrderId + 1;
        }

    private:
        // Varibles
        static int currentOrderId;


};