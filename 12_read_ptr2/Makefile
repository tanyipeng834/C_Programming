# Makefile for compiling test.c into a program called "test"

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Source file
SOURCE = test.c

# Output executable
OUTPUT = test

all: $(OUTPUT)

$(OUTPUT): $(SOURCE)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SOURCE)

clean:
	rm -f $(OUTPUT)
