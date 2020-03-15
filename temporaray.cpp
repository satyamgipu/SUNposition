
#include<math.h>
#include<stdio.h>
#include<conio.h>

#define pi    3.14159265358979323846
#define twopi (2*pi)
#define rad   (pi/180)
#define dEarthMeanRadius     6371.01	// In km
#define dAstronomicalUnit    149597890

double Cjulian;
double dDecimalHours;
double dEclipticLongitude;
double dEclipticObliquity;
double dRightAscension;
double dDeclination;
double dMeanLongitude;
double dMeanAnomaly;
double dOmega;
double dY;
double dX;
double Zenith;
double ZenithAngle;
double Azimuth;
double Elevation;

int main(){
	        int year  = 2020;
			int month = 3;
            int day   = 15;
            double hours = 00.00;            /*  UTC TIME!  */
			double minutes = 30.00;
			double seconds = 0.00;
			double longitude =77.5011; // your longitude [e.g 151.857964];
			double latitude  =27.2038;
			double dJulianDate;
			long int liAux1;
			long int liAux2;
						  // Calculate time of the day in UT decimal hours
			for (hours=00.00;hours<=18;hours++){
			
			
			dDecimalHours = hours + (minutes + seconds / 60.0 ) / 60.0;
						  // Calculate current Julian Day
			liAux1 =(month-14)/12;
			liAux2=(1461*(year + 4800 + liAux1))/4 + (367*(month - 2-12*liAux1))/12- (3*((year + 4900 + liAux1)/100))/4+day-32075;
			dJulianDate=(double)(liAux2)-0.5+dDecimalHours/24.0;
						  // Calculate difference between current Julian Day and JD 2451545.0
			Cjulian = dJulianDate-2451545.0;
			dOmega=2.1429-0.0010394594*Cjulian;
			dMeanLongitude = 4.8950630+ 0.017202791698*Cjulian; // Radians
			dMeanAnomaly = 6.2400600+ 0.0172019699*Cjulian;
			dEclipticLongitude = dMeanLongitude + 0.03341607*sin( dMeanAnomaly ) + 0.00034894*sin( 2*dMeanAnomaly )-0.0001134-0.0000203*sin(dOmega);
			dEclipticObliquity = 0.4090928 - 6.2140e-9*Cjulian +0.0000396*cos(dOmega);
			double dSin_EclipticLongitude;
			dSin_EclipticLongitude= sin( dEclipticLongitude );
			dY = cos( dEclipticObliquity ) * dSin_EclipticLongitude;
			dX = cos( dEclipticLongitude );
			dRightAscension = atan2( dY,dX );
			if( dRightAscension < 0.0 ){
						    dRightAscension = dRightAscension + twopi;
						  }
			dDeclination = asin( sin( dEclipticObliquity )*dSin_EclipticLongitude );
			double dGreenwichMeanSiderealTime;
			 double dLocalMeanSiderealTime, dLatitudeInRadians, dHourAngle, dCos_Latitude, dSin_Latitude, dCos_HourAngle, dParallax;
			dGreenwichMeanSiderealTime = 6.6974243242 + 0.0657098283*Cjulian + dDecimalHours;
			dLocalMeanSiderealTime = (dGreenwichMeanSiderealTime*15 + longitude)*rad;
			dHourAngle = dLocalMeanSiderealTime - dRightAscension;
			dLatitudeInRadians = latitude*rad;
			dCos_Latitude = cos( dLatitudeInRadians );
			dSin_Latitude = sin( dLatitudeInRadians );
			dCos_HourAngle= cos( dHourAngle );
			Zenith = (acos( dCos_Latitude*dCos_HourAngle*cos(dDeclination) + sin( dDeclination )*dSin_Latitude));
			dY = -sin( dHourAngle );
			dX = tan( dDeclination )*dCos_Latitude - dSin_Latitude*dCos_HourAngle;
			Azimuth = atan2( dY, dX );
			if ( Azimuth < 0.0 ){
						    Azimuth = Azimuth + twopi;
						  }
			Azimuth = Azimuth/rad;
						  // Parallax Correction
			dParallax=(dEarthMeanRadius/dAstronomicalUnit)*sin(Zenith);
			ZenithAngle =(Zenith + dParallax)/rad;
			Elevation = 90.00 - ZenithAngle;
			printf("At hours %lf Elevation %lf Azimuth %lf \n ",dDecimalHours+5.5,Elevation,Azimuth);
			
		}
	}
