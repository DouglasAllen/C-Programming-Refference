/************************************************************************ 
 *
 * Purpose: Part one of a two part example showing the 
 *          extern keyword in action.
 *
 * Author:  M. J. Leslie
 *
 * Date:    24-Oct-95
 *
 ************************************************************************/

void write_extern(void);

extern int count;

void write_extern(void)
{
  printf("count is %i\n", count);
}

  
