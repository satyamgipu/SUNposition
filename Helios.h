#ifndef __HELIOS_H
#define __HELIOS_H



#define pi    3.14159265358979323846
#define twopi (2*pi)
#define rad   (pi/180)
#define dEarthMeanRadius     6371.01	// In km
#define dAstronomicalUnit    149597890	// In km

class Helios{
	public:
	void getPos(int year,
				int month,
				int day,
				double hours,
				double minutes,
				double seconds,
				double longitude,
				double latitude);
	double Zenith;
	double ZenithAngle;
	double Azimuth;
	double Elevation;
};
#endif

