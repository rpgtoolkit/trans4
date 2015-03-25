#pragma once

#include <chrono>
#include <cstdint>

namespace clio {
	class Timer {
	public:
		/**
		* Constructor.
		*/
		explicit Timer(bool start = false);

		/**
		* Destructor.
		*/
		virtual ~Timer();

		/**
		* Reset the timer's start time to now.
		*
		* @return Time elapsed before reset.
		*/
		double Reset();

		/**
		* Get the amount of time that has elapsed since start.
		*
		* @return Time elapsed.
		*/
		double Elapsed() const;

		/**
		* No copying allowed.
		*/
		Timer(Timer const&) = delete;

		/**
		* No copying allowed.
		*/
		Timer & operator=(Timer const&) = delete;
	protected:
		std::chrono::high_resolution_clock::time_point m_start;
	};
}