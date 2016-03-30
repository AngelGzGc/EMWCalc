/*
 * Source.h
 *
 *  Created on: Mar 28, 2016
 *      Author: angel
 */

#ifndef SOURCE_H_
#define SOURCE_H_

enum SourceType{
	GAUS = 0,
	SIN
};

class Source {

public:

	double offset;
	double amp;

	Source();
	Source(double offset_);
	Source(double offset_, double amp_);
	virtual ~Source();

	virtual void Update(double *Ez, int SizeX, double t) =0;
};


// f(t) = A*exp( t*t/50)
class SGaus: public Source {
private:
	int PosX, PosY;
public:
	SGaus(int PosX_, int PosY_);
	SGaus(int PosX_, int PosY_, double offset_);
	SGaus(int PosX_, int PosY_, double offset_, double amp_);
	virtual ~SGaus();

	void Update(double *Ez, int SizeX, double t);
};

// f(t) = A*sin(t)
class SSin: public Source {
private:
	int PosX, PosY;
	double freq, offset;

public:
	SSin(int PosX_, int PosY_);
	SSin(int PosX_, int PosY_, double offset_);
	SSin(int PosX_, int PosY_, double offset_, double amp_);
	virtual ~SSin();

	void Update(double *Ez, int SizeX, double t);
};


#endif /* SOURCE_H_ */
