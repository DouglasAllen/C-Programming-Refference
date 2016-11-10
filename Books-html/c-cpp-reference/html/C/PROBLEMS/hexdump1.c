/************************************************************************
 *
 * Purpose: To display a file in (mainframe) dump format as shown below.
 *
 *      20 2A 20 68 65 78 5F 63 68 61 72 28 63 68 61 72     * hex_char(char
 *      20 2A 70 6F 73 69 74 69 6F 6E 2C 20 63 68 61 72     *position, char
 *      20 63 29 0A 20 20 20 7B 0A 20 20 20 73 70 72 69     c).   {.   spri
 *      6E 74 66 28 70 6F 73 69 74 69 6F 6E 2C 20 22 25    ntf(position, "%
 *      30 32 58 20 22 2C 20 63 29 3B 20 0A 0A 09 09 09    02X ", c); .....
 * 
 * Syntax:  hexdump filename
 *
 * Method:  The program fills a variable (line) with the data, when 
 *	    the variable is full - it is sent to STDOUT.
 *	    Unprintable charcters are converted to '.' in the ASCII 
 *	    display on the right.
 *
 * Bugs:    If the last line of the dump is full, the program will 
 *	    follow it with a blank line. Not exactly a serious bug
 *	    but you are welcome to fix it.
 *
 * To do:   o Highlight '0A' (end of line) - seems like a good idea.
 *	    o Get it to read directories.
 *	    o Remove the directory info from argv[0] (if present).
 *	    o Add a column showing the byte offset.
 *
 * Author:  M J Leslie
 *
 * Rev	Date		Comments
 * ---  ---------	--------
 * 1.0  08-Feb-94	Inital Release.
 *
 * 1.1  12-May-95	Original only worked for the hex range 00-7F
 *			This version supports 00-FF. 
 *			Thanks to Emmanuel Guyot for the fix.
 *
 ************************************************************************/

#include <stdio.h>

#define HEX_OFFSET    1
#define ASCII_OFFSET 51
#define NUM_CHARS    16

/************************************************************************/

void   hexdump    (char* prog_name, char * filename);

					/* Clear the display line.	*/
void   clear_line (char *line, int size);

					/* Put a character (in hex format
					 * into the display line.	*/
char * hex_char   (char *position, int c);

					/* Put a character (in ASCII format
					 * into the display line.	*/
char * ascii_char (char *position, int c);

/************************************************************************/

main(int argc, char * argv[])
   {
   char *prog_name="hexdump";

   if (argc != 2)
      {
      printf("\n\t%s syntax:\n\n", argv[0]);
      printf("\t\t%s filename\n\n", argv[0]);
      exit(0);
      }
   
   hexdump( argv[0], argv[1]);
   }

/************************************************************************
 *
 *	The program proper.
 *
 ************************************************************************/
 
void hexdump(char* prog_name, char * filename)
   {
   int c=' ';                		/* Character read from the file	*/

   char * hex_offset;			/* Position of the next character 
					 * in Hex			*/

   char * ascii_offset;			/* Position of the next character 
					 * in ASCII.			*/

   FILE *ptr;                      	/* Pointer to the file. 	*/

   char line[81];		   	/* O/P line.			*/

                                   	/* Open the file 		*/
   ptr = fopen(filename,"r");
   if ( ferror(ptr) )
      {
      printf("\n\t%s: Unable to open %s\n\n", prog_name, filename);
      exit(0);
      }
					/* little heading.		*/
   printf("\n\tHex dump of %s\n\n", filename);

                                   	/* Read one character at a time, 
				    	 * checking for the End of File.
					 * EOF is defined in <stdio.h> 	*/
   while (c != EOF )
      {
			           	/* Prepare the variables.	*/		
      clear_line(line, sizeof line);
      hex_offset   = line+HEX_OFFSET;
      ascii_offset = line+ASCII_OFFSET;

      while ( ascii_offset < line+ASCII_OFFSET+NUM_CHARS 
              &&(c = fgetc(ptr)) != EOF  )
         {
			           	/* Build the hex part of 
					 * the line.			*/
         hex_offset = hex_char(hex_offset, c); 

			           	/* Build the Ascii part of 
					 * the line.			*/
         ascii_offset = ascii_char(ascii_offset, c);

         }
					/* Display the current line	*/
      printf("%s\n", line);
      }

   fclose(ptr);                    	/* Close the file.              */
   }

/************************************************************************
 *
 *	Clear the display line.
 *
 ************************************************************************/

void clear_line(char *line, int size)
   {
   int count;

   for  (count=0; count < size; line[count]=' ', count++);
   }

/************************************************************************
 *
 *	Put a character into the display line and return the location 
 * 	of the next character.
 *
 ************************************************************************/
char * ascii_char(char *position, int c)
   {
					/* If the character is NOT printable
					 * replace it with a '.'	*/
   if (!isprint(c)) c='.';
     
   sprintf(position, "%c", c); 		/* Put the character to the line
					 * so it can be displayed later	*/

					/* Return the position of the next 
					 * ASCII character.		*/
   return(++position);
   }

/************************************************************************
 *
 *	Put the hex value of a character into the display line and 
 *	return the location of the next  hex character.
 *
 ************************************************************************/
char * hex_char(char *position, int c)
   {
   int offset=3;
				/* Format and place the character into 
				 * the display line.	
				 * (unsigned char) required for correct
				 * O/P.					*/

   sprintf(position, "%02X ", (unsigned char) c); 

   *(position+offset)=' '; 	/* Remove the '/0' created by 'sprint'	*/

   return (position+offset);
   }
