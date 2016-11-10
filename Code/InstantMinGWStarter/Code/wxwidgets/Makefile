OBJ=main.o

#~ CXXFLAGS+=`wx-config --cxxflags --wxcfg=gcc_dll/mswu`
#~ LIBS+=`wx-config --libs --wxcfg=gcc_dll/mswu`

#~ wxwidgets.exe: $(OBJ)
	#~ $(CXX) -o $@ $^ $(LIBS)
	
LIBS+=`wx-config --libs --wxcfg=gcc`	
	
wxwidgets: $(OBJ)
	$(CXX) -o $@ $^ $(LIBS)	

clean:
	rm -f *.o *.exe
