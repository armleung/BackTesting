#include "dataHandler.hpp"

CSVDataHandler::CSVDataHandler(std::queue<Event>& eventQueue, const std::string &filePath)
    : eventQueue(eventQueue), filePath(filePath), fileStream(filePath)
{
    if (!fileStream.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        endOfFile = true;
    }
}

void CSVDataHandler::tick()
{
    if (endOfFile) return;

    readNextLine();
}

void CSVDataHandler::readNextLine() {
    if (std::getline(fileStream, currentLine)) {
        // Process the current line
        std::cout << "Processing line: " << currentLine << std::endl;
        eventQueue.push(Event::TICK); // Example of pushing a TICK event
    } else {
        endOfFile = true;
    }
}
// This function reads the next line from the CSV file and processes it.