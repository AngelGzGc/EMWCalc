//============================================================================
// Name        : DataVisGL.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdlib.h>
#include <GL/glew.h>
#include <cstdio>
#include <cmath>
#include <GL/glut.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <cstring>
#include "HMap.h"
#include "VisualConfig.h"
#include "CameraMgr.h"

using namespace std;

#define SIZE_X 400
#define SIZE_Y 400
#define SHMSZ SIZE_X*SIZE_Y

int shmid;
key_t key;
double *shm;

int gW, gH;

enum perspective {PERS = 0, ORTHO};

enum perspective pers = PERS;




HMap *Mapa = new HMap(SIZE_X,SIZE_Y);
CameraMgr *CamMgr= new CameraMgr();

float ax = 0;
float Ox = 0, Oy = 0;

double * MapDat;


void changeSize(int w, int h) {
	CamMgr->ChangeViewsize(w,h);
}


void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	CamMgr->getCamera()->getLookAt();

	Mapa->Paint();

	glutSwapBuffers();

}

void processNormalKeys(unsigned char key, int x, int y) {

	/* Exit on ESC key */
	if (key == 27)
		exit(0);

	switch(key){
	case 97: //key 'a'
		if( pers == PERS){
			CamMgr->setProjectionOrtho();
		}else{
			CamMgr->setProjectionPers();
		}
	}
}


void mouseButton(int button, int state, int x, int y) {
	if(CamMgr->getCamera()->getProjection() == ORTHOGRAPHIC){
		return;
	}
	// only start motion if the left button is pressed
	if (button == GLUT_LEFT_BUTTON) {

		// when the button is released
		if (state == GLUT_UP) {
			GLfloat whiteSpecularMaterial[] = {1.0, 1.0, 1.0};
			GLfloat mShininess[] = {128};
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, whiteSpecularMaterial);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mShininess);
		}
		else  {// state = GLUT_DOWN
			Ox = x;
			Oy = y;
			printf("y0: %.3f",Oy);
		}
	}else if(button == 3 ){ // Wheel up
		CamMgr->getCamera()->setDistance(CamMgr->getCamera()->getDistance() - 10);
	}else if(button == 4){
		CamMgr->getCamera()->setDistance(CamMgr->getCamera()->getDistance() + 10);
	}
}

void mouseMove(int x, int y) {

	if( CamMgr->getCamera()->getProjection() == PERSPECTIVE){
		CamMgr->getCamera()->setAngles(
					CamMgr->getCamera()->getPhi()   + (x-Ox)*0.01,
					CamMgr->getCamera()->getTheta() + (y-Oy)*0.01
					);
	}

	Oy = y;
	Ox = x;
}

VisualConfig *VConf;

int main(int argc, char **argv) {

	VConf = new VisualConfig();
		VConf->Init(argc, argv);
		VConf->LightInit();
	key = 5678;

	/*
	 * Create the segment.
	 */
	if ((shmid = shmget(key, SHMSZ*sizeof(double), IPC_CREAT | 0666)) < 0) {
		perror("shmget");
		printf("%i\n", shmid);
		//printf("%i\n", SHMSZ*sizeof(int));
		exit(1);
	}

	/*
	 * Now we attach the segment to our data space.
	 */
	if ((shm = (double*)shmat(shmid, NULL, 0)) == (double *) -1) {
		perror("shmat");
		exit(1);
	}
	for (int i = 0; i < SHMSZ; i++){
		shm[i] = 0;
	}


	Mapa->AssignMap(shm);
	CamMgr->SetDefaultConfig();


	glShadeModel (GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);
	glutKeyboardFunc(processNormalKeys);
	// enter GLUT event processing cycle

	glutMainLoop();

	delete(Mapa);
	delete(CamMgr);
	return 1;
}
