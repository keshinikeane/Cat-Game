#include "testApp.h"
#include <string>
#include "OldLady.h"
#include "Cat.h"
#include <sstream>


//Global variables
OldLady oldlady;
Cat cat;
int x = cat.getX();
int currentScore=0;
int initialScore=0;

//Drawing function
void drawOldLady();
void drawCat();

void testApp::setup() {
	ofBackground(0,153,0);
	arialFontSmall.loadFont("arial.ttf", 16);
	arialFontLarge.loadFont("arial.ttf", 32);
	ofSetFrameRate(30);
	ofSetVerticalSync(true);
	if(!kitten.loadImage("cat.jpg")){
		ofLog(OF_LOG_ERROR,"Error while loading image");
	}
	if(!grandma.loadImage("grandma.jpg")){
		ofLog(OF_LOG_ERROR,"Error while loading image");
	}
	if(!winner.loadImage("win.jpg")){
		ofLog(OF_LOG_ERROR,"Error while loading image");
	}
	if(!loser.loadImage("lose.jpg")){
		ofLog(OF_LOG_ERROR,"Error while loading image");
	}
}

void testApp::update() {

}

bool showCat() {
	bool showCat = false;
	if (cat.catTime()==1) {
		if (oldlady.isCaught(cat)) {
			showCat = false;
		} else {
			showCat = true;
		}
	}
	return showCat;
}


void testApp::draw() {
	if (currentScore<0) {
		loser.draw(0,0,800,600);
		ofSetColor(255,255,255);
		arialFontLarge.drawString("You died :(", 250, 280);
	} else if (currentScore==5) {
		winner.draw(0,0,800,600);
	} else {

	cat.getColor();
	cat.getX();
	cat.getY();

	if (cat.catTime()==0) {
		oldlady.isCaught(cat);
	}

	if (showCat()) {
		drawCat();
	}

	if (cat.getX()!=x) {
		currentScore = oldlady.score(cat);
		if (currentScore>initialScore) {
			x = cat.getX();
			initialScore = currentScore;
		}
	}

	stringstream ss;
	ss << currentScore;
	string str = ss.str();
	ofSetColor(255,255,255);
	arialFontSmall.drawString("Cats caught: " + str + "/5", 600, 580);

	drawOldLady();
	}

}

void testApp::keyPressed(int key) {
		// tell grandma to move up
	if (key == OF_KEY_UP) {
		oldlady.moveUp();
		// move down
    } else if (key == OF_KEY_DOWN) {
		oldlady.moveDown();
		// move right
    } else if (key == OF_KEY_RIGHT) {
		oldlady.moveRight();
		// move left
    } else if (key == OF_KEY_LEFT) {
		oldlady.moveLeft();
		// tell grandma to catch cat
    } else if (key == ' ') {
		oldlady.isCaught(cat);
    }
}



void testApp::keyReleased(int key) {

}


void testApp::mouseMoved(int x, int y) {

}


void testApp::mouseDragged(int x, int y, int button) {

}


void testApp::mousePressed(int x, int y, int button) {

}


void testApp::mouseReleased(int x, int y, int button) {

}


void testApp::windowResized(int w, int h) {

}

void testApp::drawOldLady() {
	grandma.draw(oldlady.getX(),oldlady.getY(),60,60);
}


void testApp::drawCat() {
	if (showCat()) {
		if (cat.getColor()==188) {
			ofSetColor(188,188,188);
		} else {
			ofSetColor(214,135,23);
		}
		kitten.draw(cat.getX(),cat.getY(),60,60);
	}
}


