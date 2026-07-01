CC = gcc

CFLAGS = -Wall -Iinclude

SRC = main.c src/dynamic_array.c src/linked_list.c src/doubly_linked_list.c src/stack.c

TARGET = main

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	del /Q main.exe 2>nul || rm -f main
	