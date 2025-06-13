#ifndef ORDER_H
#define ORDER_H

#include <chrono>

class Order {
public:
    Order(double value, bool sell);
    [[nodiscard]] const double get_value() const;
    [[nodiscard]] const bool is_sell() const;
    [[nodiscard]] const bool is_buy() const;
    [[nodiscard]] const std::chrono::system_clock::time_point get_time() const;

private:
    double value;
    bool sell; // true = sell, false = buy
    std::chrono::system_clock::time_point time;
};

#endif //ORDER_H
