CPP = gcc
CPPFLAGS = 
OFLAG = -g -Wall -std=gnu99 -O3
.SUFFIXES : .o .c
.c.obj :
	$(CPP) $(CPPFLAGS) -c $<

all: \
  file2 \
  fun1 \
  fun2 \
  fun3 \
  lab6 \
  scope \
  static \
  tstack

# file2: file2.o file1.o
	# $(CPP) file2.exe file2.o file1.o $(OFLAG)
	
# fun1: fun1.o
	# $(CPP) $(OFLAG)fun1 fun1.o
	
# fun2: fun2.obj
	# $(CPP) $(OFLAG)fun2 fun2.o 
	
# fun3: fun3.o
	# $(CPP) $(OFLAG)fun3 fun3.o 
	
# lab6: lab6.o employee.o
	# $(CPP) $(OFLAG)lab6 lab6.o employee.o
	
# scope: scope.obj
	# $(CPP) $(OFLAG)scope scope.o 
	
# static: static.obj
	# $(CPP) $(OFLAG)static static.o 
	
# tstack: tstack.obj stack.o
	# $(CPP) $(OFLAG)tstack tstack.o stack.o

# lab6.o: lab6.c employee.h
# stack.o: stack.c stack.h
# tstack.o: tstack.c stack.h
# file1.o: file1.c
# file2.o: file2.c
# fun1.o: fun1.c
# fun2.o: fun2.c
# fun3.o: fun3.c
# scope.o: scope.c
# static.o: static.c

