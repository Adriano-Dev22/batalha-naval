#include "board.h"

// Inicializa o tabuleiro com malloc
Board* board_init(int rows, int cols) {
    Board *board = (Board*)malloc(sizeof(Board));
    if (board == NULL) return NULL;
    board->rows = rows;
    board->cols = cols;
    board->cells = (Cell*)malloc(rows * cols * sizeof(Cell));
    if (board->cells == NULL) {
        free(board);
        return NULL;
    }
    for (int i = 0; i < rows * cols; i++) {
        board->cells[i].state = CELL_WATER;
        board->cells[i].ship_id = -1;
    }
    return board;
}

// Libera memória do tabuleiro
void board_free(Board *board) {
    if (board != NULL) {
        free(board->cells);
        free(board);
    }
}

// Coloca um navio no tabuleiro, validando limites e overlaps
bool board_place_ship(Board *board, int row, int col, int length, bool horizontal, int ship_id) {
    for (int i = 0; i < length; i++) {
        int r = row + (horizontal ? 0 : i);
        int c = col + (horizontal ? i : 0);
        if (!board_is_valid_pos(board, r, c) || board_get_cell(board, r, c)->state == CELL_SHIP) {
            return false;
        }
    }
    for (int i = 0; i < length; i++) {
        int r = row + (horizontal ? 0 : i);
        int c = col + (horizontal ? i : 0);
        Cell *cell = board_get_cell(board, r, c);
        cell->state = CELL_SHIP;
        cell->ship_id = ship_id;
    }
    return true;
}

// Retorna ponteiro para célula
Cell* board_get_cell(Board *board, int row, int col) {
    return &board->cells[row * board->cols + col];
}

// Verifica se posição é válida
bool board_is_valid_pos(Board *board, int row, int col) {
    return row >= 0 && row < board->rows && col >= 0 && col < board->cols;
}

// Reseta tabuleiro de tiros (para shots)
void board_reset_shots(Board *board) {
    for (int i = 0; i < board->rows * board->cols; i++) {
        board->cells[i].state = CELL_WATER;
        board->cells[i].ship_id = -1;
    }
}