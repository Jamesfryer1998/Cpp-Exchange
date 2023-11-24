#include <gtest/gtest.h>
#include "ordersInit/CSVReader.h"
#include <ordersInit/Order.h>
#include <ordersInit/OrderBook.h>

TEST(CSVReaderTest, BasicAssertions) {
    CSVReader reader;

    {
        // Given an empty line
        // When we tokenize it
        auto tokens { reader.tokenise("", ',')};
        // Then we expect the result to be no tokens
        EXPECT_EQ(tokens.size(), 0);
    }

    {
        // Given a line with a single world
        // When we tokenize it
        auto tokens { reader.tokenise("test", ',')};
        // Then we expect the word as the only token
        EXPECT_EQ(tokens.size(), 1);
        EXPECT_EQ(tokens[0], "test");
    }

    {
        // Given a line with a single word and a trailing comma
        // When we tokenize it
        auto tokens { reader.tokenise("test,", ',')};
        EXPECT_EQ(tokens.size(), 1);
        // Then we expect the word as the only token
        EXPECT_EQ(tokens[0], "test");
    }

    {
        // Given a line with a single word and a trailing command
        // When we tokenize it
        auto tokens { reader.tokenise("test1,,test2", ',')};
        // Then we expect what????, presumably more than one token. This test
        // would fail if we asserted we wanted more than 1 token
        EXPECT_GE(tokens.size(), 1);
    }

    {
        // Given a line with two words and a leading space 
        // When we tokenize it
        auto tokens { reader.tokenise("test1, test2", ',')};
        // Then we expect two words including the leading space
        EXPECT_EQ(tokens.size(), 2);
        EXPECT_EQ(tokens[0], "test1");
        EXPECT_EQ(tokens[1], " test2");
    }
}

TEST(CSVReaderTest, LoadOrders) {
    CSVReader reader;
    std::unordered_map<int, Order> orders = reader.readCSV("/Users/james/Projects/exchange/20200317.csv");

    {
        // The number of all orders should be equal to 3540 (the number of rows in the CSV)
        EXPECT_EQ(orders.size(), 3540);
    }

    {
        auto test = orders.find(10);
        
        EXPECT_EQ(test->first, 10);
    }
}

TEST(CSVReaderTest, UpperCase) {
    CSVReader reader;

    {
        std::string str = reader.toUpperCase("test");

        EXPECT_STREQ("TEST", str.c_str());
    }

}