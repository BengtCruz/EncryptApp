# Compiler
CC = gcc

# Compiler flags
CFLAGS = -g -Wall -Wextra -std=c99 -lm

# Source files
SRCS = main.c

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
	rm -f $(OBJS) $(TARGET)


