//
// FeedHandler is responsible for processing binary market data received from the wire
// and processing the data into internal algos.
//
// This represents a useful, although very simplified, use case for Concepts. Exchanges disseminate
// quotes and trades using a specific protocol that can be modeled semantically via Concepts to provide
// compile time type checking. Additionally, the Concept can be used (as shown below) for function
// template overloads based on type properties.
//
// This approach represents a superior alternative to SFINAE while also providing the additional benefit
// of advanced compiler diagnostics which can greatly improve developer productivity over the often
// difficult to decipher template error messages
//
// Created by Michael Lewis on 8/31/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_FEEDHANDLER_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_FEEDHANDLER_HPP

#include <iostream>


// Represents a set of constraints for a quote
template<typename T>
concept QuoteEvent = requires (const T& quote)
{
    quote.getSymbol();
    quote.getBidPrice();
    quote.getBidSize();
    quote.getBidExchange();
    quote.getAskPrice();
    quote.getAskSize();
    quote.getAskExchange();
    quote.getTimestamp();
};

// Represents a set of constraints for a Trade
template<typename T>
concept TradeEvent = requires (const T& trade)
{
    trade.getPrice();
    trade.getSize();
    trade.getTimestamp();
    trade.getTick();
    trade.getExchange();
    trade.getSaleCondition();
    trade.getSymbol();
};

class FeedHandler
{
public:
    FeedHandler() = default;
    ~FeedHandler() = default;

    template<typename T>
    requires QuoteEvent<T>
    void handle(const T& t)
    {
        std::cout << "Processing a quote" << std::endl;
    }

    template<typename T>
    requires TradeEvent<T>
    void handle(const T& t)
    {
        std::cout << "Processing a trade" << std::endl;
    }
};

#endif //ADVANCED_CPP_AND_MODERN_DESIGN_FEEDHANDLER_HPP
