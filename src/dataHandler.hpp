#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <queue>
#include "event.hpp"

class DataHandler {
public:
    virtual ~DataHandler() = default;
    virtual void tick() = 0;
};

class CSVDataHandler : public DataHandler {
public:
    CSVDataHandler(std::queue<Event>& eventQueue, const std::string& filePath);
    void tick() override;
private:
    std::string filePath;
    std::ifstream fileStream;
    std::string currentLine;
    bool endOfFile = false;

    void readNextLine();

    std::queue<Event>& eventQueue;
};