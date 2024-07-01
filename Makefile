#id:207988213 email:haleviadiel@gmail.com

CXX = g++
CXXFLAGS = -std=c++11

all: tree tests

tree: Demo.o
	$(CXX) $(CXXFLAGS) -o tree Demo.o

tests: Tests.o
	$(CXX) $(CXXFLAGS) -o tests Tests.o

Demo.o: Demo.cpp Tree.hpp Node.hpp Complex.hpp
	$(CXX) $(CXXFLAGS) -c Demo.cpp

Tests.o: Tests.cpp Tree.hpp Node.hpp Complex.hpp
	$(CXX) $(CXXFLAGS) -c Tests.cpp

clean:
	rm -f *.o tree tests