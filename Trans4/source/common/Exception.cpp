#include "common/Exception.h"

using namespace tk4;

Exception::Exception(std::string message) : m_message(message) {

}

Exception::~Exception() throw() {

}