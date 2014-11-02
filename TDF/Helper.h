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

	int snap(bool up, int grid, int pose) {
		double temp1 = pose / grid;
		double temp2;
		if (up == true) {
			temp2 = ceil(temp1);
		}
		if (up == false) {
			temp2 = floor(temp1);
		}
		double temp3 = temp2 * grid;
		double out = temp3;
		return static_cast<int>(out);
	}

	int getLarge(int a[]) {
		int mem = a[0];
		for (int x = 1; x < sizeof(a); x++) {
			if (mem < a[x]) {
				mem = a[x];
			}
		}
		return mem;
	}

	int getSmall(int a[]) {
		int mem = a[0];
		for (int x = 1; x < sizeof(a); x++) {
			if (mem > a[x]) {
				mem = a[x];
			}
		}
		return mem;
	}

	double getAv(int a[]) {
		int mem = 0;
		for (int x = 0; x < sizeof(a); x++) {
			mem =+ a[x];
		}
		return mem / sizeof(a);
	}

	void sense(int mnsize, int mxsize, int xT, int yT, int xL, int yL) {
		if (xT != xL + mnsize || yT != yL) {
			if (xT > xL && yT > yL) {
			}
			if (xT < xL && yT > yL) {
			}
			if (xT > xL && yT < yL) {
			}
			if (xT < xL && yT < yL) {
			}
			if (xT < xL && yT == yL) {
			}
			if (xT > xL && yT == yL) {
			}
			if (xT == xL && yT < yL) {
			}
			if (xT == xL && yT > yL) {
			}
		}
		if (xT == xL && yT == yL) {
		}
	}

}
#endif