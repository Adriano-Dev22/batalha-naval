#include "game.h"
#include "io.h"
#include "rnd.h"
#include <stdio.h>
#include <stdbool.h>

int main() {
    rnd_seed();
    int board_size = 10;  // Default
    bool auto_place = true;  // Default

    while (true) {
        io_print_menu();
        int opt = io_get_option();
        if (opt == 3) break;
        if (opt == 2) {
            board_size = io_get_board_size();
            auto_place = io_get_placement_mode();
            continue;
        }

        // Novo jogo
        Game *game = game_init(board_size);
        if (game == NULL) {
            printf("Erro de memoria!\n");
            return 1;
        }

        printf("Informe apelido do Jogador 1: ");
        io_get_nickname(game->p1.nickname);
        printf("Informe apelido do Jogador 2: ");
        io_get_nickname(game->p2.nickname);

        // Posiciona frotas
        game_place_fleet(&game->p1, auto_place);
        game_place_fleet(&game->p2, auto_place);

        // Loop de turnos
        while (!game->game_over) {
            Player *current = game_get_current_player(game);
            io_print_turn(current);
            int row, col;
            io_get_shot_coord(&row, &col, board_size);
            bool hit = game_shoot(game, row, col);
            int ship_id = board_get_cell(game_get_opponent(game)->board, row, col)->ship_id;
            bool sunk = false;
            char ship_name[20] = "";
            if (hit && ship_id >= 0) {
                Ship *ship = &game_get_opponent(game)->fleet->ships[ship_id];
                strcpy(ship_name, ship->name);
                sunk = (ship->hits == ship->length);
            }
            io_print_result(hit, sunk, ship_name);
            if (!game->game_over) game_switch_turn(game);
        }

        io_print_winner(game);
        game_free(game);
    }

    return 0;
}