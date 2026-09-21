# Makefile for the Pair class + Catch2 tests
#   make        -> build ./tests
#   make test   -> build and run the tests
#   make clean  -> remove build products

CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -g

TARGET := tests

# Every .cpp in this folder (tests-main.cpp today, Pair.cpp when you add it)
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Each .o depends on its .cpp and on the project headers
%.o: %.cpp $(wildcard *.h) catch.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(TARGET)
	./$(TARGET)

# Show the individual test results, not just the summary
test-verbose: $(TARGET)
	./$(TARGET) --success

clean:
	rm -f $(OBJS) $(TARGET)
	rm -rf $(TARGET).dSYM

.PHONY: all test test-verbose clean
