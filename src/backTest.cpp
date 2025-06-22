#include "backTest.hpp"
#include <iostream>
#include "strategies/movingAverage.hpp"

BackTest::BackTest()
    : dataHandler(std::make_shared<CSVDataHandler>(eventQueue, "GLD.csv"))
{
    // Initialize strategies
    strategies.push_back(std::make_shared<MovingAverageStrategy>(eventQueue, 20, 50));
}
void BackTest::run()
{
    dataHandler->tick(); // Process the first tick
    while (!eventQueue.empty()) {
        auto event = eventQueue.front();
        eventQueue.pop();
        switch (event->getType())
        {
        case EventType::TICK:
            for (const auto& strategy : strategies) {
                // Process the tick event with each strategy
                auto tickEvent = std::dynamic_pointer_cast<TickEvent>(event);
                if (tickEvent) {
                    strategy->calculateSignal(tickEvent->getOHLCData());
                }
            }
            break;
        case EventType::SIGNAL:
            std::cout << "Processing SIGNAL event" << std::endl;
            break;
        case EventType::ORDER:
            std::cout << "Processing ORDER event" << std::endl;
            break;
        case EventType::FILL:
            std::cout << "Processing FILL event" << std::endl;
            break;
        default:
            break;
        }
        dataHandler->tick(); // Process the next tick
    }
}