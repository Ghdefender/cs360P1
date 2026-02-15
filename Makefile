CXX = g++

CXXFLAGS = -Wall

all: run_serial cpu_test run_concurrent
	
run_serial:
	$(CXX) $(CXXFLAGS) run_serial.cpp -o run_serial
	
run_concurrent:
	$(CXX) $(CXXFLAGS) run_concurrent.cpp -o run_concurrent

cpu_test:
	$(CXX) $(CXXFLAGS) cpu_test.cpp -o cpu_test

clean:
	rm -f run_serial cpu_test run_concurrent

