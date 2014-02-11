win32-app.exe: main.cpp resource.rc.res.o
	g++ -o win32-app.exe main.cpp resource.rc.res.o

resource.rc.res.o: resource.rc
	windres -o resource.rc.res.o -i resource.rc

clean:
	rm -f *.o win32-app.exe
	