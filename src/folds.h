#ifndef _FOLDS
#define _FOLDS

#include "ofMain.h"
#include <math.h>

class Folds
{
    public:
        void draw(ofVec2f v, int currentDraw);
        ofVec2f getFoldByNum(int num, ofVec2f v);
        
        //folds
        ofVec2f sine(ofVec2f v);
        ofVec2f butterfly(ofVec2f v);
        ofVec2f pinch(ofVec2f v);
        ofVec2f bulge(ofVec2f v);
        ofVec2f rosette(ofVec2f v);

        int w,h,b;

        Folds(); // constuctor
        
};

#endif
