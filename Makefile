.PHONY: clean

CC = gcc
CFLAGS = -Wall -g -std=c11
OBJ_DIR = obj
BIN_DIR = bin

$(OBJ_DIR)/board.o: obj board.c board.h
	$(CC) $(CFLAGS) -c board.c
	mv board.o $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(BIN_DIR):
	mkdir $(BIN_DIR)

clean:
	rm -rf bin/*
	rm -rf obj/*
