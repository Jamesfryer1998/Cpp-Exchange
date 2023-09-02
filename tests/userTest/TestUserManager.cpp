#include <gtest/gtest.h>
#include "usersInit/UserManager.h"

TEST(UserTest, CreateUser) {
    UserManager users;

    {
        // Initialise User {me}
        User user = User{1, "James", "Fryer"};

        // Create User in UserManager
        users.createUser(user);

        // Should be 1 user in users
        EXPECT_EQ(users.getUsers().size(), 1);
    }
    
}

TEST(UserTest, UpdateUser) {
    UserManager users;
    User user = User{1, "James", "Fryer"};
    users.createUser(user);

    {
        // Update User
        users.updateUser(1, "Chantal", "Maskell");

        // Get user
        user = users.getUsers()[1];

        // Should be 1 user in users
        EXPECT_NE(user.getFirstName(), "James");
        EXPECT_EQ(user.getFirstName(), "Chantal");
    }
    
}

TEST(UserTest, DeleteUser) {
    UserManager users;
    User user = User{1, "James", "Fryer"};
    users.createUser(user);

    {
        // Delete UserId 1 from Users
        users.deleteUser(1);

        // Expect Users to have a size of 0
        EXPECT_EQ(users.getUsers().size(), 0);
    }
    
}