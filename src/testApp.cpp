#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
    ofEnableAlphaBlending();
//    float wxh[2]={ofGetScreenWidth(),ofGetScreenHeight()};
    
    mLine.setMode(OF_PRIMITIVE_LINE_STRIP);
    int vertCount = 100;
    float numberOfSwirls = 3.3;
    float swirlRadius = 10.f;
    float totalSwirlHeight = 300.f;
    for(int i = 0; i < vertCount; i++)
    {
        float curRadian = numberOfSwirls*i*M_PI*2/(vertCount-1);
        mLine.addVertex(ofVec3f(swirlRadius*cos(curRadian),
                                i*totalSwirlHeight/(vertCount-1),
                                swirlRadius*sin(curRadian)));
    }

    
    
    ofLog(OF_LOG_NOTICE, "created Geo...");
    
	ofSetFrameRate(60);
	ofBackground(0, 0, 0);
	ofSetVerticalSync(false);

//	windowResized(ofGetWidth(), ofGetHeight());		// force this at start (cos I don't think it is called)
	
//	ofEnableAlphaBlending();
	ofSetBackgroundAuto(false);
}


void testApp::update()
{

}

void testApp::draw()
{
    ofBackground(0,0,0);
    ofEnableAlphaBlending();
//    ofEnableNormalizedTexCoords();
    
    ofPushMatrix();
    
    ofPushMatrix();
    ofSetLineWidth(1);
    ofTranslate(ofGetScreenWidth()/2,ofGetScreenHeight()/2,0);
    float tm = ofGetElapsedTimef();
//    ofRotateX(tm);
//    ofRotateY(tm);
//    ofRotateZ(tm);
    
    
    int hCount = 30;
    int wCount = 30;
    for(int i = 0; i < hCount; i++)
    {
        for(int j = 0; j < wCount; j++)
        {
            ofPushMatrix();
                ofSetColor(255,255,255,255);
                ofRotateY(j*180*2.f/wCount);
                ofRotateX((i+.5)*180.f/hCount);
                ofRotateY(tm*40);
                ofTranslate(0, 200);
                mLine.draw();
            ofPopMatrix();
        }
    }
    ofPopMatrix();
    ofPopMatrix();

    stringstream s;
    s <<"FPS: " << ofGetFrameRate();
    string fps = s.str();
    ofDrawBitmapString(fps, 50,50);

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

