# Compiler
CC = g++
# Compiler flags
CFLAGS = -Wall -Wextra -std=c++11

# Source files
SRCS = vertice.cpp aresta.cpp grafo.cpp main.cpp
# Object files
OBJS = $(SRCS:.cpp=.o)
# Header files
HDRS = vertice.hpp aresta.hpp grafo.hpp

# Target executable
TARGET = main

.PHONY: all clean

# Default target
all: $(TARGET)

# Rule to link object files into executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Rule to compile source files into object files
%.o: %.cpp $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	rm -f $(OBJS) $(TARGET)