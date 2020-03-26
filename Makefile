.PHONY: clean

CC = gcc
CFLAGS = -Wall -g -std=c11
OBJ_DIR = obj
TARGETS = $(OBJ_DIR)/board.o $(OBJ_DIR)/player.o $(OBJ_DIR)/driver.o

default: ConnectFour.exe

ConnectFour.exe: $(TARGETS)
	$(CC) $(CFLAGS) -o ConnectFour.exe $(TARGETS)

$(OBJ_DIR)/board.o: $(OBJ_DIR) board.c board.h
	$(CC) $(CFLAGS) -c board.c
	mv board.o $(OBJ_DIR)

$(OBJ_DIR)/player.o: $(OBJ_DIR) player.c player.h
	$(CC) $(CFLAGS) -c player.c
	mv player.o $(OBJ_DIR)

$(OBJ_DIR)/driver.o: $(OBJ_DIR) driver.c board.h player.h
	$(CC) $(CFLAGS) -c driver.c
	mv driver.o $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	rm ConnectFour.exe
	rm -rf obj/*
