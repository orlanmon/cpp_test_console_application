#include "Map.h"
#include "GPSPlacemarker.h"
#include <memory>


Map::Map() {

}


Map::~Map() {

	

}


void Map::AddPlacemarker(double latitude, double longitude, std::string name, std::string description) {


	std::unique_ptr<GPSPlacemarker> up_GPSPlacemarker = std::make_unique<GPSPlacemarker>(latitude, longitude, name, description);

	this->vGPSPlacemarkers.push_back(up_GPSPlacemarker);


}