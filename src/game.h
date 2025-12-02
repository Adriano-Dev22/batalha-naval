#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "fleet.h"
#include "rnd.h"
#include <stdbool.h>

typedef struct {
    Board *board;   // Tabuleiro de navios
    Board *shots;   // Tabuleiro de tiros dados
    Fleet *fleet;
    char nickname[32];
    int shots_fired;
    int hits;
} Player;

typedef struct {
    Player p1, p2;
    int current_player;  // 1 ou 2
    bool game_over;
    int board_size;
} Game;

// Funções do jogo
Game* game_init(int board_size);
void game_free(Game *game);
void game_place_fleet(Player *player, bool automatic);
bool game_shoot(Game *game, int row, int col);
Player* game_get_current_player(Game *game);
Player* game_get_opponent(Game *game);
void game_switch_turn(Game *game);

#endif