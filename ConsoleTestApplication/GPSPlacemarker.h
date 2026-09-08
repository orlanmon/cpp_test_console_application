#ifndef GPSPLACEMARKER_H
#define GPSPLACEMARKER_H

#include <string>



class GPSPlacemarker
{

private:

	double latitude;
	double longitude;

	std::string name;
	std::string description;

public:


	GPSPlacemarker(double latitude, double longitude, std::string name, std::string description);
	~GPSPlacemarker();


};





#endif

