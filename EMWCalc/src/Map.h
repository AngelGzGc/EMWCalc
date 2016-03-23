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


class Map {

private:
	Json::Value root;
	Json::Reader reader;

	int SizeX, SizeY;
	double *Modifier;


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
