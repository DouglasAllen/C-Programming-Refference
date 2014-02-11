OBJ=z_pack.o

CXXFLAGS+=-I..\core
LIBS+=-L..\core -lcore

z_pack.exe: $(OBJ)
	$(CXX) -o $@ $^ $(LIBS)

clean:
	rm -f *.o *.exe *.dll
