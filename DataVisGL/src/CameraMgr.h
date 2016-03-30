/*
 * CameraMgr.h
 *
 *  Created on: Jan 29, 2016
 *      Author: angel
 */

#ifndef CAMERAMGR_H_
#define CAMERAMGR_H_

#include "Camera.h"


class CameraMgr {
private:
	Camera *Cam;
	enum CamType Projection;

public:
	CameraMgr();
	virtual ~CameraMgr();

	Camera* getCamera();

	void SetDefaultConfig();
	void ChangeViewsize(int Width_, int Height_);

	void setProjection(enum CamType proj);
	void resetProjectionOrtho();
	void resetProjectionPers();
	void setProjectionOrtho();
	void setProjectionPers();
};

#endif /* CAMERAMGR_H_ */
