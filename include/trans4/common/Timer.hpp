/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#ifndef RPGTOOLKIT_TRANS4_COMMON_TIMER_INCLUDED
#define RPGTOOLKIT_TRANS4_COMMON_TIMER_INCLUDED

#include <chrono>
#include <cstdint>

namespace rpgtoolkit {

	struct Timer {
		explicit Timer(bool start = false);

		virtual ~Timer();

		const double Reset();

		const double Elapsed() const;

	protected:
		std::chrono::high_resolution_clock::time_point start_;
	};
}

#endif