#ifndef SICT_DATA_TABLE_H
#define SICT_DATA_TABLE_H

#include <iostream>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <fstream>
#include <deque>

namespace sict {

	template<typename T>
	class DataTable {

		struct coord {
			T x;
			T y;
		};

		std::deque<coord *> coords;

		public:
		DataTable(std::ifstream& file) {

			coord *tmp = nullptr;

			while(file) {
		
				try {
					tmp = new coord;
				} catch(std::bad_alloc) {
					std::cerr 
					<< "Insufficient memory" << std::endl;
					exit(1);
				}
				file >> tmp->x;
				if(file) {
					file >> tmp->y;
					if(file) {
						coords.push_back(tmp);
					}
				}

			}
		}
		~DataTable() {
			for(coord *t : coords) {
				delete t;
			}
		}
		void displayData(std::ostream& os) const {

			os << "Data Values" << std::endl;
			os << "------------" << std::endl;
			for(coord *t : coords) {
				os << std::setw(8) << std::setprecision(4)
				<< std::right << t->x << " " << t->y << std::endl;
			}
		}
		void displayStatistics(std::ostream& os) const {
			os << "Statistics" << std::endl;
			os << "----------" << std::endl;
			T mean = 0.0f;
			for(int i = 0; i < coords.size(); i++) {
				mean += coords[i]->y;
			}
			mean /= coords.size();
			os << "y mean = " << mean << std::endl;

			T sum = 0.0f;
			for(int i = 0; i < coords.size(); i++) {
				sum += (coords[i]->y - mean) * 
					(coords[i]->y - mean);
			}
			sum /= coords.size() - 1;
			sum = sqrt(sum);
			os << "y sigma = " << sum << std::endl;

		}

	};

}
#endif
