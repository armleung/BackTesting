#include "dataHandler.hpp"
#include <sstream>
#include "types.hpp"

CSVDataHandler::CSVDataHandler(std::queue<std::shared_ptr<Event>>& eventQueue, const std::string &filePath)
    : eventQueue(eventQueue), filePath(filePath), fileStream(filePath)
{
    if (!fileStream.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        endOfFile = true;
    }
    std::getline(fileStream, currentLine); // Read the header line
}

void CSVDataHandler::tick()
{
    if (endOfFile) return;
    readNextLine();
}

void CSVDataHandler::readNextLine() {
    if (std::getline(fileStream, currentLine)) {
        
        std::stringstream ss(currentLine);
        std::string lineItem;
        std::vector<std::string> lineVector;

        while (std::getline(ss, lineItem, ',')) {
            lineVector.emplace_back(lineItem);
        }
        // Directly construct the TickEvent with parsed OHLC data using lvalue references
        eventQueue.push(std::make_shared<TickEvent>(
            std::make_tuple(
                std::stoll(lineVector[0]), // Timestamp
                std::stod(lineVector[1]),  // Open
                std::stod(lineVector[2]),  // High
                std::stod(lineVector[3]),  // Low
                std::stod(lineVector[4]),  // Close
                std::stoi(lineVector[5])   // Volume
        )));
    } else {
        endOfFile = true;
    }
}
// This function reads the next line from the CSV file and processes it.