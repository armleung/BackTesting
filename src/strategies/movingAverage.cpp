#include "movingAverage.hpp"
#include <iostream>

void MovingAverageStrategy::calculateSignal(const OHLC &data)
{
    double closePrice = std::get<CLOSE_IDX>(data);
    long long timestamp = std::get<TIMESTAMP_IDX>(data);
    shortBuffer.add(closePrice);
    longBuffer.add(closePrice);

    // Calculate the moving average
    double shortMovingAverage = shortBuffer.moving_average();
    double longMovingAverage = longBuffer.moving_average();

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