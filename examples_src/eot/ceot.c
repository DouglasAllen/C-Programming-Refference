/* gcc -o ceot ceot.c -lm -lsofa_c */

#include <stdio.h>
#include <time.h>
#include <sofa.h>

#define RADEG 0.0174532925199
#define DEGRAD 57.2957795457

/* 1.1.1970 = JD 2440587.5 */
#define EJD (double) 2440587.5

#define J2000 (double) 2451545.0

/***************************************/
/* Mean geocentric longitude of the Sun */
double mlSun(double t);

/* Eccentricity of Earth orbit */
double eoe(double t);

/* Equation of Center */
double eqc(double ma, double t);

/* Right ascension of Sun */
double raSun(double y0, double cos_al_Sun);

/* Declination Sun */
double sun_dec(double al_sun, double to_earth);
/* Sine declination Sun */
double sin_dec_sun(double dec_sun);
/* Cosine declination Sun */
double cos_dec_sun(double dec_sun);

/* Cosine of zenith */
double cosZ(double zenith);

/* Apparent longitude of Sun */
double alSun(double ma, double t, double o);
/* Cosine of apparent longitude Sun */
double cos_al_sun(double al_sun);
/* Sine apparent longitude Sun */
double sin_al_sun(double al_sun);

/* Sine local latitude */
double sin_lat(double lat);
/* Cosine local latitude */
double cos_lat(double lat);

/* True longitude of Sun */
double tlSun(double ma, double t);
/* Sine true longitude Sun */
double sin_tl_sun(double tl_sun);
/* Cosine true longitude Sun */
double cos_tl_sun(double tl_sun);

/* Cosine true obliquity Earth */
double cos_to_earth(double to_earth);
/* Sine true obliquity Earth */
double sin_to_earth(double to_earth);

/* Solar angle from zenith */
double sun(double zenith, double dec_sun, double lat);

/* Mean geocentric longitude of the Sun */
double mlSun(double t)
{
  double a;
  
  a = fmod(          280.4664567       +
    t * (             36000.76982779     +
    t * (                     0.0003032028 +
    t * (     1.0/499310.0                   +
    t * (    1.0/-152990.0                   +
    t * (1.0/-19880000.0 ) ) ) ) ), 360.0 ) * 
	  RADEG;

  return a;
}

/* Eccentricity of Earth orbit */
double eoe(double t)
{
  double e;

  e = (0.016708617 + t * (-0.000042037 + t *  -0.0000001235));

  return e; 
}

/* Equation of Center */
double eqc(double ma, double t)
{             
  double a1, a2, a3, a4, a5, s1, s2, s3, s4, s5, e;
  e   = eoe(t);  
  s1  = sin( 1.0 * ma );
  s2  = sin( 2.0 * ma );
  s3  = sin( 3.0 * ma );
  s4  = sin( 4.0 * ma );
  s5  = sin( 5.0 * ma );
  a1  = s1 * 2;
  a2  = s2 * 5.0/4.0;
  a3  = s3 * 13.0/12.0 - s1 * 1.0/4.0;
  a4  = s4 * 103.0/96.0 - s2 * 11.0/24.0;
  a5  = s5 * 1097.0/960.0 + s1 * 5.0/96.0 - s3 * 43.0/64.0;
  /* Equation of Center */
  //a =  s1 * (e  *    2.0      - e3 * 1.0/4.0 + e5 *  5.0/96.0) +
  //     s2 * (e2 *    5.0/4.0  - 0.0          - e4 * 11.0/24.0) + 
  //     s3 * (e3 *   13.0/12.0 - 0.0          - e5 * 43.0/64.0) +
  //     s4 *  e4 *  103.0/96.0                                  +
  //     s5 *  e5 * 1097.0/960.0; 
  return e * (a1 + e * (a2 + e * (a3 + e * (a4 + e * a5))));
}

/* True longitude of Sun */
double tlSun(double ma, double t)
{
  double a;

  a = fmod( mlSun(t) + eqc(ma, t), DEGRAD);

  return a;
}

/* Apparent longitude of Sun */
double alSun(double ma, double t, double o)
{
  double a;

  a = fmod(tlSun(ma, t) - 
           0.00569 * RADEG - 
           0.00478 * RADEG * 
           sin(o), DEGRAD);

  return a;
}

/* Right ascension of Sun */
double raSun(double y0, double cos_al_Sun)
{
  return atan2(-y0, -cos_al_Sun);
}

/* Cosine of zenith */
double cosZ(double zenith)
{

  double ca;

  ca = cos(zenith * RADEG);

  return ca;
}

/* Cosine of apparent longitude Sun */
double cos_al_sun(double al_sun) 
{

  double ca;

  ca = cos(al_sun);

  return ca;
}

/* Cosine declination Sun */
double cos_dec_sun(double dec_sun) 
{

  double ca;

  ca = cos(dec_sun);

  return ca;
} 

/* Cosine local latitude */
double cos_lat(double lat) 
{

  double c_lat;

  c_lat = cos(lat * RADEG);

  return c_lat;
}                                   

/* Cosine true longitude Sun */
double cos_tl_sun(double tl_sun) 
{

  double ca;

  ca = cos(tl_sun);

  return ca;
}                                               

/* Cosine true obliquity Earth */
double cos_to_earth(double to_earth) 
{

  double ca;

  ca = cos(to_earth);

  return ca;
} 

/* Sine apparent longitude Sun */
double sin_al_sun(double al_sun) 
{

  double sa;

  sa = sin(al_sun);

  return sa;
}

/* Sine declination Sun */
double sin_dec_sun(double dec_sun) 
{

  double sa;

  sa = sin(dec_sun);

  return sa;
}  

/* Sine local latitude */
double sin_lat(double lat) 
{

  double sa;

  sa = sin(lat * RADEG);

  return sa;
}                                   

/* Sine true longitude Sun */
double sin_tl_sun(double tl_sun) 
{

  double sa;

  sa = sin(tl_sun);

  return sa;
}                                               

/* Sine true obliquity Earth */
double sin_to_earth(double to_earth) 
{

  double sa;

  sa = sin(to_earth);

  return sa;
} 

/* Solar angle from zenith */
double sun(double zenith, double dec_sun, double lat)
{
  double cos1 = cosZ(zenith);
  double sin2 = sin_dec_sun(dec_sun);
  double sin3 = sin_lat(lat);
  double cos2 = cos_dec_sun(dec_sun);
  double cos3 = cos_lat(lat);
  double top  = cos1 - sin2 * sin3;
  double bot  = cos2 * cos3;
  double ca   = top / bot;
  double c;
  c = (ca > 1.0 || ca < -1.0) ? 1.0: ca;    
  return acos(c);
}

/* Declination Sun */
double sun_dec(double al_sun, double to_earth) 
{
  double sin1 = sin_to_earth(to_earth);
  double sin2 = sin_al_sun(al_sun);
  double a   = asin(sin1 * sin2);
  return a;
}
// ***** end of prototypes *****/

int main()
{
	double lat = 41.9475360;
	double lon =  -88.7430640;
	
	double jd = time(0)/86400.0 + EJD;
	double mjd = jd - J2000;
	int iy, im, id;
	double fd;
	iauJd2cal(jd, 0, &iy, &im, &id, &fd);
	printf ("\tDate \t\t : %4d/%2.2d/%2.2d\n", iy, im, id );
  	
	printf ("\tJD \t\t\t : %f \n", jd);
	printf ("\tMJD \t\t\t : %f \n", mjd);
	printf ("\tFD \t\t\t : %f\n", fd );
	
	time_t rawtime;
	struct tm *info;

	time(&rawtime);
	/* Get GMT time */
	info = gmtime(&rawtime );
	printf("\tUTC \t\t\t : %2d:%02d:%2d\n", (info->tm_hour)%24, info->tm_min, info->tm_sec);
	return 0;
}
