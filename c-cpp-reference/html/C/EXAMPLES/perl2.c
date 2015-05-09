/********************************************************************
 *
 * Date:    11-May-97
 *
 * Purpose: Imbed PERL code in C.
 *
 * Notes:   This code is based on the examples found in the
 *          Perl man pages.
 *
 * Compile: To compile this code you will need a starement simular too:
 *
 *  g++ perl2.c -L/usr/lib/perl5/i586-linux/5.003/CORE
 *              -I/usr/lib/perl5/i586-linux/5.003/CORE
 *              -lperl
 *              -lm
 *
 * This program uses the C++ compiler as there seem to be problems
 * With the header files on Linux when using GCC.
 *
 ********************************************************************/

#include <stdio.h>
#include <EXTERN.h>
#include <perl.h>

/********************************************************************/

PerlInterpreter        *my_perl;

void PerlInit(char **env);
int  PerlEval(char  *string);
void PerlEnd (void);

/********************************************************************/

main (
  int                   argc,
  char                **argv,
  char                **env)
{
  unsigned int          Length;

  // ...        Initalise.

  PerlInit(env);

  // ...        Some basic Perl statements
  
  PerlEval("$a = 3;");
  PerlEval("$a = $a+2;");

  // ...        Extract an integer perl value into the C code.
  
  printf("a = %d\n", SvIV(perl_get_sv("a", FALSE)));

  PerlEval("$a = $a+2.5;");

  // ...        Extract a float perl value into the C code.
  
  printf("a = %f5.2\n", SvNV(perl_get_sv("a", FALSE)));

  // ...        Play with strings.
  
  PerlEval("$a = 'rekcaH lreP rehtonA tsuJ';");
  PerlEval("$a = reverse($a); ");

  // ...        Extract a string perl value into the C code.

  printf("a = %s\n", SvPV(perl_get_sv("a", FALSE), Length));

  printf("%d\n", Length);
  
  // ...        Tidy up.

  PerlEnd();
}

/********************************************************************/

void PerlInit( char **env)
{
  char                 *Embedding[] = { "", "-e", "sub _eval_ { eval $_[0] }" };    

  my_perl = perl_alloc();
  perl_construct( my_perl );

  perl_parse(my_perl, NULL, 3, Embedding, env);
}

/********************************************************************/

int PerlEval(char *string)
{
  char *argv[2];
  argv[0] = string;
  argv[1] = NULL;
  perl_call_argv("_eval_", 0, argv);
}

/********************************************************************/

void PerlEnd(void)
{
    perl_destruct(my_perl);
  perl_free(my_perl);
}
