# Pre-compiler and Compiler flags
CXX := g++
CXX_FLAGS := -Wall -Wextra -std=c++17
PRE_FLAGS := -O2
LDLIBS := 
# Project directory structure
SRC := src
OBJ := obj
BIN := bin
LIB := lib
MKDIR = mkdir -p

# Build directories and output
TARGET := program.exe
BUILD := build
EXT_LIB :=
LDLIBS :=

SRCS := $(shell find C:\Users\gabri\Desktop\Github\AtariEmulatorCPP\src -name "*.cpp")
OBJs := $(subst $(SRC), $(OBJ), $(SRCs:.cpp=.o))

all: $(BIN)

$(BIN): $(OBJs)
	$(CXX) $(CXX_FLAGS) $(PRE_FLAGS) $(OBJs) -o $@ $(LDLIBS)

$(OBJs): $(SRCs)
	$(CXX) $(CXX_FLAGS) $(PRE_FLAGS) -c $(subst $(OBJ), $(SRC), $(@:.o=.cpp)) -o $@
