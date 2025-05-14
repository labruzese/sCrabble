# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude

# Directories
SRC_DIR = src
INC_DIR = include
TEST_DIR = test
BIN_DIR = bin
OBJ_DIR = $(BIN_DIR)/obj

# Files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJS = $(patsubst $(TEST_DIR)/%.c, $(OBJ_DIR)/%.o, $(TEST_SRCS))
EXEC = $(BIN_DIR)/program
TEST_EXEC = $(BIN_DIR)/test_runner

# Phony targets
.PHONY: all clean test dirs run

# Default target
all: dirs $(EXEC)

# Create necessary directories
dirs:
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(OBJ_DIR)

# Compile the main program
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Compile object files from source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Test target
test: dirs $(TEST_EXEC)
	./$(TEST_EXEC)

# Compile test program
$(TEST_EXEC): $(filter-out $(OBJ_DIR)/main.o, $(OBJS)) $(TEST_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Compile test object files
$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Run target
run: all
	./$(EXEC)

# Clean target
clean:
	rm -rf $(BIN_DIR)
