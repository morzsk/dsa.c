# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iheaders -g

# Directories
SRC_DIR = ./src
HEADERS_DIR = ./headers
BIN_DIR = ./bin

# Files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SRCS))
TARGET = $(BIN_DIR)/main

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files into object files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure the bin directory exists
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Clean up build artifacts
clean:
	rm -rf $(BIN_DIR)

# Phony targets
.PHONY: all clean

