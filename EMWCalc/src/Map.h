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
#include "Source.h"
#include "Object.h"



class Map {

private:
	Json::Value root;
	Json::Reader reader;

	int SizeX, SizeY;
	double *Modifier;

	// Store the objects in the world.
	std::list<Object*> OList;

	//List of sources
	std::list<Source*> SList;

	void CreateModifier();

public:
	Map();
	virtual ~Map();

	void ReadJSON(std::string file);

	void ModifyMap(double *Ez);
	void UpdateSources(double *Ez, double time);
};

#endif /* JSONREADER_H_ */
