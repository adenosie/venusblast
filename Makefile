CC = g++

INC_DIR := include
SRC_DIR := src
BLD_DIR := build

TARGET = $(BLD_DIR)/build

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(BLD_DIR)/%.o, $(SRC_FILES))

CPPFLAGS = -std=c++17 -Wall -I$(INC_DIR)
LDFLAGS  = -pthread `pkg-config --libs sfml-system sfml-window sfml-graphics sfml-audio`

all : $(TARGET)

$(TARGET) : $(OBJ_FILES)
	$(CC) -o $@ $^ $(LDFLAGS)

$(BLD_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

clean:
	rm $(BLD_DIR)/*
