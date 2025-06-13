#include <iostream>
#include "OrderBook.h"

int main() {
    OrderBook ob;
    ob.add_order(Order(101.0, false)); // Buy order at 101
    ob.add_order(Order(99.0, true));   // Sell order at 99

    Order buy = Order(100.00, false);
    Order sell = Order(105.00, true);
    // buy = {101.0 : [A],  100.00: [B]}
    // sell = {99.00 : [C], 105.00: [D]

    ob.add_order(sell);
    ob.add_order(buy);

    std::optional<Order> o = ob.get_best_buy_order(sell); //95 - inf
    std::optional<Order> o2 = ob.get_best_sell_order(buy);

    //ob.print_orders();
    if (o) {
        std::cout << o->get_value() << std::endl;
    }
    if (o2) {
        std::cout << o2->get_value() << std::endl;
    }
    else {
        std::cout << "No such order" << std::endl;
    }

    return 0;
}
