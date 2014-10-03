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
}
#endif