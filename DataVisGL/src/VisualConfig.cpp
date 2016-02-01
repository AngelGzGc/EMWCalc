/*
 * VisualConfig.cpp
 *
 *  Created on: 3 de nov. de 2015
 *      Author: angel
 */

#include "VisualConfig.h"
#include <GL/glew.h>
#include <GL/glut.h>

VisualConfig::VisualConfig() {
	// TODO Auto-generated constructor stub

}

void VisualConfig::Init(int argc, char **argv){

	// Send the execution params to the glutInit.
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);

	//Set windows size
	glutInitWindowPosition(00,100);
	glutInitWindowSize(620,620);

	//Create the window
	glutCreateWindow("3D Plotter");

	glewInit();
}

void VisualConfig::LightInit(){

	/* Configure OpenGL Light 0 */
	this->TurnOnLight();


	/* Set up light parameters */
	this->Light = {
				{0.2f, 0.2f, 0.2f, 1.0f}, 	// Ambient
				{1.0f, 1.0f, 1.0f, 1.0f},	// Diffuse
				{0.5f, 0.5f, 0.5f, 1.0f},	// Specular
				{100.0f, 100.0f, 100.0f, 1.0f} // Position
		};

	glLightfv(GL_LIGHT0, GL_AMBIENT, this->Light.Ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, this->Light.Diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, this->Light.Specular);
	glLightfv(GL_LIGHT0, GL_POSITION, this->Light.Position);
}


void VisualConfig::TurnOnLight(){

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

}
