#include "folds.h"

Folds::Folds()
{
    w = ofGetWidth();
    h = ofGetHeight();
    b = 10; // border
}

// -------------------------------
void Folds::draw(ofVec2f v)
{
    // +/-pi --> screen values
    float i = ofMap(v.x, -M_PI, M_PI, 0+b, w-b);
    float j = ofMap(v.y, -M_PI, M_PI, 0+b, h-b);
    ofVertex(i,j);
}

// -------------------------------
ofVec2f Folds::getFoldByNum(int num, ofVec2f v){
    switch(num){
        case 0: return sine(v);
        case 1: return butterfly(v);
        case 2: return pinch(v);
        case 3: return bulge(v);
        case 4: return rosette(v);
        default: return v;
    }
}

// -------------------------------
ofVec2f Folds::sine(ofVec2f v){
    v.set(sin(v.x),sin(v.y));
    v *= M_PI;
    return v;
}
// -------------------------------
ofVec2f Folds::butterfly(ofVec2f v){
    float r = 1.707963267149069 * (sqrt(abs(v.y * v.x) / (pow(v.x,2) + pow(2*v.y,2))));
    v.set(r * v.x, r* v.y);
    return v;
}
// -------------------------------
ofVec2f Folds::pinch(ofVec2f v){
    float d = ofDist(0,0,v.x,v.y)/4.4428829381583661;
    v.set(d * v.x,d * v.y);
    return v;
}
// -------------------------------
ofVec2f Folds::rosette(ofVec2f v){
    float d = 1 - (ofDist(0,0,v.x,v.y)/4.4428829381583661);
    d *= 2.8;
    v.set(d*v.x,d*v.y);
    return v;
}
// -------------------------------
ofVec2f Folds::bulge(ofVec2f v){
    float d = 2 - (ofDist(0,0,v.x,v.y)/4.4428829381583661);
    d /= 2;
    d *= 1.41421356237;
    v.set(d*v.x,d*v.y);
    return v;
}

