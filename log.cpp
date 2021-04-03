#include <iomanip>
#include <thread>
#include <ctime>
#include <fstream>
#include <string>
#include "log.h"

std::time_t t = std::time(nullptr);
std::tm tm = *std::localtime(&t);

Logger* Logger::m_pThis = nullptr;
std::ofstream Logger::m_Logfile;
std::string Logger::prefix;

std::string Logger::logLevel = "INFO";

Logger::Logger(){}

Logger::~Logger()
{
    if(m_Logfile.is_open()){
        m_Logfile << std::endl;
        m_Logfile.close();
    }
    else{
        std::cout << std::endl;
    }
}

Logger::Logger(const Logger&){}

Logger Logger::getLogger()
{
    if (m_pThis == nullptr){
        m_pThis = new Logger();
        //std::cout << std::put_time(&tm, "%c") << "; " << m_pThis->logLevel << "; " << m_pThis->prefix << "(" << std::this_thread::get_id() << "): ";

    }
    return *m_pThis;
}

Logger Logger::getLogger(std::string fName)
{
    if (m_pThis == nullptr){
        m_pThis = new Logger();
        if (!fName.empty()){
            m_Logfile.open(fName, std::ios::app);
            //m_Logfile << std::put_time(&tm, "%c") << "; " << m_pThis->logLevel << "; " << m_pThis->prefix << "(" << std::this_thread::get_id() << "): ";
        }
    }
    return *m_pThis;
}

Logger Logger::getLogger(std::string fName, std::string prefixName)
{
    if (m_pThis == nullptr){
        m_pThis = new Logger();
        if (!fName.empty()){
            m_Logfile.open(fName, std::ios::app);
        }
        m_pThis->prefix = prefixName;
        //m_Logfile << std::put_time(&tm, "%c") << "; " << m_pThis->logLevel << "; " << m_pThis->prefix << "(" << std::this_thread::get_id() << "): ";
    }
    return *m_pThis;
}


Logger& Logger::operator<<(const std::string& sMessage)
{
    if(m_Logfile.is_open()) {
        m_Logfile << std::put_time(&tm, "%c") << "; " << this->logLevel << "; " << this->prefix << "(" << std::this_thread::get_id() << "): ";
        m_Logfile << sMessage << "\n";
    }
    else{
        std::cout << std::put_time(&tm, "%c") << "; " << this->logLevel << "; " << this->prefix << "(" << std::this_thread::get_id() << "): ";
        std::cout << sMessage << "\n";
    }


   return *this;
}

/*
Operator << for DOUBLE
*/
Logger& Logger::operator<<(const double& sDouble)
{
    std::string sString = std::to_string(sDouble);

    if(m_Logfile.is_open()) {
        m_Logfile << std::put_time(&tm, "%c") << "; " << this->logLevel << "; " << this->prefix << "(" << std::this_thread::get_id() << "): ";
        m_Logfile << sString;
    }
    else{
        std::cout << std::put_time(&tm, "%c") << "; " << this->logLevel << "; " << this->prefix << "(" << std::this_thread::get_id() << "): ";
        std::cout << sString;
    }


   return *this;
}


Logger& Logger::operator()(typelog type)
{
    switch(type)
    {
        case DEBUG: this->logLevel = "DEBUG"; break;
        case WARNING: this->logLevel = "WARNING"; break;
        case ERROR: this->logLevel = "ERROR"; break;
        default: this->logLevel = "INFO"; break;
    }
    //Logger* new_pThis = new Logger(*this);
   return *this;

}



