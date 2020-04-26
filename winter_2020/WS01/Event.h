#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

namespace sdds {

	const int COUNT_WIDTH {3};
	const int NUM_WIDTH {2};

	class Event {
		char *desc {nullptr};
		size_t start {0ul};
		
		public:
		Event() = default;
		Event(const Event& e);
		Event& operator=(const Event& e);
		~Event();
		void display();
		void setDescription(char *d);
	};

}

#endif
