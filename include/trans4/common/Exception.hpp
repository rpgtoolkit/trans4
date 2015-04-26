/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_COMMON_EXCEPTION_INCLUDED
#define RPGTOOLKIT_TRANS4_COMMON_EXCEPTION_INCLUDED

#include <exception>
#include <string>

namespace rpgtoolkit {

	/// \brief Generic exception class that can be thrown by TK4
	struct Exception : public std::exception {

		Exception(const std::string& message) throw();

		virtual ~Exception() throw();

		inline virtual const char *what() const throw()	{
			return message_.c_str();
		}

	private:

		std::string message_;

	};
}

#endif