/*
 * Source.cpp
 *
 *  Created on: Mar 28, 2016
 *      Author: angel
 */

#include "Source.h"
#include <cmath>

#define Update_MOD_(I, J, M) M[(I)*SizeX + (J)]
#define Update_MOD(I,J) Update_MOD_(I,J,Ez)

/* Base class */
Source::Source():
	offset(0),
	amp(1) {
	// TODO Auto-generated constructor stub

}

Source::Source(double offset_):
	offset(offset_),
	amp(1) {
	// TODO Auto-generated constructor stub

}

Source::Source(double offset_, double amp_):
	offset(offset_),
	amp(amp_) {
	// TODO Auto-generated constructor stub

}

Source::~Source() {
	// TODO Auto-generated destructor stub
}


SGaus::SGaus(int PosX_, int PosY_):
	PosX(PosX_),
	PosY(PosY_){

}

SGaus::SGaus(int PosX_, int PosY_, double offset_):
	PosX(PosX_),
	PosY(PosY_),
	Source(offset_){

}

SGaus::SGaus(int PosX_, int PosY_, double offset_, double amp_):
	PosX(PosX_),
	PosY(PosY_),
	Source(offset_,amp_){

}

SGaus::~SGaus(){

}

void SGaus::Update(double* Ez, int SizeX, double t){
	Update_MOD(this->PosX, this->PosY) += 10.0*amp*exp(-(t - offset) *(t - offset) / 50.0);

}


SSin::SSin(int PosX_, int PosY_):
	PosX(PosX_),
	PosY(PosY_),
	freq(1)
{

}

SSin::SSin(int PosX_, int PosY_, double freq_):
	PosX(PosX_),
	PosY(PosY_),
	freq(freq_){

}

SSin::SSin(int PosX_, int PosY_, double freq_, double offset_):
	PosX(PosX_),
	PosY(PosY_),
	freq(freq_),
	Source(offset_){

}

SSin::~SSin(){

}

void SSin::Update(double* Ez, int SizeX, double t){
	Update_MOD(this->PosX, this->PosY) += 5*amp*sin(freq*t);

}
