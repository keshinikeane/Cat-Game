/* CSCI261 Final Project
 *
 * Author: YOUR NAME
 *
*/
#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"



int main() {
	const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;
    ofAppGlutWindow window;
	ofSetupOpenGL(&window, WINDOW_WIDTH, WINDOW_HEIGHT, OF_WINDOW);
	ofRunApp( new testApp());
}
