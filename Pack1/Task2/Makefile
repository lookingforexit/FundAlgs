CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -Iinclude
TARGET = app.out

SRCS = $(wildcard src/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, build/%.o, $(SRCS))
HEADERS = $(wildcard include/*.h)

all: build/$(TARGET)

build/$(TARGET): $(OBJS) 
	$(CC) $(OBJS) -o $@
	
build/%.o: src/%.c $(HEADERS) | build
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build/*.o build/$(TARGET)

run: 
	./build/$(TARGET)

.PHONY: all run clean