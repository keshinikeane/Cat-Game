#include "Cat.h"
#include <cstdlib>
#include <ctime>


Cat::Cat() {
	// variables
	tinitial = time(NULL);
}

int Cat::getTime() {
	tfinal = time(NULL);
	return tfinal;
}

int Cat::getX() {
	if (catTime()==0) {
		x = rand() % 801;
	}
		return x;
}

int Cat::getY() {
	if (catTime()==0) {
		y = rand() % 601;
	}
		return y;
}

int Cat::getColor() {
	if (catTime()==0) {
		int color = rand() % 801;
		if (color % 2 == 0) {
			red = 214;
			green = 135;
			blue = 23;
		} else {
			red = 188;
			green = 188;
			blue = 188;
		}
	}
		return red;
}

int Cat::catTime() {
	tfinal = getTime();
	if (abs(tfinal-tinitial)<3) {
		isTime = 1;
	} else if ((tfinal-tinitial)==3) {
		tinitial = tfinal + 4;
		isTime = 3;
	} else {
		isTime = 0;
	}
	return isTime;
}
