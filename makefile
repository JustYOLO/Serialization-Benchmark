CXX = g++
CXXFLAGS = -g -std=c++17 -Wall -Wextra
LDFLAGS = -lbenchmark

OBJS = main.o data_generator.o

all: main

main: $(OBJS)
	$(CXX) $(OBJS) -o main $(LDFLAGS) -g

data_generator.o: data_generator.cpp data_generator.h
	$(CXX) $(CXXFLAGS) -c data_generator.cpp

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f *~ *.o main

.PHONY: all clean