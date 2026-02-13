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
=======
CXX = g++

CXXFLAGS = -Wall

all:
	$(CXX) $(CXXFLAGS) run_serial.cpp -o run_serial
	
clean:
	rm -f run_serial
>>>>>>> ebff6c55deea9466937f9cbf9f2e2b573e702149
