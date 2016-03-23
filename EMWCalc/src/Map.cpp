/*
 * JSONReader.cpp
 *
 *  Created on: Mar 18, 2016
 *      Author: angel
 */

#include "Map.h"
#include <cmath>

#define MODIFIER(I, J) this->Modifier[(I)*this->SizeX + (J)]

Map::Map() {
	// TODO Auto-generated constructor stub

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

	Json::Value World = root["World"];
	Json::Value tempval;
	for(signed int i = 0u; i < World.size(); i++){
		Json::Value::ArrayIndex j = 0u;
		std::vector<std::string> list = World[((int)1)].getMemberNames();
		/*for(int i =0; i < list.size(); i++){
			printf("Nodo: %s\n", list[i].c_str());
		}*/
		//tempval = root["World"][i];


		/*if( tempval["Type"] == "Parabola"){
			this->AddParabola(
						tempval["Focus"][0].asInt(),
						tempval["Focus"][1].asInt(),
						tempval["Vertex"][0].asInt(),
						tempval["Vertex"][1].asInt());
		}*/
	}

	/*std::vector<std::string> list = root.getMemberNames();
	for(int i =0; i < list.size(); i++){
		printf("Nodo: %s\n", list[i].c_str());
	}*/


}

Map::~Map() {
	// TODO Auto-generated destructor stub
}

void Map::ModifyMap(double *Ez){

}

void Map::CreateModifier(){
	this->Modifier = (double*) malloc(sizeof(double)*SizeX*SizeY);
	printf("[MAP] Debug: Modifier created: %ix%i\n", SizeX, SizeY);
}

void Map::AddParabola(int FocusX, int FocusY, int VertexX, int VertexY){
	double dx = FocusX - VertexX;
	double dy = FocusY - VertexY;
	double p = sqrt(dx*dx + dy*dy );
	double valor_metal = 0;
	for(int i = 0; i < 100; i++){
		MODIFIER(int(FocusX-p+i+1),int(round(FocusY-2*sqrt(p*i))))=valor_metal;
		MODIFIER(int(FocusX-p+i+1),int(round(FocusY+2*sqrt(p*i))))=valor_metal;
		for(int j = 0; j <= ceil(2*(sqrt(p*(i+1))-sqrt(p*(i)))); j++){
				MODIFIER( int(FocusX-p+1+int(round((j*j)/(4*p)))),  FocusY+j) = valor_metal;
				MODIFIER(int( FocusX-p+1+int(round((j*j)/(4*p)))), -(FocusY+j)) = valor_metal;
		}
		MODIFIER(int(FocusX-p+i-1),int(round(FocusY-2*sqrt(p*i))))=valor_metal;
		MODIFIER(int(FocusX-p+i-1),int(round(FocusY+2*sqrt(p*i))))=valor_metal;
	}
}
