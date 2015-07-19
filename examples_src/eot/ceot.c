/* gcc -o ceot ceot.c -lm -lsofa_c */

#include <stdio.h>
#include <time.h>
#include <sofa.h>

#ifndef PI
#define PI        3.1415926535897932384
#endif

#define RADEG 0.0174532925199
#define DEGRAD 57.2957795457

/* 1.1.1970 = JD 2440587.5 */
#define EJD (double) 2440587.5

#define J2000 (double) 2451545.0

/***************************************/
/* Mean geocentric longitude of the Sun */
double ml_Sun(double t);

/* True longitude of Sun */
double tl_Sun(double ma, double t);
/* Sine true longitude Sun */
double sin_tl_Sun(double tl_Sun);
/* Cosine true longitude Sun */
double cos_tl_Sun(double tl_Sun);

/* Apparent longitude of Sun */
double al_Sun(double ma, double t, double o);
/* Cosine of apparent longitude Sun */
double cos_al_Sun(double al_Sun);
/* Sine apparent longitude Sun */
double sin_al_Sun(double al_Sun);

/* Eccentricity of Earth orbit */
double eoe(double t);

/* Equation of Center */
double eqc(double ma, double t);

/* Right ascension of Sun */
double raSun(double y0, double cos_al_Sun);

/* Declination Sun */
double dec_Sun(double al_sun, double to_Earth);
/* Sine declination Sun */
double sin_dec_Sun(double dec_Sun);
/* Cosine declination Sun */
double cos_dec_Sun(double dec_Sun);

/* Cosine of zenith */
double cos_Z(double zenith);

/* Sine local latitude */
double sin_lat(double lat);
/* Cosine local latitude */
double cos_lat(double lat);

/* Cosine true obliquity Earth */
double cos_to_Earth(double to_Earth);
/* Sine true obliquity Earth */
double sin_to_Earth(double to_Earth);

/* Solar angle from zenith */
double sun(double zenith, double dec_Sun, double lat);

/* Mean geocentric longitude of the Sun */
double ml_Sun(double t)
{
	double a;

	a = fmod(280.4664567     +
	 t * (36000.76982779     +
	 t * (    0.0003032028   +
	 t * (    1.0/499310.0   +
	 t * (    1.0/-152990.0  +
	 t * (1.0/-19880000.0 ) ) ) ) ), 360.0 );

	return a * RADEG;
}

/* True longitude of Sun */
double tl_Sun(double ma, double t)
{
	double a;

	a = fmod( ml_Sun(t) + eqc(ma, t), DEGRAD);

	return a;
}

/* Cosine true longitude Sun */
double cos_tl_Sun(double tl_Sun) 
{

	double ca;

	ca = cos(tl_Sun);

	return ca;
}  

/* Sine true longitude Sun */
double sin_tl_Sun(double tl_Sun) 
{

	double sa;

	sa = sin(tl_Sun);

	return sa;
}      

/* Apparent longitude of Sun */
double al_Sun(double ma, double t, double omega)
{
	double a;

	a = fmod(tl_Sun(ma, t) - 
		 0.00569 * RADEG - 
		 0.00478 * RADEG * 
		 sin(omega), DEGRAD);

	return a;
}

/* Cosine of apparent longitude Sun */
double cos_al_Sun(double al_Sun) 
{

	double ca;

	ca = cos(al_Sun);

	return ca;
}

/* Sine apparent longitude Sun */
double sin_al_Sun(double al_Sun) 
{

	double sa;

	sa = sin(al_Sun);

	return sa;
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

/* Right ascension of Sun */
double ra_Sun(double y0, double cos_al_Sun)
{
	return atan2(-y0, -cos_al_Sun);
}

/* Declination Sun */
double sun_dec(double al_Sun, double to_Earth) 
{
	double sin1 = sin_to_Earth(to_Earth);
	double sin2 = sin_al_Sun(al_Sun);
	double a   = asin(sin1 * sin2);
	return a;
}

/* Sine declination Sun */
double sin_dec_Sun(double dec_Sun) 
{

	double sa;

	sa = sin(dec_Sun);

	return sa;
}  

/* Cosine declination Sun */
double cos_dec_Sun(double dec_Sun) 
{

	double ca;

	ca = cos(dec_Sun);

	return ca;
} 

/* Cosine of zenith */
double cosZ(double zenith)
{

	double ca;

	ca = cos(zenith * RADEG);

	return ca;
}

/* Cosine local latitude */
double cos_lat(double lat) 
{

	double c_lat;

	c_lat = cos(lat * RADEG);

	return c_lat;
}                                   

/* Sine local latitude */
double sin_lat(double lat) 
{

	double sa;

	sa = sin(lat * RADEG);

	return sa;
}                                            

/* Cosine true obliquity Earth */
double cos_to_Earth(double to_Earth) 
{

	double ca;

	ca = cos(to_Earth);

	return ca;
}  

/* Sine true obliquity Earth */
double sin_to_Earth(double to_Earth) 
{

	double sa;

	sa = sin(to_Earth);

	return sa;
} 

/* Solar angle from zenith */
double sun(double zenith, double dec_Sun, double lat)
{
	double cos1 = cosZ(zenith);
	double sin2 = sin_dec_Sun(dec_Sun);
	double sin3 = sin_lat(lat);
	double cos2 = cos_dec_Sun(dec_Sun);
	double cos3 = cos_lat(lat);
	double top  = cos1 - sin2 * sin3;
	double bot  = cos2 * cos3;
	double ca   = top / bot;
	double c;
	c = (ca > 1.0 || ca < -1.0) ? 1.0: ca;    
	return acos(c);
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
	printf ("\tDate \t\t\t\t\t: %4d/%2.2d/%2.2d\n", iy, im, id );

	printf ("\tJD \t\t\t\t\t\t: %f \n", jd);
	printf ("\tMJD \t\t\t\t\t\t: %f \n", mjd);
	printf ("\tFD \t\t\t\t\t\t: %f\n", fd );

	time_t rawtime;
	struct tm *info;

	time(&rawtime);
	/* Get GMT time */
	info = gmtime(&rawtime );
	printf("\tUTC \t\t\t\t\t\t: %2d:%02d:%2d\n", (info->tm_hour)%24, info->tm_min, info->tm_sec);

	double t = mjd / 36525.0;

	double sma = iauFalp03(t);
	printf("\tmean anomaly Sun\t\t\t: %lf11 deg.\n", sma * DEGRAD);
	double sta = eqc(sma, t) + sma;
	printf("\ttrue anomaly Sun\t\t\t: %lf11 deg.\n", sta * DEGRAD);
	double orbit_angle = sma - sta;
	printf("\torbital angle Sun\t\t\t: %lf11 deg.\n", orbit_angle * DEGRAD);

	double sml = ml_Sun(t);
	printf("\tmean longitude Sun\t\t\t: %lf11 deg.\n", sml * DEGRAD);
	double stl = tl_Sun(sma, t);
	printf("\ttrue longitude Sun\t\t\t: %lf11 deg.\n", stl * DEGRAD);	
	double omega = iauFaom03(t);
	double sal = al_Sun(sma, t, omega);
	printf("\tapparent longitude Sun\t\t: %lf11 deg.\n", sal * DEGRAD);

	double mo_Earth = iauObl06(jd, 0);
	double dpsi, deps;
	iauNut06a(jd, 0,&dpsi, &deps);
	double to_Earth = mo_Earth + deps;
	printf("\ttrue obliquity Earth\t\t\t: %lf11 deg.\n", to_Earth * DEGRAD);	
	double y0 = sin_al_Sun(sal) * cos_to_Earth(to_Earth);
	double cos_al_sun = cos_al_Sun(sal);
	double sra = iauAnp(PI + ra_Sun(y0, cos_al_sun));
	printf("\tright ascension Sun\t\t\t: %lf11 deg.\n", sra * DEGRAD);

	double obliquity_angle = sal - sra;
	printf("\tobliquity angle Sun\t\t\t: %lf11 deg.\n", obliquity_angle * DEGRAD);
	double eot_angle = orbit_angle + obliquity_angle;
	printf("\tdelta total\t\t\t\t\t: %lf11 deg.\n", eot_angle * DEGRAD);
	printf("\tdelta total minutes\t\t\t: %lf11\n", eot_angle * DEGRAD / 15 *  60);
	printf("\tcompare with http://equationoftime.herokuapp.com/eot");

	return 0;
}
