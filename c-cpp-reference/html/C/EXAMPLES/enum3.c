/****************************************************************************
 *
 *  Enumeration example: This program will fail to compile because
 *  'Alex' is in both enum lists.
 *
 ****************************************************************************/
main()
{

  enum People1 {Alex=0,    Tracy,  Kristian} Girls;
  enum People2 {William=0, Martin, Alex}     Boys;
  /*     A      A
         |      |
         |      |
         |      -------  list of aliases.
         --------------  Enumeration tag.	*/
    

  switch (Boys)
  {
  case William:
    puts("William");
    break;

  case Martin:
    puts("Martin");
    break;

  case Alex:
    puts("Alex");
    break;

  default:
    break;
  }
}
