
float point_color(point_number)
int point_number;
{
    float correction;  /* color correction factor */
    extern float red,green,blue;/* current colors */

    correction = lookup(point_number);
    return (red*correction * 100.0 + 
            blue*correction * 10.0 +
            green*correction);
}
