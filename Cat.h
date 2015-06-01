#pragma once
#include <ctime>


class Cat {

private:
	int x;
	int y;
	static const int SIZE = 20;
	int red;
    int green;
    int blue;
	int tinitial;
	int tfinal;
	int isTime;

public:
	Cat();
	int getX();
    int getY();
	int getTime();
	int getColor();
	int catTime();
};