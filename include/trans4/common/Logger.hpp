/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_COMMON_LOGGER_INCLUDED
#define RPGTOOLKIT_TRANS4_COMMON_LOGGER_INCLUDED

#include <cstdio>
#include <cstdarg>
#include <string>

namespace rpgtoolkit {

	struct Logger {

		Logger(const std::string logfile);

		~Logger();

		void Print(const char* file, int line, const char* message, std::va_list args);

	private:

		std::FILE* log_file_;

	};

	void Log(Logger* log, const char* file, int line, const char* message, ...);

	//__FILE__ and __LINE__ will correspond to where the macro is being called from
#define LOG(logger, msg, ...) Log(logger, __FILE__, __LINE__, msg, ##__VA_ARGS__)

}

#endif
