/*
 * HMap.cpp
 *
 *  Created on: 2 de nov. de 2015
 *      Author: angel
 */

#include "HMap.h"
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <GL/glew.h>


HMap::HMap(int sX, int sY){
	// TODO Auto-generated constructor stub
	this->SizeX = sX;
	this->SizeY = sY;
	this->cs = 0.1;
	this->ss = 500;
	this->Height = 200;
	this->Color = (int*)malloc(sizeof(int)*sX*sY);
	this->Varray = (double*)malloc(sizeof(double)*3*sX*sY);
	for(int i = 0; i < sX*sY; i++){
		this->Color[i] = 1;
	}
}

void HMap::AssignMap(double *Mem){

	this->Data = Mem;
	/*glGenBuffersARB(1, &vbo);
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, vbo);

	// upload data to VBO
	glBufferDataARB(GL_ARRAY_BUFFER_ARB, SizeX*sizeof(double), Data, GL_STATIC_DRAW_ARB);
	//glBufferData(GL_ARRAY_BUFFER, SizeX*SizeY*sizeof(double), Data, GL_DYNAMIC_DRAW);*/

	//glVertexPointer(3,GL_DOUBLE,);
}

double HMap::GetI(int X, int Y){
	if(X*Y < SizeX*SizeY and X >= 0 and Y >= 0){
		return Data[X*SizeX + Y];
	}
	return 0.0f;
}

void HMap::Paint(){

			double v1[3], v2[3], v3[3];
			glPushMatrix();
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glShadeModel(GL_SMOOTH);

		    for (int x = 1; x < SizeX-1; x++) {
				float colorBlue[] = { 1.0f, 1.0f, 1.0f, 1.0f };
				float colorBlue2[] = { 1.0f, 0.0f, 1.0f, 1.0f };
				glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colorBlue);
				glMaterialfv(GL_FRONT, GL_SPECULAR, colorBlue2);
				glEnable(GL_COLOR_MATERIAL);
				glBegin(GL_QUAD_STRIP);


		      	for (int z = 1; z < SizeY; z++) {
		    	  	v2[0] = -GetI(x,z)+GetI(x+1, z);
		    	    v1[0] = v2[0];
		    	    v1[1] = -1.0f;
		    	    v1[2] = v2[0];
		    	    v2[1] = sqrt(v1[0]*v1[0]+1+v1[0]*v1[0]);
		    	    v1[0] /= v2[1];
		    	    v1[1] /= v2[1];
		    	    v1[2] /= v2[1];


		        	glColor3f(abs(GetI(x,z)/cs),abs(GetI(x,z)/cs),abs(GetI(x,z)/cs*2));
		        	glVertex3f(   x, abs(ss*GetI(x,z))    , z );
		        	glVertex3f( x+1, abs(ss*GetI(x+1,z))  , z );
		        	glNormal3f(v1[0],v1[2],v1[3]);

		      }
		      glEnd();
		    }
		    glPopMatrix();

		    glColor3f(1.0f,1.0f,1.0f);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


		//Border line
		glLineWidth(2.5);
		glColor3f(1.0, 1.0, 1.0);
		glEnable(GL_LINE_SMOOTH);
		glHint(GL_LINE_SMOOTH_HINT,  GL_NICEST);
		glBegin(GL_LINE_STRIP);
		glVertex3f(0.0, 	0.0, 	0.0);
		glVertex3f(SizeX, 	0, 		0);
		glVertex3f(SizeX, 	0, 		SizeY);
		glVertex3f(0, 		0,		SizeY);
		glVertex3f(0.0, 	0.0, 	0.0);
		glVertex3f(0.0, 	Height, 	0.0);
		glVertex3f(SizeX, 	Height, 	0.0);
		glVertex3f(SizeX, 	Height, 	SizeY);
		glVertex3f(0, 		Height, 	SizeY);
		glVertex3f(0.0, 	Height, 	0.0);
		glEnd();



}

void HMap::FullVertex(double x, double y, double z){

}
void HMap::Normal(double a[3], double b[3] ,double c[3], double *out){

	double v1[3], v2[3];

	v1[0] = b[0] - a[0];
	v1[1] = b[1] - a[1];
	v1[2] = b[2] - a[2];

	v2[0] = c[0] - a[0];
	v2[1] = c[1] - a[1];
	v2[2] = c[2] - a[2];

	out[0] = (v1[1] * v2[2]) - (v1[2] * v2[1]);
	out[1] = (v1[2] * v2[0]) - (v1[0] * v2[2]);
	out[2] = (v1[0] * v2[1]) - (v1[1] * v2[0]);

	double l = sqrt( out[0] * out[0] + out[1]*out[1] + out[2]*out[2]);

	out[0] /= l;
	out[1] /= l;
	out[2] /= l;
	//printf("%.2f\n", out[2]);
}


HMap::~HMap() {
	// TODO Auto-generated destructor stub
}

