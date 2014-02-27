#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
    ofEnableAlphaBlending();
    float wxh[2]={ofGetScreenWidth(),ofGetScreenHeight()};
    
    mLine.setMode(OF_PRIMITIVE_LINE_STRIP);
    mLine.addVertex(ofVec3f(0,0,0));
    for(int i = 0; i < 500; i++)
    {
        mLine.addVertex(ofVec3f(ofRandom(1000)-500,ofRandom(1000)-500,ofRandom(1000)-500));
    }
//    mRect.addTexCoord(ofVec2f(0,0));
//    mRect.addVertex(ofVec3f(0,wxh[1],0));
//    mRect.addVertex(ofVec3f(wxh[0],0,0));
//    mRect.addVertex(ofVec3f(wxh[0],wxh[1],0));
    
    
    ofLog(OF_LOG_NOTICE, "created Geo...");
    
	ofSetFrameRate(60);
	ofBackground(0, 0, 0);
	ofSetVerticalSync(false);

//	windowResized(ofGetWidth(), ofGetHeight());		// force this at start (cos I don't think it is called)
	
	ofEnableAlphaBlending();
	ofSetBackgroundAuto(false);
}


void testApp::update()
{

}

void testApp::draw()
{
    ofBackground(0,0,0);
    ofEnableAlphaBlending();
    ofEnableNormalizedTexCoords();
    
    ofPushMatrix();
    
    ofPushMatrix();
    ofTranslate(ofGetScreenWidth()/2,ofGetScreenHeight()/2,0);
    ofRotateX(ofGetElapsedTimef());
    ofRotateY(ofGetElapsedTimef());
    ofRotateZ(ofGetElapsedTimef());
    ofSetColor(255,255,255,255);
    mLine.draw();

    ofPopMatrix();

    ofPopMatrix();
}


void testApp::keyPressed  (int key)
{
    switch(key)
    {
		case 'f':
			ofToggleFullscreen();
			break;
        
        case '1':
			break;
        case '2':
			break;
        case '3':
			break;
        case '4':
			break;
        case 'w':
			break;
        case 'q':
			break;
        default:
            break;
    }
}


//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y)
{

}

void testApp::mouseDragged(int x, int y, int button)
{

}

