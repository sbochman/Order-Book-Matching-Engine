#include "Order.h"
#include <map>
#include <deque>
#ifndef MATCHINGENGINE_H
#define MATCHINGENGINE_H



class MatchingEngine {

public:
  MatchingEngine();
  MatchingEngine& operator=(const MatchingEngine& other);

  std::optional<Order> find_best_matching(Order &order, std::map<double, std::deque<Order>> &book);



};



#endif //MATCHINGENGINE_H
