# Created by: Bengt Svedling Cruz
# Edited by: Bengt Svedling Cruz
# Date: 2023-05-19
# Description: Makefile for the main program

# Makefile variables

# Remove command
ifeq ($(OS),Windows_NT)
	EXE_EXT = .exe
	RM = del /Q
else
	EXE_EXT =
	RM = rm -f
endif

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -g -Wall -Wextra -std=c99 -lm

# Source files
SRCS = main.c src/AesManager.c 

# Object files
OBJS = $(SRCS:.c=.o)

# Executable
TARGET = mainExe

# Build rules
all: $(TARGET)

# Build executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	$(RM) $(OBJS) $(TARGET)$(EXE_EXT)


