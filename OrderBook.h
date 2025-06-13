#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include <map>
#include <deque>
#include "Order.h"
#include "MatchingEngine.h"

class OrderBook {
public:

    OrderBook();
    void add_order(const Order& order);
    // Get and remove the best order from buy or sell side
    std::optional<Order> get_best_buy_order(Order& sell_order);
    std::optional<Order> get_best_sell_order(Order& buy_order);
    void print_orders();

private:
    std::map<double, std::deque<Order>> buy_orders;   // buy side
    std::map<double, std::deque<Order>> sell_orders;  // sell side
    MatchingEngine matching_engine;
};

#endif // ORDERBOOK_H
