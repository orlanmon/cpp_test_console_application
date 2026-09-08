#ifndef MAP_H
#define MAP_H

#include <vector>
#include "GPSPlacemarker.h"
#include <memory>


class Map {

private:

	std::vector <std::unique_ptr<GPSPlacemarker>> vGPSPlacemarkers;


public:


	Map();

	~Map();

	void AddPlacemarker(double latitude, double longitude, std::string name, std::string description);


};


#endif

