CC = clang++
CFLAGS = -Wall -Werror -std=c++17 -Iinclude

TARGET = build/bin/sort-algo_analysis

SRCS = $(wildcard src/*.cpp)

OBJS = $(patsubst src/%.cpp, build/obj/%.o, $(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p build/bin
	$(CC) $(CFLAGS) -o $@ $^

build/obj/%.o: src/%.cpp
	@mkdir -p build/obj
	$(CC) $(CFLAGS) -c $< -o $@

run:
	./$(TARGET)

clean:
	@rm -rf build/*

.PHONY: all clean