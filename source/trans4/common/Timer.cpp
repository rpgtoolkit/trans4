/// \copyright
///
/// See LICENSE.md in the distribution for the full license text including,
/// but not limited to, a notice of warranty and distribution rights.

#include "common/Timer.hpp"

typedef std::chrono::high_resolution_clock Time;
typedef std::chrono::duration<double> duration;

namespace rpgtoolkit {

	Timer::Timer(bool start) {
		if (start) {
			Reset();
		}
	}

	Timer::~Timer() {
	}

	const double Timer::Reset() {
		double elapsed = Elapsed();

		start_ = Time::now();

		return elapsed;
	}

	const double Timer::Elapsed() const {
		duration d = Time::now() - start_;

		return d.count();
	}
}