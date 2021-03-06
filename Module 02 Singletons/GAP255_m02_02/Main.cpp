#include <conio.h>
#include "Logger.h"

/*
Instructions:

	1) refactor and complete the Logger class
	2) make it a proper singleton
*/
int main()
{
	Logger::GetInstance()->LogToConsole(Logger::LoggingStatus::INFO, "I want to see this in INFO");
	Logger::GetInstance()->LogToConsole(Logger::LoggingStatus::DEBUG, "And this in DEBUG");
	Logger::GetInstance()->LogToConsole(Logger::LoggingStatus::ERROR, "Send the ERROR to the console also");

	Logger::GetInstance()->LogToFile(Logger::LoggingStatus::INFO, "Let's see this in INFO in a FILE");
	Logger::GetInstance()->LogToFile(Logger::LoggingStatus::ERROR, "Something wrong occurred.  Log to the file");

	_getch();
}