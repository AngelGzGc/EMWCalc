
#include "Object.h"
#include <cstdio>
#include <cmath>
#include <GL/glew.h>

//#define MODIFIER(I, J) this->Modifier[(I)*this->SizeX + (J)]
#define MODIFIER_(I, J, M) this->M[(I)*this->SizeX + (J)]
#define MODIFIER(I,J) MODIFIER_(I,J, Ez)

#define PAINT_MOD_(I, J, M) M[(I)*SizeX + (J)]
#define PAINT_MOD(I, J) PAINT_MOD_(I, J, Ez)


Object::~Object(){}

OParabola::OParabola(int FocusX_, int FocusY_, int VertexX_, int VertexY_):
	FocusX(FocusX_),
	FocusY(FocusY_){

	double dx = FocusX - VertexX_;
	double dy = FocusY - VertexY_;
	p = sqrt(dx*dx + dy*dy );
}

OParabola::OParabola(int FocusX_, int FocusY_, double p_):
	FocusX(FocusX_),
	FocusY(FocusY_),
	p(p_){
}

OParabola::~OParabola(){}

void OParabola::Paint(){

	double valor_metal = 0;

	 glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);



	 glBegin(GL_LINE_STRIP);
		glVertex2f(FocusX-p, FocusY );
		for(int i = 0; i < 100; i++){
			glVertex2f(FocusX-p+i+1,round(FocusY+2*sqrt(p*i)));
		}
		glEnd();

		glBegin(GL_LINE_STRIP);
	glVertex2f(FocusX-p, FocusY );
	for(int i = 0; i < 100; i++){
		glVertex2f(FocusX-p+i+1,round(FocusY-2*sqrt(p*i)));
	}
	glEnd();

}

OLine::OLine(int x1_, int y1_, int x2_, int y2_):
	x1(x1_),
	y1(y1_),
	x2(x2_),
	y2(y2_){

	if( x1 != x2){
		p = (y2-y1)/(x2-x1);
		cte = y1-p*x1;
	}

}

OLine::~OLine(){}

void OLine::Paint(){
	glBegin(GL_LINE_STRIP);
	glVertex3f((float)x1, 	(float)y1, 	0.0);
	glVertex3f((float)x2, 	(float)y2, 	0.0);
	glEnd();
}

OCircle::OCircle(int x_, int y_, double radius_):
	x(x_),
	y(y_),
	radius(radius_)
{}

OCircle::~OCircle(){}

void OCircle::Paint(void){
	   glBegin(GL_LINE_LOOP);
	   glPushMatrix();
	   glTranslatef(x,y,0);
	   for (int i=0; i < 360; i++)
	   {
	      float degInRad = i*DEG2RAD;
	      glVertex2f(x+cos(degInRad)*radius,y+sin(degInRad)*radius);
	   }
	   glPopMatrix();
	   glEnd();
}

