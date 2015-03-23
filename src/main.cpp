#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( int argc, char *argv[] ){

	ofSetupOpenGL(600,600, OF_WINDOW);
    ofApp *app = new ofApp();
    app->a = ofToFloat(argv[1]);
    app->b = ofToFloat(argv[2]);
    ofRunApp( app );
}
