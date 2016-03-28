/*
 * JSONReader.h
 *
 *  Created on: Mar 18, 2016
 *      Author: angel
 */

#ifndef JSONREADER_H_
#define JSONREADER_H_

#include <json/json.h>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <list>

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
	int VertexX, VertexY;

public:

	OParabola(int FocusX_, int FocusY_, int VertexX_, int VertexY_);
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


class Map {

private:
	Json::Value root;
	Json::Reader reader;

	int SizeX, SizeY;
	double *Modifier;

	std::list<Object*> OList;

	void CreateModifier();

	// Predefined items
	void AddParabola(int FocusX, int FocusY, int VertexX, int VertexY);
public:
	Map();
	virtual ~Map();

	void ReadJSON(std::string file);
	void ModifyMap(double *Ez);
};

#endif /* JSONREADER_H_ */
