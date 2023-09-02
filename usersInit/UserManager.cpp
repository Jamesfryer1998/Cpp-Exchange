#include "usersInit/UserManager.h"


UserManager::UserManager(){

};

void UserManager::createUser(const User& user){
    users[user.getUserId()] = user;
};


void UserManager::updateUser(int userId, const std::string& newFirstName, const std::string& newLastName){
    if (users.find(userId) != users.end()) {
            User& user = users[userId];
            user.setFirstName(newFirstName);
            user.setLastName(newLastName);
        }
};

void UserManager::deleteUser(int userId){
    users.erase(userId);
};
