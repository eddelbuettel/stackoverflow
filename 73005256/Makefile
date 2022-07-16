
sources :=      $(wildcard *.cpp)
objects :=      $(sources:.cpp=.o)

CXXFLAGS = -Wall -pedantic -O2

myapp:		$(objects)
		$(CXX) -o $@ $^
