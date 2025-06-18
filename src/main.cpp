#include <iostream>
#include "backTest.hpp"
#include "dataHandler.hpp"

int main() {
    BackTest backTest;
    backTest.run();
    std::cout << "Backtest completed." << std::endl;
    return 0;
}