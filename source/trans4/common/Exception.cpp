/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include "common/Exception.hpp"

namespace rpgtoolkit {

	Exception::Exception(const std::string& message) throw()
		: message_(message) {

	}

	Exception::~Exception() throw() {

	}
}