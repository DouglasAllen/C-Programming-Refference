OBJ=main.o

#~ CXXFLAGS+=`pkg-config --cflags gtk+-win32-2.0`
CXXFLAGS+=`pkg-config --cflags gtk+-2.0` 
                       
#~ LIBS+=`pkg-config --libs gtk+-win32-2.0`
LIBS+=`pkg-config --libs gtk+-2.0`


#~ gtk.exe: $(OBJ)
	#~ $(CXX) -o $@ $^ $(LIBS)

gtk: $(OBJ)
	$(CXX) -o $@ $^ $(LIBS)

clean:
	rm -f *.o *.exe
