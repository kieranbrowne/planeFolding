#pragma once

#include "ofMain.h"
#include "folds.h"
#include <iostream>
#include <math.h>
using namespace std;

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
        void setFold(float x, float y, int currentDraw);
        ofVec2f recursiveFold(ofVec2f v, int r);
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        float a,b; // args

        int folds [9];
        Folds fold;

        float step;
        float pos;
        int numFolds;
        int width;
        int height;
        bool hascanvas;
};
