#include <iostream>
#include "CustomLogger/Logger.hpp"

int main() {
    std::string PATH = "log.txt";  /// log.txt
    logger::Logger::includeFile(PATH);
    logger::Logger::info("info now My program work");
    logger::Logger::error("OutOfBoundException");

    logger::Logger::d("debug start smth");





    return 0;
}
