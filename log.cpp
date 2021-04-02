#include "log.h"

Logger* Logger::m_pThis = nullptr;

Logger::Logger(){}

Logger::Logger(typelog type){
    switch(type)
    {
        case INFO: std::cout << "INFO"; break;
        case DEBUG: std::cout << "DEBUG"; break;
    }
}

Logger::~Logger()
{
    std::cout << std::endl;
}

Logger::Logger(const Logger&){}

Logger Logger::getLogger()
{
    if (m_pThis == nullptr){
        m_pThis = new Logger();

    }
    return *m_pThis;
}

Logger& Logger::operator<<(const std::string& sMessage)
{
   std::cout << sMessage;
   return *this;
}



