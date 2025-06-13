#include "MatchingEngine.h"
#include <iostream>



MatchingEngine::MatchingEngine() {};

MatchingEngine& MatchingEngine::operator=(const MatchingEngine& other) {
  if (this == &other) return *this;
  return *this;
}

std::optional<Order> MatchingEngine::find_best_matching(Order &order, std::map<double, std::deque<Order>> &book) {
    if (order.is_sell()) {
      //find best buy order in book
      auto it = book.upper_bound(order.get_value());
      if (it == book.begin()) {
        return std::nullopt;
      }
      it--;
      return it->second.front();
    }
    else {
      auto it = book.lower_bound(order.get_value());
      if (it == book.end()) {
        return std::nullopt;
      }
      return it->second.front();
    }
}