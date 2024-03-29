.PHONY := clean
CXXFLAGS := -march=native -Os -fdata-sections -ffunction-sections -fno-exceptions -fno-rtti -std=c++2a -Wall -Wextra -pedantic
CXX := g++

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
    CXX := clang++
    CXXFLAGS += -Wno-missing-noreturn -Wno-padded -Wno-c++98-compat -Weverything -flto
    LDFLAGS := -Wl,-dead_strip -flto
else ifeq ($(UNAME_S),Linux)
    LDFLAGS := -Wl,-gc-sections
else ifeq ($(OS),Windows_NT)
    LDFLAGS :=
else
    LDFLAGS :=
endif


OBJECTS := main.o board.o token.o displayer.o player.o game.o human_player.o ai_player.o

all: main

main: $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^

clean:
	@rm -f main $(OBJECTS) > /dev/null 2>&1

# g++ -MM *.cpp

