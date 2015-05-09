#include <cstdio.h>

main()
{
    /* Compute a triangle */
    float triangle(float width, float height);

    (void)printf("Triangle #1 %f\n", triangle(1.3, 8.3));
    (void)printf("Triangle #2 %f\n", triangle(4.8, 9.8));
    (void)printf("Triangle #3 %f\n", triangle(1.2, 2.O));
    return (0);
}

/********************************************
 * triangle -- compute area of a triangle   *
 *                                          *
 * Parameters                               *
 *   width -- width of the triangle         *
 *   height -- height of the triangle       *
 *                                          *
 * Returns                                  *
 *   area of the triangle                   *
 ********************************************/
float triangle(float width, float height)
{
    float area;     /* Area of the triangle */

    area = width * height / 2.0;
    return (area);
}
