#pragma once

#include <string>

class Logger
{
	/*
	class to log messages at log levels to various targets
	the LoggingStatus affects how the message is formatted:
		- DEBUG will prefix the message with "[DEBUG]"
		- INFO will prefix the message with "[INFO]"
		- ERROR will prefix the message with "[ERROR]"
	*/
public:
	enum LoggingStatus 
	{
		DEBUG,
		INFO,
		ERROR
	};

	Logger();
	~Logger();

	static Logger* GetInstance();

	// log the given message to a file at the given log level
	void LogToFile(LoggingStatus level, const char* msg);
	// log the given message to the console at the given log level
	void LogToConsole(LoggingStatus level, const char* msg);

protected:
	std::string m_logFilename;

};

