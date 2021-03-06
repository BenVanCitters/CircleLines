#pragma once

#include "ofMain.h"

#define SPHERE_ARC_COUNT 8
class testApp : public ofBaseApp
{
public:
	void setup();
	void update();
	void draw();
	
	void keyPressed  (int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
    
    bool mShowFrameRate;
    
    ofVec3f arcRotation;
    ofVec4f mArcRotRateXYPlane[SPHERE_ARC_COUNT];
    ofVboMesh mSphereArcs[SPHERE_ARC_COUNT];
    
    int mLinesHCount;
    int mLinesWCount;
    ofVec3f lineRotation;
    ofVboMesh mLine;
};