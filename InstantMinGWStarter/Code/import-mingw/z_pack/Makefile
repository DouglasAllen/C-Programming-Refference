OBJ=z_pack.o

MINGW_DIR=C:\MinGW
CXXFLAGS+=-I..\core
LIBS+=-L..\core -lcore -L$(MINGW_DIR)\lib -lboost_program_options -lboost_iostreams -L$(MINGW_DIR)\git\bin -lz

z_pack.exe: $(OBJ)
	$(CXX) -o $@ $^ $(LIBS)

clean:
	rm -f *.o *.exe
