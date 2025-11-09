# Makefile to compile galton.cc with optimization -O2

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -O2 -Wall -std=c++17

# Target executable
TARGET = bins

# Source files
SRC = bins.cc

# Default rule
all: $(TARGET)

# Compile the executable
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Clean object files and executable
clean:
	rm -f $(TARGET)

