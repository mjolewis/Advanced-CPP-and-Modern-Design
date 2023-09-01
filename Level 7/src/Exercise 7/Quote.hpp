//
// Quote is a simplified version of an object that can be constructed
// from a binary market data feed. The data is processed of the rx queue
// and converted into an object that internal apps can understand. The
// quote represents buyer and seller interest in a given security
//
// Created by Michael Lewis on 8/31/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_QUOTE_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_QUOTE_HPP

#include <string>

class Quote
{
private:
    std::string _symbol;
    double _bidPrice;
    double _bidSize;
    std::string _bidExchange;
    double _askPrice;
    double _askSize;
    std::string _askExchange;
    std::string _timestamp;

public:
    Quote() = default;
    ~Quote() = default;

    const std::string &getSymbol() const
    {
        return _symbol;
    }

    void setSymbol(const std::string &symbol)
    {
        _symbol = symbol;
    }

    double getBidPrice() const
    {
        return _bidPrice;
    }

    void setBidPrice(double bidPrice)
    {
        _bidPrice = bidPrice;
    }

    double getBidSize() const
    {
        return _bidSize;
    }

    void setBidSize(double bidSize)
    {
        _bidSize = bidSize;
    }

    const std::string &getBidExchange() const
    {
        return _bidExchange;
    }

    void setBidExchange(const std::string &bidExchange)
    {
        _bidExchange = bidExchange;
    }

    double getAskPrice() const
    {
        return _askPrice;
    }

    void setAskPrice(double askPrice)
    {
        _askPrice = askPrice;
    }

    double getAskSize() const
    {
        return _askSize;
    }

    void setAskSize(double askSize)
    {
        _askSize = askSize;
    }

    const std::string &getAskExchange() const
    {
        return _askExchange;
    }

    void setAskExchange(const std::string &askExchange)
    {
        _askExchange = askExchange;
    }

    const std::string &getTimestamp() const
    {
        return _timestamp;
    }

    void setTimestamp(const std::string &timestamp)
    {
        _timestamp = timestamp;
    }
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_QUOTE_HPP
