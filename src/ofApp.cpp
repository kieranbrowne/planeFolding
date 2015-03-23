#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    step = 6.0 / (0.15*ofGetWidth());
    pos = -M_PI;
    numFolds = b;
    width = ofGetWidth();
    height = ofGetHeight();

    ofBackground(255,255,255);  ofSetBackgroundAuto(false);
    ofSetColor(50,50,50);    ofNoFill(); 
    remove("data");
    for(int i=0;i<numFolds;i++) {
        folds[i] = floor(ofRandom(4.99)); //chooses fold type
    }
    cout << folds[0] << endl;
}

//--------------------------------------------------------------
void ofApp::update(){}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBeginShape();
    for(int f = 0; f < 1; f++) {
        bool first = true;
        int currentDraw;
        for(float i=-M_PI;i<=M_PI;i+=step) {
            if(first) {currentDraw = 0; first = false;} else {currentDraw = 1;}
            setFold(i,pos,currentDraw);         
        }
        pos += step;
    }
    ofEndShape();
    if(pos > M_PI) { 
        ofSleepMillis(1000);
        ofExit();
    }
}

//--------------------------------------------------------------
void ofApp::setFold(float x, float y, int currentDraw){
    ofVec2f v;
    v.set(x,y);
    ofVec2f newv = recursiveFold(v,0);
    fold.draw(newv,currentDraw);
}

//--------------------------------------------------------------
ofVec2f ofApp::recursiveFold(ofVec2f v, int r){
    if (r < numFolds) {
        ofVec2f newv = fold.getFoldByNum(folds[r],v);
        recursiveFold(newv, r+1);
    } else return v;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
