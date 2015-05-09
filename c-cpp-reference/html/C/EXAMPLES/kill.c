

main()
{
  int pid;

  /* ...	Get the process ID of this program. */

  getpid(pid);

  /* ...	Check to see if this program is active. */

  printf("R = %d\n", kill (pid, 0));
}
  

