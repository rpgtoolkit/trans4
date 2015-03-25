#pragma once

#include <cstdio>
#include <cstdarg>
#include <string>

namespace clio {
	class Logger {
	public:
		Logger(std::string logfile);

		~Logger();

		void Print(const char* file, int line, const char* message, std::va_list args);
	private:
		std::FILE* m_logFile;
	};
	
	void Log(Logger* log, const char* file, int line, const char* message, ...);
	//__FILE__ and __LINE__ will correspond to where the macro is being called from
	#define LOG(logger, msg, ...) Log(logger, __FILE__, __LINE__, msg, ##__VA_ARGS__)
}