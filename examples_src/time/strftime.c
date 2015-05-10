#include <stdio.h>
#include <time.h>

int main ()
{
	time_t rawtime;
	struct tm *info;
	char buffer[80];
	char hdr_date[999] = "";

	time( &rawtime );

	info = localtime( &rawtime );

	strftime(buffer,80,"%x - %I:%M%p", info);
	printf("Formatted date & time : |%s|\n", buffer );
	
  if ( strftime( hdr_date, 78, "Date: %a, %d %b %Y %T %z", info ) )
    puts( hdr_date );
  else
    return -1;
  
   return(0);
}