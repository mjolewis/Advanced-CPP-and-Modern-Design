//
// Trade is a simplified version of an object that can be constructed
// from a binary market data feed. The data is processed of the rx queue
// and converted into an object that internal apps can understand. The
// trade represents a cross between a buyer and a seller in any given market
//
// Created by Michael Lewis on 8/31/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_TRADE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_TRADE_HPP

#include <string>
#include <utility>

class Trade
{
private:
    double _price;
    double _size;
    std::string _symbol;
    std::string _saleCondition;
    std::string _tick;
    std::string _exchange;
    std::string _timestamp;

public:
    Trade() : _price{}, _size{}, _timestamp{} {};
    ~Trade() = default;

    double getPrice() const { return _price; }
    void setPrice(double price) { _price = price; }

    double getSize() const { return _size; }
    void setSize(double size) { _size = size; }

    const std::string& getTimestamp() const { return _timestamp; }
    void setTimestamp(std::string timestamp) { _timestamp = std::move(timestamp); }

    const std::string& getSaleCondition() const { return _saleCondition;}
    void setSaleCondition(const std::string &saleCondition) { _saleCondition = saleCondition;}

    const std::string& getTick() const { return _tick; }
    void setTick(const std::string& tick) { _tick = tick;}

    const std::string& getExchange() const { return _exchange; }
    void setExchange(const std::string &exchange) { _exchange = exchange; }

    const std::string& getSymbol() const { return _symbol; }
    void setSymbol(const std::string &symbol) { _symbol = symbol; }
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_TRADE_HPP
