CXX = g++

CXXFLAGS = -Wall

all:
	$(CXX) $(CXXFLAGS) run_serial.cpp -o run_serial
	
clean:
	rm -f run_serial