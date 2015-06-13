GCode : GCode.o 
	gcc -o GCode GCode.o
GCode.o : GCode.c error.h 
	gcc -c GCode.o GCode.c
error.h : bool.h

