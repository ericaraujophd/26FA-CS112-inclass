# Makefile for the List and Stack classes + Catch2 tests
#   make              -> build ./tests and ./tests-stack
#   make test         -> build and run the List tests
#   make test-stack   -> build and run the Stack tests
#   make test-verbose -> run the List tests showing every assertion
#   make test-stack-verbose -> run the Stack tests showing every assertion
#   make sanitize     -> rebuild with AddressSanitizer and run both test programs
#   make clean        -> remove build products
#
# Run only some tests by tag, e.g.:  ./tests "[append]"   or   ./tests-stack "[pop]"

CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -g

# Two test programs, each with its own main() (CATCH_CONFIG_MAIN).
# List is a template, so its code lives in List.h: there is no List.o to link.
TARGET       := tests
STACK_TARGET := tests-stack

all: $(TARGET) $(STACK_TARGET)

$(TARGET): tests.o
	$(CXX) $(CXXFLAGS) -o $@ $^

$(STACK_TARGET): tests-stack.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Each .o depends on its .cpp and on the project headers
%.o: %.cpp $(wildcard *.h) catch.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(TARGET)
	./$(TARGET)

test-stack: $(STACK_TARGET)
	./$(STACK_TARGET)

# Show the individual test results, not just the summary
test-verbose: $(TARGET)
	./$(TARGET) --success

test-stack-verbose: $(STACK_TARGET)
	./$(STACK_TARGET) --success

# Rebuild from scratch with AddressSanitizer and run the tests
sanitize: clean
	$(MAKE) CXXFLAGS="$(CXXFLAGS) -fsanitize=address"
	./$(TARGET)
	./$(STACK_TARGET)

clean:
	rm -f *.o $(TARGET) $(STACK_TARGET)
	rm -rf $(TARGET).dSYM $(STACK_TARGET).dSYM

.PHONY: all test test-stack test-verbose test-stack-verbose sanitize clean
