
/* see page 163 */

#ifdef ASTROALGO
   #include <math.h>
   #include <stdio.h>
   #include "AstroAlgo.h"

   __declspec(dllexport) short __stdcall
#else
   short
#endif

ShSolarCoordinates(double doJD, double *pdomC, double *pdoalpha, double *pdolambda, double *pdodelta,
                   short shMethod)
           /* method = 1 : "low accuracy",    p.163
              method = 2 : "higher accuracy", p.166 */

   {
   short  shReturnValue = (short) 0;

   if (pdoalpha != NULL)
      {
      *pdoalpha = (double) 0;
      }

   if (pdodelta != NULL)
      {
      *pdodelta = (double) 0;
      }

   if (   ((shMethod == 1) && (doJD < 0) || (doJD > 9999999))
       || ((shMethod == 2) && (doJD < 0) || (doJD > 9999999))
      )
      {
      shReturnValue = (short) 1;
      }

   else if (pdoalpha == NULL)
      {
      shReturnValue = (short) 2;
      }

   else if (pdodelta == NULL)
      {
      shReturnValue = (short) 3;
      }

   else if ((shMethod != 1) && (shMethod != 2))
      {
      shReturnValue = (short) 4;
      }

   else if (shMethod == 1)
      {
      double doT     = (double) 0; /* Julian Centuries */
      double doLo    = (double) 0; /* geometric mean longitude of the sun */
      double doM     = (double) 0; /* mean anomaly */
      double doC     = (double) 0; /* Sun's equation of center */
      double doLong  = (double) 0; /* true longitude of the sun */
      double doomega = (double) 0; /* nutation */
      double dolamda = (double) 0; /* apparent longitude of the sun */
      double doe     = (double) 0; /* mean obliquity of the ecliptic */

      /* Julian Centuries */
      doT = DO_JULIAN_CENTURIES(doJD);
      #ifdef DEBUG_SHSOLAR_COORDINATES
      (void) fprintf(stdout, "doT = %f\n", doT);
      #endif

      /* geometric mean longitude of the sun */
      doLo =     (double)   280.46646
              + ((double) 36000.76983   * doT)
              + ((double)     0.0003032 * doT * doT);

      /* mean anomaly of the sun */
      doM =     (double)   357.52911
             + ((double) 35999.05029    * doT)
             - ((double)     0.0001537  * doT * doT);

      /* Sun's equation of center */
      doC =    (  (    (double) 1.914602
                    - ((double) 0.004817 * doT)
                    - ((double) 0.000014 * doT * doT)
                  )
                * sin(DEGREES2RADIAN(doM))
               )
            +  (  (    (double) 0.019993
                    - ((double) 0.000101 * doT)
                  )
                * sin(DEGREES2RADIAN((2 * doM)))
               )
            + ((double) 0.000289 * sin(DEGREES2RADIAN((3 * doM))));
      
			*pdomC = doC * -1;
      /* Sun's true longitude */
      doLong = doLo + doC;

      doomega = (double) 125.04 - ((double) 1934.136 * doT);

      /* apparent longitude of the sun */
      dolamda = REDUCE360(  doLong
                          -  (double) 0.00569
                          - ((double) 0.00478 * sin(DEGREES2RADIAN(doomega)))
                         );
      *pdolambda = dolamda;
      /* mean obliquity of the ecliptic */
      doe =   (((double) 23 * (double) 3600) + ((double) 26 * (double) 60))
            +  (double) 21.448
            - ((double) 46.8150  * doT)
            - ((double) 0.00059  * doT * doT)
            + ((double) 0.001813 * doT * doT * doT);
      doe /= (double) 3600;

      /* correct mean obliquity of the ecliptic */
      doe = doe + (double) 0.00256 * cos(DEGREES2RADIAN(doomega));

      /* calculate right ascension and declination */
      *pdoalpha = REDUCE360(RADIAN2DEGREES(atan2(cos(DEGREES2RADIAN((doe)))
                                           * sin(DEGREES2RADIAN(dolamda)),
                                           cos(DEGREES2RADIAN(dolamda)))));
      *pdodelta = RADIAN2DEGREES( asin(  sin(DEGREES2RADIAN(doe))
                                       * sin(DEGREES2RADIAN(dolamda)))
                                );
      }

   else if (shMethod == 2)
      {
      ;
      }

   return shReturnValue;
   }

