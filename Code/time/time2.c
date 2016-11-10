#include <math.h>
#include <stdio.h>
#include <time.h>
#define EPOCH (double)  2440587.5 /* Julian Day number for Jan. 01, 1970 midnight*/
#include "AstronomicalAlgorithms.h"
#include "SolarCoordinates.c"
int main ()
{
	short sh1 = (short) 0;
	short  shMethod = (short)        1;
	double days = time(0)/86400.0;
	double doJD     = (double) days + EPOCH;
	double domc  = (double)       0;
	double doalpha  = (double)       0;
	double dolambda  = (double)       0;
	double dodelta  = (double)       0;
	sh1 = ShSolarCoordinates(doJD, &domc, &doalpha, &dolambda, &dodelta, shMethod);
	if (sh1 != 0)
	{
		(void) fprintf(stdout,
			       "\nShSolarCoordinates() returns %hd\n", sh1);
	}
	else
	{
		(void) fprintf(stdout,
			       "\ndoalpha = %f, dolambda = %f\n, dodelta = %f\n", doalpha, dolambda, dodelta);
		(void) fprintf(stdout,
			       "\ndt1 = %f\n", domc);
		(void) fprintf(stdout,
			       "\ndt2 = %f\n", dolambda - doalpha);
		(void) fprintf(stdout,
			       "\ndt = %f\n", domc + dolambda - doalpha);
	}


	printf ("\n%f days since January 1, 1970\n", days);

	printf ("\n%f\n", days + EPOCH);
	printf ("%f\n", days + EPOCH - EPOCH);	

	return 0;	
}


