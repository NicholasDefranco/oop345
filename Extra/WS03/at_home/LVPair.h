#ifndef SICT_LVPAIR_H
#define SICT_LVPAIR_H

#include <iostream>
#include <iomanip>

namespace sict {

	template<typename L, typename V>
	class LVPair {

		L label;
		V value;
		bool empty;

		public:

		LVPair() : empty(true) { }

		LVPair(const L& label, const V& value) : empty(false) {
			this->label = label;
			this->value = value;
		}

		virtual void display(std::ostream& os) const {
			if(!empty) {
				os << label << " : " << value << std::endl;
			}
		}

		V getValue() const {
			return value;
		}

	};

	template<typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair) {
		pair.display(os);
		return os;
	}

	template<typename L, typename V>
	class SummableLVPair : public LVPair<L, V> {

		static V value;
		static size_t width;

		public:
		SummableLVPair() : LVPair<L, V>() { }
		SummableLVPair(const L& label, const V& value) : LVPair<L, V>(label, value) {
			if(width < label.size()) {
				width = label.size();
			}
			
		}

		static const V& getInitialValue() {
			return value;
		}

		V sum(const L& label, const V& s) const {
			return this->getValue() + s;
		}

		void display(std::ostream& os) const {
			os << std::left;
			os.width(width);
			LVPair<L, V>::display(os);
			os.unsetf(std::ios::left);
		}

	};

	template<typename L, typename V>
	V SummableLVPair<L, V>::value;

	template<typename L, typename V>
	size_t SummableLVPair<L, V>::width = 0;

	template<>
	SummableLVPair<std::string, int>::SummableLVPair(const std::string& label, const int& value) : LVPair<std::string, int>(label, value) {
		this->value = 0;
		if(width < label.size()) {
			width = label.size();
		}
	}

	template<>
	SummableLVPair<std::string, std::string>::SummableLVPair(const
	std::string& label, const std::string& value) : LVPair<std::string, std::string>(label, value) {
		this->value = "";
		if(width < label.size()) {
			width = label.size();
		}
	}

	template<>
	std::string SummableLVPair<std::string, std::string>::sum(const
	std::string& label, const std::string& s) const {
		return s + " " + this->getValue();
	}
}

#endif
