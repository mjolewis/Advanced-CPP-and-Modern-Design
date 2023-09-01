//
// Concepts - Basic Illustration
//
// Created by Michael Lewis on 8/31/23.
//

#include "Quote.hpp"
#include "Trade.hpp"
#include "FeedHandler.hpp"

// Test that a valid quote object can be processed by the FeedHandler
void test_Quote()
{
    Quote quote;
    quote.setSymbol("AAPL.US");
    quote.setBidSize(188.93);
    quote.setBidSize(1000);
    quote.setBidExchange("XNAS");
    quote.setTimestamp("20230831T12:59:59");

    FeedHandler handler;
    handler.handle(quote);
}

// Test that a valid trade object can be processed by the FeedHandler
void test_Trade()
{
    Trade trade;
    trade.setPrice(188.87);
    trade.setSize(1000);
    trade.setSymbol("AAPL.US");
    trade.setTimestamp("20230831T13:00:00");
    trade.setSaleCondition("@ I");
    trade.setTick("UP");
    trade.setExchange("XNAS");

    FeedHandler handler;
    handler.handle(trade);
}

int main()
{
    test_Quote();
    test_Trade();

    return 0;
}