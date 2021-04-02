#include <iomanip>
#include <thread>
#include <ctime>
#include <fstream>
#include <string>
#include "log.h"

std::time_t t = std::time(nullptr);
std::tm tm = *std::localtime(&t);
//std::string logLevel = "INFO";
//std::string curDate = std::str(std::put_time(&tm, "%c"));
//std::string threadId = std::this_thread::get_id();



Logger* Logger::m_pThis = nullptr;

Logger::Logger(){}

Logger::~Logger()
{
    std::cout << std::endl;
}

Logger::Logger(const Logger&){}

/*Logger Logger::getLogger()
{
    if (m_pThis == nullptr){
        m_pThis = new Logger();
        //logMessage = curDate + logLevel + threadId;

    }
    return *m_pThis;
}*/

Logger Logger::getLogger(std::string fName = NULL)
{
    if (m_pThis == nullptr){
        m_pThis = new Logger();
        if (!fName.empty()){
            std::ofstream fout(fName, std::ios::app);
            fout << std::put_time(&tm, "%c") << "; " << m_pThis->logLevel << "; " << "(" << std::this_thread::get_id() << "): " << "\n";
            fout.close();
        }
        else {
            std::cout << std::put_time(&tm, "%c") << "; " << m_pThis->logLevel << "; " << "(" << std::this_thread::get_id() << "): ";
        }

    }
    return *m_pThis;

}

Logger& Logger::operator<<(const std::string& sMessage)
{
   //std::cout << std::put_time(&tm, "%c") << "; " << logLevel << "; " << "(" << std::this_thread::get_id() << "): " << sMessage;
   std::cout << sMessage;
   return *this;
}

Logger& Logger::operator()(typelog type)
{
    switch(type)
    {
        case DEBUG: logLevel = "DEBUG"; break;
        case WARNING: logLevel = "WARNING"; break;
        case ERROR: logLevel = "ERROR"; break;
        default: logLevel = "INFO"; break;
    }
   return *this;
}



