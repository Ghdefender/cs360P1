<<<<<<< HEAD
CXX = g++

CXXFLAGS = -Wall

all: run_serial cpu_test
	
run_serial:
	$(CXX) $(CXXFLAGS) run_serial.cpp -o run_serial
	
cpu_test:
	$(CXX) $(CXXFLAGS) cpu_test.cpp -o cpu_test

clean:
	rm -f run_serial cpu_test

