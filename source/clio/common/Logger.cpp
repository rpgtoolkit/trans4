#include <map>

#include "common/Logger.h"

using namespace clio;

void clio::Log(Logger* log, const char* file, int line, const char* message, ...) {
	std::va_list args;
	va_start(args, message);
	log->Print(file, line, message, args);
	va_end(args);
}

static std::map<std::string, FILE*> logs;

Logger::Logger(std::string filename) {
	auto log = logs.find(filename);

	//If the log already exists, we append to the file.
	//Otherwise we overwrite the previous file if it were
	//to exist
	if (log == logs.end()) {
		m_logFile = std::fopen(filename.c_str(), "w");
		logs[filename] = m_logFile;
	}
	else {
		m_logFile = log->second;
	}	
}

Logger::~Logger() {
	if (m_logFile != nullptr) {
		std::fclose(m_logFile);
	}
}

void Logger::Print(const char* file, int line, const char* message, std::va_list args) {
	fprintf(m_logFile, "%s, %d: ", file, line);
	vfprintf(m_logFile, message, args);
	fprintf(m_logFile, "\n");
	fflush(m_logFile);
}