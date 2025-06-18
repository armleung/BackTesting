#include "backTest.hpp"
#include <iostream>

BackTest::BackTest()
    : dataHandler(std::make_shared<CSVDataHandler>(eventQueue, "data.csv"))
{
}
void BackTest::run()
{
    dataHandler->tick(); // Process the first tick
    while (!eventQueue.empty()) {
        Event event = eventQueue.front();
        eventQueue.pop();
        switch (event)
        {
        case Event::TICK:
            std::cout << "Processing TICK event" << std::endl;
            break;
        case Event::SIGNAL:
            std::cout << "Processing SIGNAL event" << std::endl;
            break;
        case Event::ORDER:
            std::cout << "Processing ORDER event" << std::endl;
            break;
        case Event::FILL:
            std::cout << "Processing FILL event" << std::endl;
            break;
        default:
            break;
        }
        dataHandler->tick(); // Process the next tick
    }
}