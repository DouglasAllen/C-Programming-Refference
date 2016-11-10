OBJ=sorting.o

CXXFLAGS+=-pg

#~ sorting.exe: $(OBJ)
	#~ $(CXX) -o $@ $^ $(CXXFLAGS)
	
sorting: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)	

clean:
	rm -f *.o *.exe *.out *.dot profile*
