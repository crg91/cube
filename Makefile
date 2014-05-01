all:	cube
cube:	cube.o
	g++ -o cube cube.o -g -lGL -lglut -lGLEW
cube.o:	cube.cpp
	g++ -g -c cube.cpp
clean:
	rm cube cube.o
