#pragma once

#include <exception>
#include <string>

namespace clio {
	/// \brief Generic exception class that can be thrown by clio
	class Exception : public std::exception {
	public:
		Exception(const std::string& message) throw();

		virtual ~Exception() throw();

		inline virtual const char *what() const throw()	{
			return message_.c_str();
		}
	private:
		std::string message_;
	};
}