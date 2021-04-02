#ifndef LOG_H_INCLUDED
#define LOG_H_INCLUDED

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
    Logger();

    Logger(typelog type);

    virtual ~Logger();

    Logger(const Logger&);

    Logger& operator=(const Logger&) {return *this;};

    Logger& operator<<(const std::string& sMessage);

    static Logger getLogger();

private:
    static Logger* m_pThis;

    static std::string logLevel;

    //typelog msglevel = INFO;

};

#endif // LOG_H_INCLUDED
