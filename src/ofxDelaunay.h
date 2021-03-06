/*
 *  ofxDelaunay.h
 *
 *  Created by Pat Long on 29/10/09.
 *  Copyright 2009 Tangible Interaction. All rights reserved.
 *
 *  Some parts based on demo code by Gilles Dumoulin. 
 *  Source: http://local.wasp.uwa.edu.au/~pbourke/papers/triangulate/cpp.zip
 *
 *	Cleaned up by Lukasz Karluk, 19/05/2010
 *
 *  Refactored for 0071 + ofMesh by James George on 21/06/2012
 */

#pragma once

#include "ofMain.h"
#include "Delaunay.h"

struct XYZI{
	double x, y, z;
	int i; // index
};

int XYZICompare(const void *v1, const void *v2);

class ofxDelaunay {
    
public:
    
    void reset(ofColor colorTriangle_);
	
	int addPoint( const ofPoint& point );
	int addPoint( float x, float y, float z);
	int addPoints( vector<ofPoint>& points );

	ofPoint getPointNear(ofPoint pos, float minDist, int & index); //returns actual point AND index to point
	ITRIANGLE getTriangleForPos(ofPoint pos); //returns ITRIANGLE(0,0,0) if none found!
	void removePointAtIndex(int index); //invalidates triangles and mesh
	void setPointAtIndex(ofPoint p, int index); //invalidates mesh
	vector<ofPoint> getPointsForITriangle(ITRIANGLE t);
	int getNumTriangles();
	int getNumPoints();
	ITRIANGLE getTriangleAtIndex(int index);
    void setColor(ofColor colorTriangle_, float opacityGrid_, ofImage input_, ofImage maskGrid_);
    void addColor(ofColor colorTriangle_, float opacityGrid_, ofImage input_, ofImage maskGrid_);

	void drawThickness(float thickness);
	void drawQuad(ofPoint a, ofPoint b, ofColor colorA, ofColor colorB, float thickness);
    int  triangulate();
	void draw();
	
    ofVboMesh triangleMesh; //output of triangulate();
	vector<ofVboMesh> thickMeshes;
    ofColor colorTriangle;


private:

	    vector<XYZI> vertices; //only input of triangulate();
		vector<ITRIANGLE> triangles; //output of triangulate();
		int ntri; //# tri

	
};


