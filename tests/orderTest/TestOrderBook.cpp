#include <gtest/gtest.h>
#include "ordersInit/OrderBook.h"
 
TEST(OrderBookTest, IncrementOrderId) {
    OrderBook orders; // See OrderBookEntry tests.
    {
        // Get current Order Id Value
        int currentOrderID = orders.getCurrentOrderId();

        // We intialise the OrderBook order #0
        EXPECT_EQ(currentOrderID, 0);
    }

    {

        int currentOrderID = orders.getCurrentOrderId();

        // Update the current Order Id value by 1
        orders.updateCurrentOrderId(currentOrderID);

        // Get new current Order Id Value
        int newOrderId = orders.getCurrentOrderId();

        EXPECT_EQ(newOrderId, 1);
    }

    orders.resetOrderId();

    {
        // Increment Order Id by 10
        int toIncrementBy = 10;

        // Loop through value and get, set OrderId value
        for (int i = 0; i < toIncrementBy; i++){
            int currentOrderID = orders.getCurrentOrderId();
            orders.updateCurrentOrderId(currentOrderID);
        }
        
        // Return the final Order Id
        int newOrderId = orders.getCurrentOrderId();

        EXPECT_EQ(newOrderId, toIncrementBy);
    }

    orders.resetOrderId();

    {
        // Increment Order Id by 200k
        int toIncrementBy = 200000;

        // Loop through value and get, set OrderId value
        for (int i = 0; i < toIncrementBy; i++){
            int currentOrderID = orders.getCurrentOrderId();
            orders.updateCurrentOrderId(currentOrderID);
        }
        
        // Return the final Order Id
        int newOrderId = orders.getCurrentOrderId();

        EXPECT_EQ(newOrderId, toIncrementBy);
    }

}

TEST(OrderBookTest, InsertOrders) {
    OrderBook orderBook;

    {
        // No order inserted into OrderBook
        auto orderFound = orderBook.lookupOrder(1);

        // We expect a nullptr
        EXPECT_EQ(orderFound, nullptr);
    }
    
    {
        // Define and inster Order into OrderBook
        Order entry1(1, "2020/03/17 17:01:24.884492", Type::Ask, "ETH/BTC", 1, 1);
        orderBook.insertOrder(entry1, 1, Type::Ask);

        // Lookup order in memory using ptr
        int orderId = 1;
        auto orderFound = orderBook.lookupOrder(orderId);

        // OrderId of orderFound expected to be 1
        EXPECT_EQ(orderFound->orderId, orderId);
    }

    orderBook.clearOrderBook();

    {
        // Testing large amount of insertions
        int correctCount = 0;

        for (int i = 0; i < 1000; i++){
            Order entry1(i, "2020/03/17 17:01:24.884492", Type::Ask, "ETH/BTC", 1, 1);
            orderBook.insertOrder(entry1, 1, Type::Ask);

            auto orderFound = orderBook.lookupOrder(i);

            if (orderFound->orderId == i) correctCount++;
        }

        EXPECT_EQ(correctCount, 1000);
    }
}

TEST(OrderBookTest, UpdateOrders) {
    OrderBook orderBook;

    {
        // Create and insert order into orderbook
        Order entry1(1, "2020/03/17 17:01:24.884492", Type::Ask, "ETH/BTC", 1, 1);
        orderBook.insertOrder(entry1, 1, Type::Ask);

        // Update the order amount to 2
        orderBook.updateOrder(1, 2);

        // Get new order amount
        double newOrderAmount = orderBook.lookupOrder(1)->amount;

        // Expected to be 2
        EXPECT_EQ(newOrderAmount, 2);
    }

    {
        // Create and insert multiple order into orderbook
        Order entry1(1, "2020/03/17 17:01:24.884492", Type::Ask, "ETH/BTC", 1, 1);
        Order entry2(2, "2020/03/17 17:01:24.884492", Type::Ask, "ETH/BTC", 2, 1);
        Order entry3(3, "2020/03/17 17:01:24.884492", Type::Ask, "ETH/BTC", 3, 1);

        orderBook.insertOrder(entry1, 1, Type::Ask);
        orderBook.insertOrder(entry2, 2, Type::Ask);
        orderBook.insertOrder(entry3, 3, Type::Ask);

        // Update the order amount to 2
        orderBook.updateOrder(2, 10);

        // Get new order amount
        double newOrderAmount = orderBook.lookupOrder(2)->amount;

        // Expected to be 2
        EXPECT_EQ(newOrderAmount, 10);
    }

}

TEST(OrderBookTest, DeleteOrders) {
    OrderBook orderBook;

    {        
        // Create and insert multiple order into orderbook
        Order entry1(1, "2020/03/17 17:01:24.884492", Type::Ask, "ETH/BTC", 1, 1);
        Order entry2(2, "2020/03/17 17:01:24.884492", Type::Ask, "ETH/BTC", 2, 1);
        Order entry3(3, "2020/03/17 17:01:24.884492", Type::Ask, "ETH/BTC", 3, 1);

        orderBook.insertOrder(entry1, 1, Type::Ask);
        orderBook.insertOrder(entry2, 2, Type::Ask);
        orderBook.insertOrder(entry3, 3, Type::Ask);

        // Delete order 2 from ord;erbook
        orderBook.deleteOrder(2);

        // Check if order exists
        auto order = orderBook.lookupOrder(2);

        EXPECT_EQ(order, nullptr);
    }

    {
        // Checking clear orderbook deletes all orders

        // Create and insert multiple order into orderbook
        Order entry1(1, "2020/03/17 17:01:24.884492", Type::Ask, "ETH/BTC", 1, 1);
        Order entry2(2, "2020/03/17 17:01:24.884492", Type::Ask, "ETH/BTC", 2, 1);
        Order entry3(3, "2020/03/17 17:01:24.884492", Type::Ask, "ETH/BTC", 3, 1);

        orderBook.insertOrder(entry1, 1, Type::Ask);
        orderBook.insertOrder(entry2, 2, Type::Ask);
        orderBook.insertOrder(entry3, 3, Type::Ask);

        orderBook.clearOrderBook();

        EXPECT_EQ(orderBook.lookupOrder(1), nullptr);
        EXPECT_EQ(orderBook.lookupOrder(2), nullptr);
        EXPECT_EQ(orderBook.lookupOrder(3), nullptr);

    }
}

TEST(OrderBookTest, TestStats) {
    OrderBook orderBook;

    // Define stat varibales
    double highPrice = 3;
    double lowPrice = 1;
    double avgPrice = 2;
    double spread = 2;

    // Init Order entries
    Order entry1(1, "2020/03/17 17:01:24.884492", Type::Ask, "ETH/BTC", lowPrice, 1);
    Order entry2(2, "2020/03/17 17:01:24.884492", Type::Ask, "ETH/BTC", avgPrice, 1);
    Order entry3(3, "2020/03/17 17:01:24.884492", Type::Ask, "ETH/BTC", highPrice, 1);

    // Insert orders into OrderBook
    orderBook.insertOrder(entry1, lowPrice, Type::Ask);
    orderBook.insertOrder(entry2, avgPrice, Type::Ask);
    orderBook.insertOrder(entry3, highPrice, Type::Ask);

    // Assert values from high, low, avg and spread
    EXPECT_EQ(orderBook.getHighPrice(orderBook.askLevels), 3);
    EXPECT_EQ(orderBook.getLowPrice(orderBook.askLevels), lowPrice);
    EXPECT_EQ(orderBook.getHighPrice(orderBook.askLevels) - OrderBook::getLowPrice(orderBook.askLevels), spread);
    EXPECT_EQ(orderBook.getAvgPrice(orderBook.askLevels), avgPrice);
}