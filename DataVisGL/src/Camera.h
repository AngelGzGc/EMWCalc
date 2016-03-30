/*
 * Camera.h
 *
 *  Created on: Jan 29, 2016
 *      Author: angel
 */

#include <GL/glut.h>

#ifndef CAMERA_H_
#define CAMERA_H_



enum CamType {PERSPECTIVE, ORTHOGRAPHIC, ORTHO_PROTECTED};
enum CamAngle { PHY, THETA };

class Camera {
private:

	/* Camera Angles and Distance*/
	GLfloat Phi, Theta, Distance;


	/* Camera position */
	GLfloat PosX, PosY, PosZ;
	GLfloat RefX, RefY, RefZ;
	GLfloat UpX, UpY, UpZ;

	/* View sizes */
	int Width, Height;

	enum CamType Projection;
public:

	Camera();
	virtual ~Camera();

	/* This function has to be called in every frame so it position the camera */
	void getLookAt();

	/* Set camera parameters*/
	void setDistance(GLfloat Distance_);
	void setRefs( GLfloat RefX_, GLfloat RefY_, GLfloat RefZ_);
	void setUps(GLfloat UpX_, GLfloat UpY_, GLfloat UpZ_);
	void setAngles(GLfloat Phi_, GLfloat Theta_);
	void setPos(GLfloat PosX_, GLfloat PosY_, GLfloat PosZ_);
	void setViewsize(int Width_, int Height_);



	/* Change camera parameters */
	void ChangeDistance(GLfloat Distance_);
	void ChangeAngle(enum CamAngle Angle, GLfloat variation);


	/* Get camera parameters */
	GLfloat getDistance(){ return Distance; }
	GLfloat getPosX()	{ return PosX; }
	GLfloat getPosY()	{ return PosY; }
	GLfloat getPosZ()	{ return PosZ; }
	GLfloat getPhi()	{ return Phi;  }
	GLfloat getTheta()	{ return Theta;}
	enum CamType getProjection(){ return Projection; }


	/* Called when the View size changes */
	void ChangeViewsize(int Width_, int Height_);

	/* Update the projection of the scene */
	void UpdateProjection();
	void setProjection(enum CamType Proj);

	/* Update Position based on the angles */
	void UpdatePos();

};

#endif /* CAMERA_H_ */
