#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
    ofEnableAlphaBlending();
//    float wxh[2]={ofGetScreenWidth(),ofGetScreenHeight()};

    lineRotation = ofVec3f(.8+ofRandom(.4),.8+ofRandom(.4),.8+ofRandom(.4));
    mLinesHCount = 20;
    mLinesWCount = 20;
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

    
    arcRotation = ofVec3f(ofRandom(.8),ofRandom(.8),ofRandom(.8));
    int sVertCount = 70;
    for(int j = 0; j < SPHERE_ARC_COUNT; j++)
    {
        mSphereArcs[j].setMode(OF_PRIMITIVE_LINE_STRIP);
        float curRotation = ofRandom(360);
        float curRotationRate = ofRandom(.2);
        float curXRot = ofRandom(360);
        float curYRot = ofRandom(360);
        mArcRotRateXYPlane[j] = ofVec4f(curRotation,curRotationRate,curXRot,curYRot);
        //arclength will be less than a third of a complete rotation
        float arcLen = ofRandom(M_PI*2/4.f);
        float arcRadius = totalSwirlHeight + 300 + ofRandom(50);
        for(int i = 0; i < sVertCount; i++)
        {
            float curRadian = numberOfSwirls*i*arcLen/(sVertCount-1);
            mSphereArcs[j].addVertex(ofVec3f(arcRadius*cos(curRadian),
                                             arcRadius*sin(curRadian),
                                             0));
        }
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
    for(int i = 0; i < SPHERE_ARC_COUNT; i++)
    {
        mArcRotRateXYPlane[i].x += mArcRotRateXYPlane[i].y;
    }
}

void testApp::draw()
{
    ofBackground(0,0,0);
    ofEnableAlphaBlending();
//    ofEnableNormalizedTexCoords();
    
    ofPushMatrix();
    ofTranslate(ofGetScreenWidth()/2,ofGetScreenHeight()/2,0);
    ofPushMatrix();
    ofSetLineWidth(1);
    
    float tm = ofGetElapsedTimef();
    ofRotateX(lineRotation.x*tm);
    ofRotateY(lineRotation.y*tm);
    ofRotateZ(lineRotation.z*tm);

    //render lines
    float hXPansion = sin(tm/20.2);
    float wXPansion = sin(tm/30.33);
    
    for(int i = 0; i < mLinesHCount; i++)
    {
        for(int j = 0; j < mLinesWCount; j++)
        {
            ofPushMatrix();
            {
                ofSetColor(255,255,255,255);
                ofRotateY(wXPansion*j*180*2.f/mLinesWCount);
                ofRotateX(hXPansion*(i+.5)*180.f/mLinesHCount);
                ofRotateY(tm*40);
                ofTranslate(0, 200);
                float scale =8.5*(1+cos(tm/40.f+(j)/14.f));
                float scaleY =4.5*(1+cos(2+tm/32.f+(i)/60.f));
                ofScale(scale,scaleY ,scale);
                mLine.draw();
            }
            ofPopMatrix();
        }
    }
    ofPopMatrix();
    
    //render arcs
    ofPushMatrix();
    ofRotateX(arcRotation.x*tm);
    ofRotateY(arcRotation.y*tm);
    ofRotateZ(arcRotation.z*tm);
    ofSetLineWidth(6);
    for(int j = 0; j < SPHERE_ARC_COUNT; j++)
    {
        ofPushMatrix();
        //rotate into a plane
        ofRotateX(mArcRotRateXYPlane[j].w);
        ofRotateY(mArcRotRateXYPlane[j].z);
        
        ofRotateZ(mArcRotRateXYPlane[j].x);
        mSphereArcs[j].draw();
        ofPopMatrix();
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

