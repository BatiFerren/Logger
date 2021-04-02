#ifndef LOG_H_INCLUDED
#define LOG_H_INCLUDED

#include <fstream>
#include <iostream>
#include <cstdarg>
#include <string>

enum typelog {
    INFO,
    DEBUG,
    WARNING,
    ERROR
};

class Logger
{
public:

    std::string logLevel = "INFO";

    //std::string logMessage;

    Logger();

    //Logger(typelog type);

    virtual ~Logger();

    Logger(const Logger&);

    Logger& operator()(typelog type);

    Logger& operator=(const Logger&) {return *this;};

    Logger& operator<<(const std::string& sMessage);

    static Logger getLogger();

    static Logger getLogger(const std::string fName);

private:
    static Logger* m_pThis;

};

#endif // LOG_H_INCLUDED
