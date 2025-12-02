CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRC_DIR = src
SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/board.c $(SRC_DIR)/fleet.c $(SRC_DIR)/game.c $(SRC_DIR)/io.c $(SRC_DIR)/rnd.c
EXEC = batalha_naval

all: $(EXEC)

$(EXEC): $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(EXEC)