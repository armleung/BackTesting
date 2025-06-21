#include "backTest.hpp"
#include <iostream>

BackTest::BackTest()
    : dataHandler(std::make_shared<CSVDataHandler>(eventQueue, "GLD.csv"))
{
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
            std::cout << "Processing TICK event" << std::endl;
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