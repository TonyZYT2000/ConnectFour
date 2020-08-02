.PHONY: all
.PHONY: tester
.PHONY: board
.PHONY: player
.PHONY: driver
.PHONY: clean

CC = gcc
CFLAGS = -Wall -g -std=c11
OBJ_DIR = obj
OBJECTS = $(OBJ_DIR)/board.o $(OBJ_DIR)/player.o $(OBJ_DIR)/driver.o

all: ConnectFour.exe tester.exe

tester: tester.exe

board: $(OBJ_DIR)/board.o

player: $(OBJ_DIR)/player.o

driver: $(OBJ_DIR)/driver.o

ConnectFour.exe: $(OBJECTS)
	$(CC) $(CFLAGS) -o ConnectFour.exe $(OBJECTS)

tester.exe: $(OBJ_DIR)/board.o $(OBJ_DIR)/player.o $(OBJ_DIR)/test.o
	$(CC) $(CFLAGS) -o tester.exe $(OBJ_DIR)/board.o $(OBJ_DIR)/player.o \
		$(OBJ_DIR)/test.o

$(OBJ_DIR)/test.o: test.c board.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c test.c
	mv test.o $(OBJ_DIR)

$(OBJ_DIR)/board.o: board.c board.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c board.c
	mv board.o $(OBJ_DIR)

$(OBJ_DIR)/player.o: player.c player.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c player.c
	mv player.o $(OBJ_DIR)

$(OBJ_DIR)/driver.o: driver.c board.h player.h | $(OBJ_DIR) 
	$(CC) $(CFLAGS) -c driver.c
	mv driver.o $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f ConnectFour.exe
	rm -f tester.exe
	rm -rf obj/*
