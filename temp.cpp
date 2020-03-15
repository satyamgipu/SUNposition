#include "Helios.h"
#include<stdio.h>
#include<conio.h>

/////////// TEMPORARY TEST VARIABLES //////////////////////
int TheYear  = 2013;
int TheMonth = 1;
int TheDay   = 16;
double TheHour = 04.00;            /*  UTC TIME!  */
double TheMinute = 0.00;
double TheSeconds = 0.00;
double YourLongitude =151 // your longitude [e.g 151.857964];
double YourLatitude  =-33 // your latitude  [e.g -33.579265];
////// LIVE VARIABLES SHOULD BE USED FROM A GPS //////////

Helios helios;

void setup(){}

int  main(){
  helios.getPos(TheYear, TheMonth, TheDay, TheHour, TheMinute, TheSeconds, YourLongitude, YourLatitude);
  printf("Sun Zenith Angle:  ");    // Degrees down from vertical
  printf("%lf",helios.ZenithAngle);
  printf("Sun Azimuth Angle:  ");   // Degrees from north
  printf("%lf",helios.Azimuth);
  printf("Sun Elevation Angle:  "); // Degrees up from horizontal
  printf("%lf",helios.Elevation);
}
