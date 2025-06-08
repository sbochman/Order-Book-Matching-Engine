#include "OrderBook.h"
#include <stdexcept>

// Add order to the appropriate side
void OrderBook::add_order(const Order& order) {
    if (order.is_sell()) {
        sell_orders[order.get_value()].push_back(order);
    } else {
        buy_orders[order.get_value()].push_back(order);
    }
}

// Get and remove the best buy order (highest price, FIFO)
Order OrderBook::get_best_buy_order() {
    if (buy_orders.empty())
        throw std::runtime_error("No buy orders!");
    // rbegin() gives the highest price
    auto it = buy_orders.rbegin();
    Order best_order = it->second.front();
    it->second.pop_front();
    if (it->second.empty()) {
        // Need to erase the key in the map using base() - 1
        buy_orders.erase(std::next(it).base());
    }
    return best_order;
}

// Get and remove the best sell order (lowest price, FIFO)
Order OrderBook::get_best_sell_order() {
    if (sell_orders.empty())
        throw std::runtime_error("No sell orders!");
    auto it = sell_orders.begin();
    Order best_order = it->second.front();
    it->second.pop_front();
    if (it->second.empty()) {
        sell_orders.erase(it);
    }
    return best_order;
}
