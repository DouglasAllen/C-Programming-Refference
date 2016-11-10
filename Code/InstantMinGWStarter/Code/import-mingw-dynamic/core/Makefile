OBJ=options.o packer.o

MINGW_DIR=C:\MinGW
CXXFLAGS+=-I$(MINGW_DIR)\include
LIBS+=-L$(MINGW_DIR)\lib -lboost_program_options -lboost_iostreams -L$(MINGW_DIR)\git\bin -lz


libcore.dll: $(OBJ)
	$(CXX) -shared -o $@ $^ $(LIBS)

clean:
	rm -f *.o *.dll
