#ifndef BOARD_H
#define BOARD_H

#include <stdlib.h>
#include <stdbool.h>

typedef enum { CELL_WATER, CELL_SHIP, CELL_HIT, CELL_MISS } CellState;

typedef struct {
    CellState state;
    int ship_id;  // -1 se não houver navio
} Cell;

typedef struct {
    int rows, cols;
    Cell *cells;  // Alocado dinamicamente com malloc
} Board;

// Funções para manipular o tabuleiro
Board* board_init(int rows, int cols);
void board_free(Board *board);
bool board_place_ship(Board *board, int row, int col, int length, bool horizontal, int ship_id);
Cell* board_get_cell(Board *board, int row, int col);
bool board_is_valid_pos(Board *board, int row, int col);
void board_reset_shots(Board *board);

#endif