#pragma once 
#include <tuple>

constexpr std::size_t TIMESTAMP_IDX = 0;
constexpr std::size_t OPEN_IDX      = 1;
constexpr std::size_t HIGH_IDX      = 2;
constexpr std::size_t LOW_IDX       = 3;
constexpr std::size_t CLOSE_IDX     = 4;
constexpr std::size_t VOLUME_IDX    = 5;

// Timestamp, Open, High, Low, Close, Volume
using OHLC = std::tuple<long, double, double, double, double, int>; 