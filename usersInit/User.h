#pragma once

#include "ordersInit/Order.h"
#include <iostream>
#include <vector>


class User{
    public:
        User() = default;

        User(int _userId,
             std::string _firstName,
             std::string _lastName
        );

        // getters
        int getUserId() const {
            return userId;
        }

        // setters
        void setFirstName(const std::string& newFirstName){
            firstName = newFirstName;
        }

        void setLastName(const std::string& newLastName){
            lastName = newLastName;
        }

    private:
        // Variables
        int userId;
        std::string firstName;
        std::string lastName;
        std::unordered_map<int, int> userOrders;

};
