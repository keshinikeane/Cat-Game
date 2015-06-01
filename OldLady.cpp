#include "OldLady.h"
#include "Cat.h"
#include <cstdlib>

OldLady::OldLady() {
	//variables
	x=0;
	y=0;
	width = 60;
	height = 60;
	caught = false;
	points = 0;
}
// Determine the position of the old lady
int OldLady::getX() {
    return x;
}

int OldLady::getY() {
    return y;
}


// Movement of old lady
void OldLady::moveUp() {
    y -= SPEED;
}

void OldLady::moveDown() {
    y += SPEED;
}

void OldLady::moveLeft() {
    x -= SPEED;
}

void OldLady::moveRight() {
    x += SPEED;
}


// Catching the cat
// Determine whether the old lady is touching the cat
bool OldLady::touchCat(Cat c) {
    return ((x < c.getX() && x + width > c.getX()) &&
            (y < c.getY() && y + height > c.getY()));
}
// If the old lady is touching the cat before it disappears, it is caught.
bool OldLady::isCaught(Cat cat) {
	if (cat.catTime()==1) {
		if (touchCat(cat)) {
			caught = true;
		}
	} else {
		caught = false;
	}
	return caught;
}
// Determine whether the cat is the correct color
bool OldLady::typeCat(Cat cat) {
	if (cat.getColor()==188) {
		right = true;
	} else {
		right = false;
	}
	return right;
}
// Calculate the score when a cat is caught. If it is the correct color, one point is added. If it is the wrong color, the score is negative.
int OldLady::score(Cat cat) {
	if (isCaught(cat)) {
		if (typeCat(cat)) {
			++points;
		} else {
			points=-1;
		}
	}
	return points;
}


