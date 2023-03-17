#include <iostream>
#include "CustomLogger/CustomLogger.hpp"

int main() {
    std::string PATH = "D:\\Development\\C++Project\\Second semester\\Lab_6\\log.txt";  /// log.txt
    logger::CustomLogger::includeFile(PATH);
    logger::CustomLogger::info("info now My program work");
    logger::CustomLogger::error("OutOfBoundException");

    logger::CustomLogger::d("debug start smth");


//    logger::Logger logger(logger::Type::DEBUG);
//    logge



    return 0;
}
