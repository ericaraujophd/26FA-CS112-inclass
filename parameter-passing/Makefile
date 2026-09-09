# Makefile for the parameter-passing example
#   make        -> build ./main
#   make run    -> build and run
#   make clean  -> remove build products

CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -g

TARGET  := main
SRCS    := main.cpp function.cpp
OBJS    := $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Each .o depends on its .cpp and on the header
%.o: %.cpp function.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all run clean
