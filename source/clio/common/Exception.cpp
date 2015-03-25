#include "common/Exception.h"

using namespace clio;

Exception::Exception(std::string message) : m_message(message) {

}

Exception::~Exception() throw() {

}