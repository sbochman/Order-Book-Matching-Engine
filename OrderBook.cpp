#include "OrderBook.h"
#include <stdexcept>
#include <iostream>

OrderBook::OrderBook(){
  matching_engine = MatchingEngine();
}

// Add order to the appropriate side
void OrderBook::add_order(const Order& order) {
    if (order.is_sell()) {
        sell_orders[order.get_value()].push_back(order);
    } else {
        buy_orders[order.get_value()].push_back(order);
    }
}

// Get and remove the best buy order (highest price, FIFO)
std::optional<Order> OrderBook::get_best_buy_order(Order& sell_order) {
    std::optional<Order> match = matching_engine.find_best_matching(sell_order, buy_orders);
    if (match != std::nullopt) {
      return *match;
    }
    return std::nullopt;
}

// Get and remove the best sell order (lowest price, FIFO)
std::optional<Order> OrderBook::get_best_sell_order(Order& buy_order) {
    std::optional<Order> match = matching_engine.find_best_matching(buy_order, sell_orders);
    if (match != std::nullopt) {
      return *match;
    }
    return std::nullopt;
}

void OrderBook::print_orders() {
  for (auto& price : sell_orders) {
    for (auto& order : price.second) {
      std::cout << order.get_value();
    }
    std::cout << std::endl;
  }
  for (auto& price : buy_orders) {
    for (auto& order : price.second) {
      std::cout << order.get_value();
    }
    std::cout << std::endl;
  }
}