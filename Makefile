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
CFLAGS = -g -Wall -Wextra -std=c99
CFLAGS += -I./lib
CFLAGS += `pkg-config --cflags gtk+-3.0`

# Linker flags
LDFLAGS = `pkg-config --libs gtk+-3.0`
LDFLAGS += -lssl -lcrypto

# Source files
SRCS = main.c src/AesManager.c src/GtkGui.c
TSRCS = test/main.c test/unity.c src/AesManager.c

# Object files
OBJS = $(SRCS:.c=.o)
TOBJS = $(TSRCS:.c=.o)

# Executable
TARGET = mainExe
TEST_TARGET = testExe

# Build rules
all: $(TARGET)

# Build executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build and run test executable
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Build test executable
$(TEST_TARGET): $(TOBJS)
	$(CC) $(CFLAGS) $(TOBJS) -o $(TEST_TARGET) $(LDFLAGS)

# Clean
# Removes all object files and then executables
# Note: Cant do both object and executables at the same time
# in Windows, so we do it in two steps. In cmd.exe, the
# del command expects individual files as arguments.
# Usage: make clean
clean:
	$(RM) $(OBJS) $(TOBJS)
	$(RM) $(TARGET)$(EXE_EXT) $(TEST_TARGET)$(EXE_EXT)

.PHONY: all test clean

# Dependencies for test target
$(TOBJS): test/main.c test/unity.c src/AesManager.c
