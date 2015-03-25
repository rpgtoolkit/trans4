#include "common/Timer.hpp"

namespace clio {

	typedef std::chrono::high_resolution_clock Time;
	typedef std::chrono::duration<double> duration;

	Timer::Timer(bool start) {
		if (start) {
			Reset();
		}
	}

	Timer::~Timer() {

	}

	double Timer::Reset() {
		double elapsed = Elapsed();

		m_start = Time::now();

		return elapsed;
	}

	double Timer::Elapsed() const {
		duration d = Time::now() - m_start;

		return d.count();
	}
}