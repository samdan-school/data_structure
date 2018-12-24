CPP = g++
OPTS = -lglut -lGLU -lGL -I"./irrKlang/include" -L"/usr/lib" ./irrKlang/bin/linux-gcc-64/libIrrKlang.so -pthread

all:
	$(CPP) o_x.cpp -o ./compile/c.exe $(OPTS)

clean:
	rm example