#include "AllHeaders.h"

#ifndef __HELPER_H_INCLUDED__
#define __HELPER_H_INCLUDED__

namespace Helper{
	int rand(int min, int max) {
		std::random_device rd;
		std::mt19937 eng(rd());
		std::uniform_int_distribution<> distr(min, max);

		return distr(eng);
	}

	int snap(int grid, double pose){
		double temp1 = pose / grid;
		double temp2 = ceil(temp1);
		int out = temp2 * grid;
		return out;
	}
}
#endif