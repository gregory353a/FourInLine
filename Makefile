.PHONY := clean
CXXFLAGS := -march=native -Os -fdata-sections -ffunction-sections -fno-exceptions -fno-rtti -std=c++17 -Wall -Wextra -pedantic
CXX := g++

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
    CXX := clang++
    CXXFLAGS += -Wno-missing-noreturn -Wno-padded -Wno-c++98-compat -Weverything
    LDFLAGS := -Wl,-dead_strip
else ifeq ($(UNAME_S),Linux)
    LDFLAGS := -Wl,-gc-sections
else ifeq ($(OS),Windows_NT)
    LDFLAGS := -Wl,-gc-sections
else
    LDFLAGS :=
endif


OBJECTS := main.o board.o token.o displayer.o player.o game.o

all: main

main: $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^

clean:
	@rm -f main $(OBJECTS) > /dev/null 2>&1

# g++ -MM *.cpp

board.o: board.cpp board.hpp token.hpp displayer.hpp
displayer.o: displayer.cpp displayer.hpp token.hpp board.hpp
game.o: game.cpp game.hpp token.hpp player.hpp displayer.hpp board.hpp
main.o: main.cpp game.hpp
player.o: player.cpp player.hpp token.hpp board.hpp
token.o: token.cpp token.hpp
