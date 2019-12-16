#ifndef SICT_TIMEKEEPER_H
#define SICT_TIMEKEEPER_H

#include <iostream>
#include <chrono>

namespace sict {

	const int MAX_RECORDS {10};

	class Timekeeper {
		unsigned no {0U};
		std::chrono::steady_clock::time_point strt;
		std::chrono::steady_clock::time_point endt;
		typedef struct {
			char *msg = nullptr;
			char *unit = nullptr;
			std::chrono::steady_clock::duration duration;

		} record;
		record records[MAX_RECORDS];

		public:
		Timekeeper();
		~Timekeeper();
		void start();
		void stop();
		void recordEvent(const char *);
		void report(std::ostream&) const;

	};

}

#endif
