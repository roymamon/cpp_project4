# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17

# SFML library paths
SFML_LIB_PATH = /usr/lib/x86_64-linux-gnu
SFML_INCLUDE_PATH = /usr/include

# SFML libraries
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Source and target
SOURCES = Demo.cpp
TEST_SOURCES = Test.cpp
TARGET = demo
TEST_TARGET = test

# Build main executable
all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -I$(SFML_INCLUDE_PATH) -o $(TARGET) $(SOURCES) -L$(SFML_LIB_PATH) $(LIBS)

# Build test executable
$(TEST_TARGET): $(TEST_SOURCES)
	$(CXX) $(CXXFLAGS) -I$(SFML_INCLUDE_PATH) -o $(TEST_TARGET) $(TEST_SOURCES) -L$(SFML_LIB_PATH) $(LIBS)

# Clean up build files
clean:
	rm -f $(TARGET) $(TEST_TARGET) *.o
