#include<stdio.h>
#include<dos.h>

int main()
{
	struct date *dt;

  getdate(&dt);

   printf("Operating system's current date is %d-%d-%d\n",
	 dt.da_day, dt.da_mon, dt.da_year);

   return 0;
}