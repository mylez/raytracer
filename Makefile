# based on hw3 makefile for mac

#
# clang -L/usr/local/opt/libomp/lib -I/opt/homebrew/include -Xpreprocessor -fopenmp omp_hello.c -lomp
#
CC = g++
CFLAGS = -g -O3 -Xpreprocessor -fopenmp -std=c++11 -Wno-deprecated-register -Wno-deprecated-declarations
INCFLAGS = -I./include -I/opt/homebrew/include -I./glm-0.9.7.1
LDFLAGS = -L/opt/homebrew/lib -lm -lfreeimage -lomp


SOURCES := $(wildcard src/*.cpp)
OBJECTS := main.o $(patsubst src/%.cpp,%.o,$(SOURCES))

all: ray

fresh_scene:
	rm -f Scene.o
	make ray

ray: $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: main.cpp
	$(CC) $(CFLAGS) $(INCFLAGS) -c $<

%.o: src/%.cpp
	$(CC) $(CFLAGS) $(INCFLAGS) -c $<

.PHONY: clean
clean:
	rm -f $(OBJECTS)
