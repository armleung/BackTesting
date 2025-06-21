#pragma once
#include <queue>
#include "event.hpp"
#include "dataHandler.hpp"

class BackTest {
public:
    BackTest();
    void run();

private:
    std::queue<std::shared_ptr<Event>> eventQueue;
    std::shared_ptr<DataHandler> dataHandler;
};
