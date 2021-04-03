#ifndef LOG_H_INCLUDED
#define LOG_H_INCLUDED

#include <fstream>
#include <iostream>
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

    static std::string logLevel;

    static std::string prefix;

    Logger();

    virtual ~Logger();

    Logger(const Logger&);

    Logger& operator()(typelog type);

    Logger& operator=(const Logger&) {return *this;};

    Logger& operator<<(const std::string& sMessage);

    Logger& operator<<(const double& sDouble);

    static Logger getLogger();

    static Logger getLogger(std::string fName);

    static Logger getLogger(std::string fName, std::string prefixName);

private:
    static Logger* m_pThis;

    static std::ofstream m_Logfile;


};

#endif // LOG_H_INCLUDED
