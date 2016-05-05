/*
 * HUD.cpp
 *
 *  Created on: Mar 29, 2016
 *      Author: angel
 */

#include "HUD.h"
#include <GL/glew.h>

HUD::HUD() {
	// TODO Auto-generated constructor stub
	Mapa = new Map();
	Mapa->ReadJSON("world.json");
}

HUD::~HUD() {
	// TODO Auto-generated destructor stub
	delete(Mapa);
}

void HUD::Paint(){
	float SizeX = 100.0;
	float SizeY = 100.0;
	float Height = 30.0;


	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glShadeModel(GL_SMOOTH);
	float colorBlue[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float colorBlue2[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorBlue);
	glEnable(GL_COLOR_MATERIAL);

	// Draw the color bar
	glTranslatef(-150.0,  0.0, 0.0);
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.0, 	0.0, 	0.0);
	glVertex3f(50.0, 	0.0, 		0);
	glColor3f(0.5,0.5,1.0);
	glVertex3f(0.0,		200.0,	0.0);
	glVertex3f(50.0, 	200.0, 	0.0);
	glColor3f(0.0,0.0,0.0);
	glVertex3f(0.0,		400.0,	0.0);
	glVertex3f(50.0,	400.0,	0.0);
	glEnd();

	glColor3f(1.0f,1.0f,1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


	//Border line
	glLoadIdentity();
	glLineWidth(2.5);
	glColor3f(1.0, 1.0, 1.0);
	glEnable(GL_LINE_SMOOTH);
	glDisable(GL_DEPTH_TEST);
	glHint(GL_LINE_SMOOTH_HINT,  GL_NICEST);


	Mapa->ModifyMap();

	glEnable(GL_DEPTH_TEST);
}
