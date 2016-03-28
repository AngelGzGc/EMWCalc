#ifndef OBJECT_H_
#define OBJECT_H_


enum WorldType{
	Line = 0,
	Parabola = 1
};

class Object{
public:
	virtual ~Object();
	virtual void  Paint(double *Ez, int SizeX)=0;
};


class OParabola: public Object{
private:
	int FocusX, FocusY;
	double p;

public:

	OParabola(int FocusX_, int FocusY_, int VertexX_, int VertexY_);
	OParabola(int FocusX_, int FocusY_, double p_);
	virtual ~OParabola();
	void Paint(double *Ez, int SizeX);

};


class OLine: public Object{
private:
	int x1, y1;
	int x2, y2;

	// For the line eq: y = p*x + cte
	// where cte = y0 - p*x0
	double p, cte;
public:

	OLine(int x1_, int y1_, int x2_, int y2_);
	virtual ~OLine();
	void Paint(double *Ez, int SizeX);

};

#endif
