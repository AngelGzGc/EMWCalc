/*
 * CameraMgr.cpp
 *
 *  Created on: Jan 29, 2016
 *      Author: angel
 */

#include "CameraMgr.h"
#include "Camera.h"

CameraMgr::CameraMgr() {
	// TODO Auto-generated constructor stub
	Cam = new Camera();
	SetDefaultConfig();
}

CameraMgr::~CameraMgr() {
	// TODO Auto-generated destructor stub
	delete(Cam);
}

void CameraMgr::SetDefaultConfig(){
	setProjectionPers();
}

void CameraMgr::ChangeViewsize(int Width_, int Height_){
	Cam->ChangeViewsize(Width_, Height_);
}

Camera* CameraMgr::getCamera(){
	return Cam;
}

void CameraMgr::setProjectionOrtho(){

	/*gluLookAt(	199.99, 600.0, 199.99,
						SIZE_X/2.0f, 0.0f,  SIZE_Y/2.0f,
						0.0f, -1.0f,  -1.0f);
						*/
	Cam->setProjection(ORTHOGRAPHIC);
	Cam->UpdateProjection();

	Cam->setUps(0.0f, 0.0f, -1.0f);
	Cam->setPos(200.0f, 600.0f, 200.0f);
}

void CameraMgr::setProjectionPers(){
	Cam->setAngles(3.15*45/180, 3.15*45/180);
	Cam->setDistance(1000.0f);
	Cam->setRefs(200.0f, 0.0f, 200.0f);
	Cam->setUps(0.0f, 1.0f, 0.0f);
	//Cam->setUps(1.0f, 0.0f, 0.0f);
	Cam->setProjection(PERSPECTIVE);
	Cam->UpdateProjection();
}
