/*
 * HUD.h
 *
 *  Created on: Mar 29, 2016
 *      Author: angel
 */

#ifndef HUD_H_
#define HUD_H_

#include "Map.h"


class HUD {
private:
	Map *Mapa;

	// Store the objects of the GUI.
	std::list<Object*> OList;
public:
	HUD();
	virtual ~HUD();

	void Paint();
};

#endif /* HUD_H_ */
