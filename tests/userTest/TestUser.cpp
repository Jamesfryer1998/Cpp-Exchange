#include <gtest/gtest.h>
#include <usersInit/User.h>

TEST(UserTest, UserGetters) {
    User user = User{1, "James", "Fryer"};

    {
        // Get each item of infomation from user        
        EXPECT_EQ(user.getUserId(), 1);
        EXPECT_EQ(user.getFirstName(), "James");
        EXPECT_EQ(user.getLastName(), "Fryer");
    }
}

TEST(UserTest, UserSetters) {
    User user = User{1, "James", "Fryer"};

    {
        // Setting new first and last name for user
        user.setFirstName("Chantal");
        user.setLastName("Maskell");

        // Getting new infomation for user        
        EXPECT_EQ(user.getFirstName(), "Chantal");
        EXPECT_EQ(user.getLastName(), "Maskell");
    }
}