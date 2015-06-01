#ifndef _TEST_APP
#define _TEST_APP



class testApp : public ofBaseApp{

	public:
		ofTrueTypeFont arialFontSmall;
		ofTrueTypeFont arialFontLarge;
		ofImage kitten;
		ofImage grandma;
		ofImage winner;
		ofImage loser;

		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void drawCat();
		void drawOldLady();


};

#endif
