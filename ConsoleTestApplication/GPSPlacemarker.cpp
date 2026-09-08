#include "GPSPlacemarker.h"


GPSPlacemarker::GPSPlacemarker(double latitude, double longitude, std::string name, std::string description) {

	this->latitude = latitude;
	this->longitude = longitude;

	this->name = name;
	this->description = description;

}


GPSPlacemarker::~GPSPlacemarker() {



}