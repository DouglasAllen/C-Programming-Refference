# Makefile to compile the examples provided by libgtkdatabox-dev package
# Andreas Tille <tille@debian.org>  Wed,  9 Apr 2003
# GPL

CFLAGS=-g -O2 -Wall -DG_DISABLE_DEPRECATED -DGDK_DISABLE_DEPRECATED -DGDK_PIXBUF_DISABLE_DEPRECATED -DGTK_DISABLE_DEPRECATED `pkg-config gtk+-2.0 libglade-2.0 --cflags`
LDFLAGS=`pkg-config gtk+-2.0 libglade-2.0 --libs` -s -lgtkdatabox

all: addremove basics basics2 basics_libglade colors enable_disable grid grid_array keycontrol lissajous logarithmic markers signals

clean:
	rm -rf *.o *~
