/*
 * JSONReader.cpp
 *
 *  Created on: Mar 18, 2016
 *      Author: angel
 */

#include "Map.h"
#include <cmath>

//#define MODIFIER(I, J) this->Modifier[(I)*this->SizeX + (J)]
#define MODIFIER_(I, J, M) this->M[(I)*this->SizeX + (J)]
#define MODIFIER(I,J) MODIFIER_(I,J, Ez)

#define PAINT_MOD_(I, J, M) M[(I)*SizeX + (J)]
#define PAINT_MOD(I, J) PAINT_MOD_(I, J, Ez)

Object::~Object(){}

OParabola::OParabola(int FocusX_, int FocusY_, int VertexX_, int VertexY_):
	FocusX(FocusX_),
	FocusY(FocusY_),
	VertexX(VertexX_),
	VertexY(VertexY_){

}

OParabola::~OParabola(){}

void OParabola::Paint(double *Ez, int SizeX){
	double dx = FocusX - VertexX;
	double dy = FocusY - VertexY;
	double p = sqrt(dx*dx + dy*dy );
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

Map::Map() {
	// TODO Auto-generated constructor stub
	OList.begin();
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

	for( auto it : World){
		std::vector<std::string> list = it.getMemberNames();
		for(unsigned int i =0; i < list.size(); i++){
					printf("Nodo: %s\n", list[i].c_str());
				}

		if( it["Type"] == "Parabola"){
				printf("[MAP] Debug: + Parabola Focus: %ix%i\n", it["Focus"][0].asInt(), it["Focus"][1].asInt());
				printf("[MAP] Debug: + Parabola Vertex: %ix%i\n", it["Vertex"][0].asInt(), it["Vertex"][1].asInt());
				OList.push_back(new OParabola(
						it["Focus"][0].asInt(),
						it["Focus"][1].asInt(),
						it["Vertex"][0].asInt(),
						it["Vertex"][1].asInt()));
				}

		else if( it["Type"] == "Line"){
			printf("[MAP] Debug: + Line: (%i, %i) -> (%i, %i)\n",
					it["Origin"][0].asInt(),
					it["Origin"][1].asInt(),
					it["To"][0].asInt(),
					it["To"][1].asInt());

			OList.push_back(new OLine(
					it["Origin"][0].asInt(),
					it["Origin"][1].asInt(),
					it["To"][0].asInt(),
					it["To"][1].asInt()));
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

void Map::CreateModifier(){
	this->Modifier = (double*) malloc(sizeof(double)*SizeX*SizeY);
	printf("[MAP] Debug: Modifier created: %ix%i\n", SizeX, SizeY);
}

void Map::AddParabola(int FocusX, int FocusY, int VertexX, int VertexY){
	printf("[MAP] Debug: + Parabola: %ix%i\n", FocusX, FocusY);
	printf("[MAP] Debug: + Parabola: %ix%i\n", VertexX, VertexY);
	/*
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
*/
}
