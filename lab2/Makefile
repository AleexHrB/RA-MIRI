# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -O2 -Wall -std=c++17

# Target executable
TARGET = main 

# Source files
SRC = main.cc

# Default rule
all: $(TARGET) generateData

# Compile the executable
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Clean object files and executable
clean:
	rm -f $(TARGET)
	rm -f generateData

