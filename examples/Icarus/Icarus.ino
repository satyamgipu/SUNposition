#include <Helios.h>

/////////// TEMPORARY TEST VARIABLES //////////////////////
int TheYear  = 2013;
int TheMonth = 1;
int TheDay   = 16;
double TheHour = 04.00;            /*  UTC TIME!  */
double TheMinute = 0.00;
double TheSeconds = 0.00;
double YourLongitude = // your longitude [e.g 151.857964];
double YourLatitude  = // your latitude  [e.g -33.579265];
//////LIVE VARIABLES SHOULD BE USED FROM GPS///////////////

Helios helios;

void setup(){}

void loop(){
  helios.getPos(TheYear, TheMonth, TheDay, TheHour, TheMinute, TheSeconds, YourLongitude, YourLatitude);
  Serial.print("Sun Zenith Angle:  ");
  Serial.println(helios.ZenithAngle);
  Serial.print("Sun Azimuth Angle:  ");
  Serial.println(helios.Azimuth);
  Serial.print("Sun Elevation Angle:  ");
  Serial.println(helios.Elevation);
  delay(500);
}

