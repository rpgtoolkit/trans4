/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include <map>
#include "common/Logger.hpp"

namespace rpgtoolkit {

	void Log(Logger* log, const char* file, int line, const char* message, ...) {
		std::va_list args;
		va_start(args, message);
		log->Print(file, line, message, args);
		va_end(args);
	}

	static std::map<std::string, FILE*> logs;

	Logger::Logger(const std::string filename) {
		auto log = logs.find(filename);

		//If the log already exists, we append to the file.
		//Otherwise we overwrite the previous file if it were
		//to exist
		if (log == logs.end()) {
			log_file_ = std::fopen(filename.c_str(), "w");
			logs[filename] = log_file_;
		}
		else {
			log_file_ = log->second;
		}
	}

	Logger::~Logger() {
		if (log_file_ != nullptr) {
			std::fclose(log_file_);
		}
	}

	void Logger::Print(const char* file, int line, const char* message, std::va_list args) {
		fprintf(log_file_, "%s, %d: ", file, line);
		vfprintf(log_file_, message, args);
		fprintf(log_file_, "\n");
		fflush(log_file_);
	}
}
