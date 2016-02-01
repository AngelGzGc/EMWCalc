/*
 * HMap.h
 *
 *  Created on: 2 de nov. de 2015
 *      Author: angel
 */

#ifndef HMAP_H_
#define HMAP_H_

#include <vector>
#include <GL/glew.h>

using namespace std;

struct Vertex{
	double 	position[3];
	double 	normal[3];
	uint8_t	color[4];
};

class HMap {
private:

	GLuint vbo;

public:
	int SizeX, SizeY; // Size of the map
	float Height;
	double *Data; // 2D array to store the heigh values
	double *Varray;
	int *Color;
	float cs; // Escalado de color
	float ss; //Escalado de datos
	double n[3] = {0};

	//Constructors and destructor
	HMap(int sX, int sY);
	virtual ~HMap();

	//Get Value of one item of the grid
	double GetI(int X, int Y);

	//Assign the memory with the heigh data
	void AssignMap(double *Mem);

	//OpenGl instructions to paint the heighmap
	void Paint();


private:
	void FullVertex(double x, double y, double z);

	//Math aux
	void Normal(double a[3], double b[3], double c[3], double out[3]); 		//Compute the Normal Vector and store in normal
	void Normalize(float inout[3]);

};

#endif /* HMAP_H_ */
