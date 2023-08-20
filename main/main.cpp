#include <iostream>
#include <ordersInit/Order.h>

int main(){
    Order app{0, "1", Type::Ask, "3", 1, 1};
    app.TestFunc();
}
