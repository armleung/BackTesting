#include "movingAverage.hpp"
#include <iostream>

void MovingAverageStrategy::calculateSignal(const OHLC &data)
{
    auto closePrice = std::get<CLOSE_IDX>(data);
    auto timestamp = std::get<TIMESTAMP_IDX>(data);
    shortBuffer.add(closePrice);
    longBuffer.add(closePrice);

    // Calculate the moving average
    auto shortMovingAverage = shortBuffer.moving_average();
    auto longMovingAverage = longBuffer.moving_average();

    // Generate a signal based on the moving average
    if (closePrice > shortMovingAverage) {
        std::cout << "Timestamp: " << timestamp
                  << " Short MA: " << shortMovingAverage
                  << ", Long MA: " << longMovingAverage
                  << ", Close Price: " << closePrice
                  << " - Buy signal generated." << std::endl;
        //eventQueue.push(std::make_shared<SignalEvent>()); // Buy signal
    } else if (closePrice < shortMovingAverage) {
        std::cout << "Timestamp: " << timestamp
                  << " Short MA: " << shortMovingAverage
                  << ", Long MA: " << longMovingAverage
                  << ", Close Price: " << closePrice
                  << " - Sell signal generated." << std::endl;
        //eventQueue.push(std::make_shared<SignalEvent>()); // Sell signal
    }
}