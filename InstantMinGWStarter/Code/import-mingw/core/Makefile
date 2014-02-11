OBJ=options.o packer.o

CXXFLAGS+=-IC:\MinGW\include

libcore.a: $(OBJ)
	$(AR) rcs $@ $^

clean:
	rm -f *.o *.a
