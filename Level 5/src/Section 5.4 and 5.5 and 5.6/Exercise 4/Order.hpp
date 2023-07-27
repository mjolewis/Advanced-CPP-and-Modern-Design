//
// Composite object that will be used for testing the generic variadic hash function
//
// Created by Michael Lewis on 7/27/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_ORDER_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_ORDER_HPP

#include <cstddef>
#include <string>

class Order
{
private:
    long orderId;
    char requestType;
    int side;
    double price;
    double qty;

public:
    Order() = delete;
    Order(long orderId, char requestType, int side, double price, double qty);
    ~Order() = default;

    // Friends
    friend std::size_t hash_value(const Order& order);
    friend std::size_t hash_value(std::size_t seed, const Order& order);
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_ORDER_HPP