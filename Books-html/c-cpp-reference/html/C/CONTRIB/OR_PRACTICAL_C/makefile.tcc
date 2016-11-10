CC=tcc
CFLAGS=-ml -g -w -A
SRCS=tlint.c   macros.c   symbol.c   fonts.c
OBJS=tlint.obj macros.obj symbol.obj fonts.obj

tlint: $(OBJS)
        $(CC) $(CFLAGS) -etlint $(OBJS)

fonts.obj: fonts.c gen.h symbol.h
        $(CC) $(CFLAGS) -c fonts.c

macros.obj: font.h gen.h macro.h macros.c symbol.h
        $(CC) $(CFLAGS) -c macros.c

symbol.obj: symbol.c symbol.h
        $(CC) $(CFLAGS) -c symbol.c

tlint.obj: font.h gen.h macro.h tlint.c
        $(CC) $(CFLAGS) -c tlint.c
