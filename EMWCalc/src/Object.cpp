
#include "Object.h"
#include <cstdio>
#include <cmath>

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

void OParabola::Paint(double *Ez, int SizeX){

	double valor_metal = 0;
	for(int i = 0; i < 100; i++){
		PAINT_MOD(int(FocusX-p+i+1),int(round(FocusY-2*sqrt(p*i))))=valor_metal;
		PAINT_MOD(int(FocusX-p+i+1),int(round(FocusY+2*sqrt(p*i))))=valor_metal;
		for(int j = 0; j <= ceil(2*(sqrt(p*(i+1))-sqrt(p*(i)))); j++){
				PAINT_MOD( int(FocusX-p+1+int(round((j*j)/(4*p)))),  FocusY+j) = valor_metal;
				PAINT_MOD(int( FocusX-p+1+int(round((j*j)/(4*p)))), -(FocusY+j)) = valor_metal;
		}
		PAINT_MOD(int(FocusX-p+i-1),int(round(FocusY-2*sqrt(p*i))))=valor_metal;
		PAINT_MOD(int(FocusX-p+i-1),int(round(FocusY+2*sqrt(p*i))))=valor_metal;
	}
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

void OLine::Paint(double *Ez, int SizeX){

	double valor_metal = 0;

	// If vertical line
	if(x1 == x2){
		for( int i = y1; i < y2; i++){
			PAINT_MOD(int(x1),i) = valor_metal;
		}
	}else{
		for( int i = x1; i < x2; i++){
			PAINT_MOD(int(i), int(round(p*i+cte))) = valor_metal;
		}
	}
}

OCircle::OCircle(int x_, int y_, double radius_):
	x(x_),
	y(y_),
	radius(radius_)
{}

OCircle::~OCircle(){}

void OCircle::Paint(double *Ez, int SizeX){
	double valor_metal = 0;
	   for (int i=0; i < 360; i++)
	   {
		  float degInRad = i*DEG2RAD;
		  PAINT_MOD(x+int(round(cos(degInRad)*radius)), y+int(round(sin(degInRad)*radius))) = valor_metal;
	      //glVertex2f(cos(degInRad)*radius,sin(degInRad)*radius);
	   }

}
