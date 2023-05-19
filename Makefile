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
CFLAGS = -g -Wall -Wextra -std=c99

# OpenSSL paths
# OPENSSL_DIR = C:\OpenSSL
# OPENSSL_LIB_DIR = $(OPENSSL_DIR)\lib
# OPENSSL_INC_DIR = $(OPENSSL_DIR)\include

# Compiler flags
# CFLAGS += -I$(OPENSSL_INC_DIR)
# LDFLAGS += -L$(OPENSSL_LIB_DIR) -lssl -lcrypto

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
# Removes all object files and then executables
# Note: Cant do both object and executbales at the same time
# in Windows, so we do it in two steps. In cmd.exe, the
# del command expects individual files as arguments.
# Usage: make clean
clean:
	$(RM) $(OBJS)
	$(RM) $(TARGET)$(EXE_EXT)


