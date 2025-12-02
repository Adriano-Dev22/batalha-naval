#include "game.h"
#include <string.h>

// Inicializa jogo com malloc
Game* game_init(int board_size) {
    Game *game = (Game*)malloc(sizeof(Game));
    if (game == NULL) return NULL;
    game->board_size = board_size;
    game->p1.board = board_init(board_size, board_size);
    game->p1.shots = board_init(board_size, board_size);
    game->p1.fleet = fleet_init();
    strcpy(game->p1.nickname, "");
    game->p1.shots_fired = 0;
    game->p1.hits = 0;

    game->p2.board = board_init(board_size, board_size);
    game->p2.shots = board_init(board_size, board_size);
    game->p2.fleet = fleet_init();
    strcpy(game->p2.nickname, "");
    game->p2.shots_fired = 0;
    game->p2.hits = 0;

    game->current_player = 1;
    game->game_over = false;
    return game;
}

// Libera tudo na ordem inversa
void game_free(Game *game) {
    if (game != NULL) {
        fleet_free(game->p1.fleet);
        board_free(game->p1.board);
        board_free(game->p1.shots);
        fleet_free(game->p2.fleet);
        board_free(game->p2.board);
        board_free(game->p2.shots);
        free(game);
    }
}

// Posiciona frota manual ou auto
void game_place_fleet(Player *player, bool automatic) {
    for (int i = 0; i < player->fleet->count; i++) {
        Ship *ship = &player->fleet->ships[i];
        int row, col;
        bool horizontal;
        if (automatic) {
            do {
                row = rnd_int(0, player->board->rows - 1);
                col = rnd_int(0, player->board->cols - 1);
                horizontal = rnd_int(0, 1);
            } while (!board_place_ship(player->board, row, col, ship->length, horizontal, i));
        } else {
            // No io.c vamos pedir input, mas aqui só coloca
            // Assumir que input já validado no io
        }
        ship->placed = 1;
    }
}

// Realiza tiro, retorna true se acertou
bool game_shoot(Game *game, int row, int col) {
    Player *shooter = game_get_current_player(game);
    Player *target = game_get_opponent(game);
    shooter->shots_fired++;

    if (!board_is_valid_pos(target->board, row, col)) return false;

    Cell *target_cell = board_get_cell(target->board, row, col);
    Cell *shot_cell = board_get_cell(shooter->shots, row, col);

    if (shot_cell->state != CELL_WATER) return false;  // Já atirou aqui

    if (target_cell->state == CELL_SHIP) {
        target_cell->state = CELL_HIT;
        shot_cell->state = CELL_HIT;
        shooter->hits++;
        fleet_hit_ship(target->fleet, target_cell->ship_id);
        if (fleet_all_sunk(target->fleet)) {
            game->game_over = true;
        }
        return true;
    } else {
        target_cell->state = CELL_MISS;
        shot_cell->state = CELL_MISS;
        return false;
    }
}

// Retorna jogador atual
Player* game_get_current_player(Game *game) {
    return (game->current_player == 1) ? &game->p1 : &game->p2;
}

// Retorna oponente
Player* game_get_opponent(Game *game) {
    return (game->current_player == 1) ? &game->p2 : &game->p1;
}

// Troca turno
void game_switch_turn(Game *game) {
    game->current_player = (game->current_player == 1) ? 2 : 1;
}