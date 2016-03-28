/*
 * JSONReader.cpp
 *
 *  Created on: Mar 18, 2016
 *      Author: angel
 */

#include "Map.h"
#include "Source.h"
#include <cmath>

Map::Map() {
	// TODO Auto-generated constructor stub
	OList.begin();
	SList.begin();
}

void Map::ReadJSON(std::string file){

	// Read file into root
	std::ifstream config_doc(file.c_str(), std::ifstream::binary);
	config_doc >> root;

	// Read the config part
	// TODO: Check that the config parameter exists
	this->SizeX = root["config"]["Size"][0].asInt();
	this->SizeY = root["config"]["Size"][1].asInt();
	this->CreateModifier();


	// The world object parser starts
	Json::Value World = root["World"];

	for( auto it : World){

		if( it["Type"] == "Parabola"){
				if( it.isMember("Vertex")){
				printf("[MAP] Debug: + Parabola Focus: %ix%i\n", it["Focus"][0].asInt(), it["Focus"][1].asInt());
				printf("[MAP] Debug: + Parabola Vertex: %ix%i\n", it["Vertex"][0].asInt(), it["Vertex"][1].asInt());
				OList.push_back(new OParabola(
						it["Focus"][0].asInt(),
						it["Focus"][1].asInt(),
						it["Vertex"][0].asInt(),
						it["Vertex"][1].asInt()));
				}else if( it.isMember("Directrix")){
					OList.push_back(new OParabola(
							it["Focus"][0].asInt(),
							it["Focus"][1].asInt(),
							it["Directrix"].asDouble()));
				}

		}else if( it["Type"] == "Line"){
			printf("[MAP] Debug: + Line: (%i, %i) -> (%i, %i)\n",
					it["From"][0].asInt(),
					it["From"][1].asInt(),
					it["To"][0].asInt(),
					it["To"][1].asInt());

			OList.push_back(new OLine(
					it["From"][0].asInt(),
					it["From"][1].asInt(),
					it["To"][0].asInt(),
					it["To"][1].asInt()));
		}

	}

	//Parse the sources
	Json::Value Sources = root["Sources"];

	for( auto it : Sources){

		if( it["Type"] == "Gaus"){
			if( it.isMember("Offset") ){
				SList.push_back(new SGaus(
					it["Position"][0].asInt(),
					it["Position"][1].asInt(),
					it["Offset"].asDouble()));
			}else{
				SList.push_back(new SGaus(
					it["Position"][0].asInt(),
					it["Position"][1].asInt()));
			}
		}else if( it["Type"] == "Sin"){
			SList.push_back(new SSin(
					it["Position"][0].asInt(),
					it["Position"][1].asInt(),
					it["Freq"].asDouble()));
		}

	}
}

Map::~Map() {
	// TODO Auto-generated destructor stub
}

void Map::ModifyMap(double *Ez){
	for(auto it : OList){
		it->Paint(Ez, this->SizeX);
	}
}

void Map::UpdateSources(double *Ez, double time)
{
	for( auto it : SList){
		it->Update(Ez, this->SizeX, time);
	}
}

void Map::CreateModifier(){
	this->Modifier = (double*) malloc(sizeof(double)*SizeX*SizeY);
	printf("[MAP] Debug: Modifier created: %ix%i\n", SizeX, SizeY);
}
