/*
 * Camera.cpp
 *
 *  Created on: Jan 29, 2016
 *      Author: angel
 */

#include "Camera.h"
#include <cmath>
#include <cstdio>

Camera::Camera() {
	// TODO Auto-generated constructor stub
	PosX = 0.0f;
	PosY = 0.0f;
	PosZ = 0.0f;

	RefX = 0.0f;
	RefY = 0.0f;
	RefZ = 0.0f;

	UpX = 0.0f;
	UpY = 0.0f;
	UpZ = 0.0f;

	Phi = 0.0f;
	Theta = 0.0f;
	Distance = 0.0f;

	Projection = PERSPECTIVE;
}

Camera::~Camera() {
	// TODO Auto-generated destructor stub

}



void Camera::setDistance( GLfloat Distance_){
	Distance = Distance_;
	UpdatePos();
	printf("Distance set: %.3f\n", Distance);
}

void Camera::setRefs( GLfloat RefX_, GLfloat RefY_, GLfloat RefZ_){
	RefX = RefX_;
	RefY = RefY_;
	RefZ = RefZ_;
	UpdatePos();
}

void Camera::setAngles(GLfloat Phi_, GLfloat Theta_){
	Theta = Theta_;
	Phi = Phi_;
	printf("Phi set: %.3f\n", Phi);
	printf("Theta set: %.3f\n", Theta);
	UpdatePos();
}

void Camera::setUps(GLfloat UpX_, GLfloat UpY_, GLfloat UpZ_){
	UpX = UpX_;
	UpY = UpY_;
	UpZ = UpZ_;
	UpdatePos();
}

void Camera::setViewsize(int Width_, int Height_){
	Width = Width_;
	Height = Height_;
}

void Camera::setPos(GLfloat PosX_, GLfloat PosY_, GLfloat PosZ_){
	PosX = PosX_;
	PosY = PosY_;
	PosZ = PosZ_;

}


void Camera::UpdatePos(){

	PosX = RefX + Distance*cos(Phi)*cos(Theta);
	PosY = RefY + Distance*sin(Theta);
	PosZ = RefZ + Distance*sin(Phi)*cos(Theta);

	printf("PosX: %.2f, PosY: %.2f, PosZ: %.2f\n", PosX, PosY, PosZ);
}

void Camera::getLookAt(){
	gluLookAt(	PosX, PosY, PosZ,
				RefX, RefY, RefZ,
				UpX, UpY, UpZ);
}



void Camera::ChangeViewsize(int Width_, int Height_){
	Width = Width_;
	Height = Height_;
	UpdateProjection();
}

void Camera::setProjection(enum CamType Proj){
	Projection = Proj;
}

void Camera::UpdateProjection(){
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (Height == 0)
		Height = 1;

	float ratio =  Width * 1.0 / Height;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, Width, Height);

	// Set the correct perspective.
	if(Projection == PERSPECTIVE){
		gluPerspective(45.0f, ratio, 0.1f, 15000.0f);
	}else{
		glOrtho(-300.0f, 300.0f, -300.0f, 300.0f,-4000.0f, 4000.0f);
	}

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}
