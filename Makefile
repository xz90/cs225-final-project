# Executable Name
EXENAME = finalproj

# Object Types
OBJS = readFromFile.o main.o

# Compilation Flags
CXX = clang++
CXXFLAGS = $(CS225) -std=c++14 -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++14 -stdlib=libc++ -lc++abi -lm

# Custom Clang Enforcement
include make/customClangEnforcement.mk

# Define Makefile Rules
.PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME): output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

readFromFile.o: main.cpp readFromFile.cpp
	$(CXX) $(CXXFLAGS) main.cpp readFromFile.cpp

test: output_msg catch/catchmain.cpp tests/tests.cpp readFromFile.cpp
	$(LD) catch/catchmain.cpp tests/tests.cpp readFromFile.cpp $(LDFLAGS) -o test

clean:
	-rm -f *.o $(EXENAME) test
