#pragma once
#include "Cat.h"

class OldLady {

private:
	int tinitial;
	int x;
	int y;
	int width;
    int height;
	static const int SPEED = 10;
	int red;
    int green;
    int blue;
	bool caught;
	int points;
	bool right;
	int cats;

public:
	OldLady();
	int getX();
    int getY();
    int getWidth();
    int getHeight();
	int getRed();
    int getGreen();
    int getBlue();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	bool touchCat(Cat c);	
	bool isCaught(Cat cat);
	bool typeCat(Cat cat);
	int score(Cat cat);
	
};