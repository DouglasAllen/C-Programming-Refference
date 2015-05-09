/*
 * Define a variable to hold an integer or 
 * a real number (but not both)
 */
union value {
    long int i_value;   /* The real number */
    float f_value;      /* The floating-point number */
} data;
int i;                  /* Random integer */
float f;                /* Random floating-point number */
main()
{
    data.f_value = 5.0;
    data.i_value = 3;   /* data.f_value overwritten */
    i = data.i_value;   /* legal */
    f = data.f_value;   /* not legal, will generate unexpected results */
    data.f_value = 5.5; /* put something in f_value/clobber i_value */
    i = data.i_value;   /* not legal, will generate unexpected results */
}
