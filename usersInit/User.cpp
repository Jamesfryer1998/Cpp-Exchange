#include <iostream>
#include "usersInit/User.h"

using namespace std;

User::User(int _userId,
           string _firstName,
           string _lastName)

    : userId(_userId),
      firstName(_firstName),
      lastName(_lastName)
{

};
