#ifndef SICT_TAXABLE_H
#define SICT_TAXABLE_H

namespace sict {

	class Taxable {

		float rate = 0.0f;

		public:
		Taxable(float r) : rate(r) { }
		float operator()(float p) {
			return (1 + rate) * p;
		}
	};

}

#endif
