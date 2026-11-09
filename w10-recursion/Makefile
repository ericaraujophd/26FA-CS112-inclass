# Makefile for recursion.cpp
#   make          -> build ./recursion
#   make test     -> build and run it
#   make debug    -> build and open it in lldb
#   make sanitize -> build with AddressSanitizer, run once, then clean up
#                    (reports runaway recursion as a stack-overflow)
#   make clean    -> remove build products
#
# Handy lldb commands for watching the recursion:
#   b factorial   set a breakpoint on a function   (use your function's name)
#   run           start the program
#   bt            show the call stack (one frame per recursive call)
#   frame select 2   look at another call; "fr v" prints its variables
#   c / n / s / finish   continue / next / step in / run until this call returns

CXX      := g++
# -g keeps debug info. -O0 turns off optimization so every recursive call
# gets its own stack frame (optimized builds can turn calls into loops).
CXXFLAGS := -std=c++17 -Wall -Wextra -g -O0

TARGET := recursion

all: $(TARGET)

$(TARGET): recursion.cpp $(wildcard *.h *.hpp)
	$(CXX) $(CXXFLAGS) -o $@ $<

test: $(TARGET)
	./$(TARGET)

debug: $(TARGET)
	lldb ./$(TARGET)

# Rebuild from scratch with AddressSanitizer and run. The "-" lets make carry
# on after a crash, so the sanitized program is always cleaned up afterwards.
sanitize: clean
	$(MAKE) CXXFLAGS="$(CXXFLAGS) -fsanitize=address" $(TARGET)
	-./$(TARGET)
	$(MAKE) clean

clean:
	rm -f $(TARGET)
	rm -rf $(TARGET).dSYM

.PHONY: all test debug sanitize clean
