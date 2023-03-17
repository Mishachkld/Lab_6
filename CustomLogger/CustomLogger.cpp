//
// Created by Mishach on 03.03.2023.
//

#include "CustomLogger.hpp"

namespace logger {
    std::ofstream CustomLogger::outStream;
//    Level CustomLogger::level;
    Level CustomLogger::level = Level::DEBUG;


}