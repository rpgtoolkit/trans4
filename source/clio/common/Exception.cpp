#include "common/Exception.hpp"

using namespace clio;

Exception::Exception(const std::string& message) throw()
	: message_(message) {

}

Exception::~Exception() throw() {

}