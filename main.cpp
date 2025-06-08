#include <iostream>
#include "OrderBook.h"

int main() {
    OrderBook ob;
    ob.add_order(Order(101.0, false)); // Buy order at 101
    ob.add_order(Order(99.0, true));   // Sell order at 99

    Order best_buy = ob.get_best_buy_order();
    Order best_sell = ob.get_best_sell_order();

    std::cout << "Best buy: " << best_buy.get_value() << "\n";
    std::cout << "Best sell: " << best_sell.get_value() << "\n";

    return 0;
}
