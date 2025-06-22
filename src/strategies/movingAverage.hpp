#pragma once 
#include "strategies.hpp"
#include <vector>
#include <numeric>

template<typename T>
class CircularBuffer {
public:
    CircularBuffer(size_t size) : buffer(size), max_size(size), 
        head(0), count(0) {}

    void add(T value) {
        buffer[head] = value;
        head = (++head) % max_size;
        if (count < max_size) ++count;
    }

    double moving_average() const {
        if (count == 0) return 0.0;
        T sum = std::accumulate(buffer.begin(), buffer.begin() + count, T{});
        return static_cast<double>(sum) / count;
    }

    size_t size() const { return count; }
    bool full() const { return count == max_size; }

private:
    std::vector<T> buffer;
    size_t max_size;
    size_t head;
    size_t count;
};

class MovingAverageStrategy : public Strategy {
public:
    MovingAverageStrategy(std::queue<std::shared_ptr<Event>>& eventQueue
        , int shortWindow, int longWindow)
        : Strategy(eventQueue), shortBuffer(shortWindow), longBuffer(longWindow) {}

    void calculateSignal(const OHLC& data) override;
private:
    CircularBuffer<double> shortBuffer; // Circular buffer for short moving average
    CircularBuffer<double> longBuffer; // Circular buffer for long moving average
};