/*
 * VisualConfig.h
 *
 *  Created on: 3 de nov. de 2015
 *      Author: angel
 */

#ifndef VISUALCONFIG_H_
#define VISUALCONFIG_H_

#include <GL/glew.h>
#include <GL/glut.h>

class VisualConfig {
private:
	struct _Light{
		GLfloat Ambient[4];
		GLfloat Diffuse[4];
		GLfloat Specular[4];
		GLfloat Position[4];
	} Light;

public:
	VisualConfig();

	void Init(int argc, char **argv);
	void LightInit();
	void TurnOnLight();
};

#endif /* VISUALCONFIG_H_ */
