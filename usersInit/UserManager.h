#include "User.h"
#include <unordered_map>

class UserManager {
    public:
        UserManager();

        void createUser(const User& user);
        void updateUser(int userId, const std::string& newFirstName, const std::string& newLastName);
        void deleteUser(int userId);

        // getters
        auto getUsers() {
            return users;
        }

    private:
        std::unordered_map<int, User> users;
};
