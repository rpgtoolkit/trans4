/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_SYSTEM_TIMER_INCLUDED
#define RPGTOOLKIT_TRANS4_SYSTEM_TIMER_INCLUDED

#include <cstdint>

namespace rpgtoolkit {

	class Timer {

	public:

		Timer();

		void start();

		void reset();

		uint32_t elapsed();

		virtual ~Timer();

		/**
		* No copying allowed.
		*/
		Timer(Timer const&) = delete;

		/**
		* No copying allowed.
		*/
		Timer & operator=(Timer const&) = delete;

	protected:

		uint32_t m_start;

	};
}

#endif
