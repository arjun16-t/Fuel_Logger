# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Target executable
TARGET = main

# Source files
SOURCES = main.cpp login.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Default rule (build the program)
all: $(TARGET)

# Rule to create the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

# Rule to compile each .cpp file into .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove compiled files
clean:
	rm -f $(TARGET) $(OBJECTS)
