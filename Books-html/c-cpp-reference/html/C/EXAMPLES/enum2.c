/****************************************************************************
 *
 *  Enumeration example. Program will return the number of days in a month
 *  I.E. returns 28 for Feburary.
 *
 ****************************************************************************/
main()
{
					/*
					 * Define a list of aliases
					 */
  enum days {Jan=31, Feb=28, Mar=31, 
             Apr=30, May=31, Jun=30, 
             Jul=31, Aug=31, Sep=30, 
             Oct=31, Nov=30, Dec=31};
   /*     A      A
          |      |
          |      |
	  |      -------  list of aliases.
	  --------------  Enumeration tag.	*/
    

  enum days month;		/* define 'month' variable of type 'months' */

  printf("%d\n", month=Feb);	/* Assign integer value via an alias	    
				 * This will return 28 			    */
}
