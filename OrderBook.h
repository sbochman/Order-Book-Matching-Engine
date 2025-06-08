#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include <map>
#include <deque>
#include "Order.h"

class OrderBook {
public:
    void add_order(const Order& order);
    // Get and remove the best order from buy or sell side (optional signature)
    Order get_best_buy_order();
    Order get_best_sell_order();

private:
    std::map<double, std::deque<Order>> buy_orders;   // buy side
    std::map<double, std::deque<Order>> sell_orders;  // sell side
};

#endif // ORDERBOOK_H
