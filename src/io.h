#ifndef IO_H
#define IO_H

#include "board.h"
#include "game.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// Funções de entrada/saída
void io_print_menu();
int io_get_option();
void io_get_nickname(char *nickname);
int io_get_board_size();
bool io_get_placement_mode();
void io_print_turn(Player *player);
char* io_get_shot_coord(int *row, int *col, int board_size);
void io_print_result(bool hit, bool sunk, char *ship_name);
void io_print_winner(Game *game);
void io_print_board(Board *board, bool show_ships, bool is_shots);
void io_print_legend(bool is_shots);

#endif