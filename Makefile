.PHONY: clean

CC = gcc
CFLAGS = -Wall -g -std=c11
OBJ_DIR = obj
BIN_DIR = bin
TARGETS = $(OBJ_DIR)/board.o $(OBJ_DIR)/player.o $(OBJ_DIR)/driver.o

$(BIN_DIR)/ConnectFour.exe: $(BIN_DIR) $(TARGETS)
	$(CC) $(CFLAGS) -o ConnectFour.exe $(TARGETS)
	mv ConnectFour.exe $(BIN_DIR)

$(OBJ_DIR)/board.o: obj board.c board.h
	$(CC) $(CFLAGS) -c board.c
	mv board.o $(OBJ_DIR)

$(OBJ_DIR)/player.o: obj player.c player.h
	$(CC) $(CFLAGS) -c player.c
	mv player.o $(OBJ_DIR)

$(OBJ_DIR)/driver.o: obj driver.c board.h player.h
	$(CC) $(CFLAGS) -c driver.c
	mv driver.o $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(BIN_DIR):
	mkdir $(BIN_DIR)

clean:
	rm -rf bin/*
	rm -rf obj/*
