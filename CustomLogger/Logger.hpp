//
// Created by Mishach on 03.03.2023.
//
#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>


namespace logger {

    enum class Level {
        DEBUG,
        RELEASE,
    };

    enum class Type {
        ERROR,
        DEBUG,
        INFO
    };

    class Logger {  /// переименовать
    private:
        static std::ofstream outStream;
        static Level level;


        Logger() = default;

        ~Logger() { outStream.close(); };

        static std::string generateMessage(const std::string &logMessage, const std::string &type) {
            std::time_t timeNow = std::time(nullptr);
            std::string result = type + ": " + logMessage + " | " + std::asctime(std::localtime(&timeNow));
            return result;
        }


    public:

        static void includeFile(const std::string &path = "log.txt") { outStream.open(path); }

        static void d(const std::string &logMessage) {
            std::system("Color 0A"); // зеленный
            if (level != Level::RELEASE)
                std::cerr << generateMessage(logMessage, "DEBUG");
            outStream << generateMessage(logMessage, "DEBUG");
            outStream.flush();

        }

        static void info(const std::string &logMessage) {
            std::system("Color 06");  // желтый
            if (level != Level::RELEASE)
                std::cerr << generateMessage(logMessage, "INFO");
            outStream << generateMessage(logMessage, "INFO");
            outStream.flush();
        }

        static void error(const std::string &logMessage) {
//            std::system("Color 04"); // красный
            if (level != Level::RELEASE)
                std::cerr << generateMessage(logMessage, "ERROR");
            outStream << generateMessage(logMessage, "ERROR");
            outStream.flush();
        }


        /*static void writeLog(const std::string &logMessage) {
            switch (level) {
                case Level::RELEASE:
                    outStream << generateMessage(logMessage, "RELEASE DEBUGGING");
                case Level::DEBUG:
                    outStream << generateMessage(logMessage, "DEBUG");
                    std::cout << generateMessage(logMessage, "DEBUG");
            }
            outStream.flush();
        }*/
    };


    class CLog {
    private:
        std::stringstream outString;
        logger::Type typeOfLogger;


        template<typename T>
        CLog &operator<<(T &t) {
            outString << t;
            return *this;
        }


    public:
        explicit CLog(Type logType) : typeOfLogger(logType) {}

        ~CLog() {
            std::time_t timeNow = std::time(nullptr);
            switch (typeOfLogger) {
                case Type::DEBUG:
                    std::cerr << "DEBUG: " <<  outString.str() + " | " + std::asctime(std::localtime(&timeNow));
                case Type::ERROR:
                    std::cerr << "ERROR: " << outString.str() + " | " + std::asctime(std::localtime(&timeNow));
                case Type::INFO:
                    std::cerr << "INFO: " << outString.str() + " | " + std::asctime(std::localtime(&timeNow));
            }
        }


        logger::CLog info()
        {
            return logger::CLog(logger::Type::INFO);
        }

        logger::CLog debug()
        {
            return logger::CLog(logger::Type::DEBUG);
        }

        logger::CLog error()
        {
            return logger::CLog(logger::Type::ERROR);
        }
    };



} // logger