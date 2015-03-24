/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include <trans4/common/Exception.hpp>

namespace rpgtoolkit {

  Exception::Exception(std::string message) throw()
    : m_message(message) {

  }

  Exception::~Exception() throw() {

  }

}
