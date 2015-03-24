/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_COMMON_EXCEPTION_INCLUDED
#define RPGTOOLKIT_TRANS4_COMMON_EXCEPTION_INCLUDED

#include <exception>
#include <string>

namespace rpgtoolkit {

	/**
	* Generic exception class for use with Trans4.
	*/
	class Exception : public std::exception {
	public:

		Exception(std::string message) throw();

		virtual ~Exception() throw();

		inline virtual const char *what() const throw()	{
			return m_message.c_str();
		}

	private:

		std::string m_message;

	};

}

#endif
