#pragma once

#include <cstdint>

namespace tk4 {
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