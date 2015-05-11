CPP = gcc
C++ = g++
CPPFLAGS =
OFLAG = -g -Wall -std=gnu99 -O3
.SUFFIXES : .o .c
.c.obj :
	$(CPP) $(CPPFLAGS) -c $<

all: \
  file2 \
  intstack.o \
  lab6 \
  lab7 \
  #~ scope \
  #~ static \
  #~ tstack

file2 : file2.o file1.o
	$(CPP) -o file2 file2.o file1.o $(OFLAG)

intstack.o:
	$(C++)$(CPPFLAGS) -c intstack.cpp
	
lab6: lab6.o employee.o
	$(CPP) -o lab6 lab6.o employee.o $(OFLAG)
lab6.o: employee.h	
	$(CPP) -c lab6.c -o lab6.o $(OFLAG)
	
lab7: lab7.o
	$(CPP) -o lab7 lab7.o $(OFLAG)
lab7.o: employ2.h	
	$(CPP) -c lab7.c -o lab7.o $(OFLAG)
# scope: scope.obj
	# $(CPP) $(OFLAG)scope scope.o 
	
# static: static.obj
	# $(CPP) $(OFLAG)static static.o 
	
#~ tstack: tstack.obj stack.o
	#~ $(CPP) -o tstack tstack.o stack.o $(OFLAG)




# stack.o: stack.c stack.h
# tstack.o: tstack.c stack.h
# file1.o: file1.c
# file2.o: file2.c
# fun1.o: fun1.c
# fun2.o: fun2.c
# fun3.o: fun3.c
# scope.o: scope.c
# static.o: static.c

.PHONY: clean
clean:
	rm *.o
	
.PHONY: delete
delete:
	rm 2d \
	