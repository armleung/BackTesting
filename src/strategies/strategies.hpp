#pragma once 
#include "../event.hpp"
#include "../types.hpp"
#include <memory>
#include <queue>

class Strategy {
public:
    Strategy(std::queue<std::shared_ptr<Event>>& eventQueue) 
        : eventQueue(eventQueue) {}
    virtual ~Strategy() = default;
	virtual void calculateSignal(const OHLC& data) = 0;
protected:
    std::queue<std::shared_ptr<Event>>& eventQueue;
};