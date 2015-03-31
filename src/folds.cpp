#include "folds.h"

Folds::Folds()
{
    w = ofGetWidth();
    h = ofGetHeight();
    b = 10; // border
}

// -------------------------------
void Folds::draw(ofVec2f v, int currentDraw)
{
    // +/-pi --> screen values
    float i = ofMap(v.x, -M_PI, M_PI, 0+b, w-b, true);
    float j = ofMap(v.y, -M_PI, M_PI, 0+b, h-b, true);
    ofVertex(i,j);

    float i2 = ofMap(v.x, -M_PI, M_PI, 55, 97, true);
    float j2 = ofMap(v.y, -M_PI, M_PI, 65, 107, true);

    // write machine data
    ofstream file;
    file.open("data", ios::out | ios::app);
    file << ofToString(i2,2) << " "
         << ofToString(j2,2) << " "
         << ofToString(currentDraw) << endl;
    file.close();
}

// -------------------------------
ofVec2f Folds::getFoldByNum(int num, ofVec2f v){
    switch(num){
        case 0: return sine(v); break;
        case 1: return butterfly(v); break;
        case 2: return pinch(v); break;
        case 3: return bulge(v); break;
        case 4: return rosette(v); break;
        case 5: return hourglass(v); break;
        case 6: return jupitermission(v); break;
        case 7: return perspective(v); break;
        case 8: return gravity(v); break;
        case 9: return creasel(v); break;
        case 10: return creaser(v); break;
        case 11: return staircase(v); break;
        default: cout << "ERROR in getFoldByNum" << endl; return v; break;
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
// -------------------------------
ofVec2f Folds::hourglass(ofVec2f v){
    v.set(v.x*sin(v.y*0.7),v.y);
    return v;
}
// -------------------------------
ofVec2f Folds::jupitermission(ofVec2f v){
    v.set(v.x,v.x*cos(v.y));
    return v;
}
// -------------------------------
ofVec2f Folds::perspective(ofVec2f v){
    float newvy = (v.y-v.x*tan(v.y*0.16)-0.8)/1.7;
    v.set(v.x,newvy);
    return v;
}
// -------------------------------
ofVec2f Folds::gravity(ofVec2f v){
    float newvy = (v.y-v.x*tan(v.x*0.18)-1)/1.3;
    v.set(v.x,newvy);
    return v;
}
// -------------------------------
ofVec2f Folds::creasel(ofVec2f v){
    float newvy = (v.y-v.x*floor(v.x*0.18)-1)/1.7;
    v.set(v.x,newvy);
    return v;
}
// -------------------------------
ofVec2f Folds::creaser(ofVec2f v){
    float newvy = (v.y-v.x*ceil(v.x*0.18)-1)/1.7;
    v.set(v.x,newvy);
    return v;
}
// -------------------------------
ofVec2f Folds::staircase(ofVec2f v){
    float newvy = (v.y-round(v.x*2))/4.0;
    v.set(newvy,v.x);
    return v;
}

