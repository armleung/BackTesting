#pragma once
#include <queue>
#include "event.hpp"
#include "dataHandler.hpp"
#include "strategies/strategies.hpp"

class BackTest {
public:
    BackTest();
    void run();

private:
    std::queue<std::shared_ptr<Event>> eventQueue;
    std::shared_ptr<DataHandler> dataHandler;
    std::vector<std::shared_ptr<Strategy>> strategies; // List of strategies to be used
};
