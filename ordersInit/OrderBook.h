#include <ordersInit/Order.h>
#include <set>

class OrderBook
{
    public:
        OrderBook();

        // DECIDE ON THE STRUCTURE OF THE ORDERBOOK

        void addOrder(const Order& order);
        void removeOrder(const Order& order);
        std::vector<Order> getMatchingOrders(const Order& order) const;

        // this is a test line

    private:
        struct OrderComparator {
            bool operator()(const Order& lhs, const Order& rhs) const {
                if (lhs.price == rhs.price) {
                    // For orders with the same price, prioritize the older one
                    return lhs.timestamp < rhs.timestamp;
                }
                // For different prices, prioritize based on order type
                return (lhs.type == Type::Buy) ? (lhs.price > rhs.price) : (lhs.price < rhs.price);
            }
        };
        using OrderMap = std::unordered_map<std::string, std::multiset<Order, OrderComparator>>;

        OrderMap buyOrdersMap;   // Hashmap of Buy Order for specific product
        OrderMap sellOrdersMap;  // Hashmap of Sell Order for specific product

};