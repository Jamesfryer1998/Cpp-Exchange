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