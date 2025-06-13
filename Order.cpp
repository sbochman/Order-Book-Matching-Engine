#include "Order.h"

Order::Order(double value, bool sell)
    : value(value), sell(sell), time(std::chrono::system_clock::now()) {}

const double Order::get_value() const {
    return this->value;
}

const bool Order::is_sell() const {
    return this->sell;
}

const bool Order::is_buy() const {
    return !this->sell;
}

const std::chrono::system_clock::time_point Order::get_time() const {
    return this->time;
}
