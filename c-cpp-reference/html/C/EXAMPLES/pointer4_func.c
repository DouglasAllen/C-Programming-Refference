int set(char *items[]);

main()
{
  char *items[]={"apple", "pear", "banana", "grape"};

  set (items);

}

int set(char *items[])
{
  printf ("/t%s\n", items[2]);
}

/**********************************************************************
 *
 * Result is  
 * 	banana
 *
 **********************************************************************/
