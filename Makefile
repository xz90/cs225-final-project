# Executable Name
EXENAME = finalproj

# Object Types
# Need to add file.o
OBJS = readFromFile.o main.o Airport.o Route.o Graph.o BFS.o PageRank.o Dijkstra.o

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

# Need to add file.cpp
readFromFile.o: main.cpp readFromFile.cpp
	$(CXX) $(CXXFLAGS) main.cpp readFromFile.cpp

Airport.o: Airport.cpp
	$(CXX) $(CXXFLAGS) Airport.cpp

Route.o: Route.cpp
	$(CXX) $(CXXFLAGS) Route.cpp

Graph.o: Graph.cpp
	$(CXX) $(CXXFLAGS) Graph.cpp

BFS.o: BFS.cpp
	$(CXX) $(CXXFLAGS) BFS.cpp

PageRank.o: PageRank.cpp
	$(CXX) $(CXXFLAGS) PageRank.cpp

Dijkstra.o: Dijkstra.cpp
	$(CXX) $(CXXFLAGS) Dijkstra.cpp

test: output_msg catch/catchmain.cpp tests/tests.cpp readFromFile.cpp Airport.cpp Route.cpp Graph.cpp PageRank.cpp Dijkstra.cpp
	$(LD) catch/catchmain.cpp tests/tests.cpp readFromFile.cpp Airport.cpp Route.cpp Graph.cpp PageRank.cpp Dijkstra.cpp $(LDFLAGS) -o test

clean:
	-rm -f *.o $(EXENAME) test
