#include "io.h"

// Imprime menu inicial
void io_print_menu() {
    printf("=== BATALHA NAVAL ===\n");
    printf("1) Novo jogo\n");
    printf("2) Configuracoes\n");
    printf("3) Sair\n");
    printf("> ");
}

// Pega opção válida
int io_get_option() {
    int opt;
    scanf("%d", &opt);
    while (opt < 1 || opt > 3) {
        printf("Opcao invalida! > ");
        scanf("%d", &opt);
    }
    return opt;
}

// Pega apelido
void io_get_nickname(char *nickname) {
    scanf("%31s", nickname);  // Limita para evitar overflow
}

// Pega tamanho tabuleiro
int io_get_board_size() {
    int size;
    printf("Tamanho do tabuleiro (6-26):\n> ");
    scanf("%d", &size);
    while (size < 6 || size > 26) {
        printf("Tamanho invalido! > ");
        scanf("%d", &size);
    }
    return size;
}

// Pega modo posicionamento
bool io_get_placement_mode() {
    char mode;
    printf("Posicionamento (M)anual ou (A)utomatico?\n> ");
    scanf(" %c", &mode);
    mode = toupper(mode);
    while (mode != 'M' && mode != 'A') {
        printf("Invalido! > ");
        scanf(" %c", &mode);
        mode = toupper(mode);
    }
    return (mode == 'A');
}

// Imprime turno
void io_print_turn(Player *player) {
    printf("-- Turno de %s --\n", player->nickname);
}

// Pega coordenada tiro, converte B5 -> row=4, col=1 (0-index)
char* io_get_shot_coord(int *row, int *col, int board_size) {
    static char coord[3];
    printf("Digite coordenada do tiro (ex.: E5):\n> ");
    scanf("%2s", coord);
    coord[0] = toupper(coord[0]);
    int c = coord[0] - 'A';
    int r = atoi(&coord[1]) - 1;
    while (!isalpha(coord[0]) || c < 0 || c >= board_size || r < 0 || r >= board_size) {
        printf("Coordenada invalida! > ");
        scanf("%2s", coord);
        coord[0] = toupper(coord[0]);
        c = coord[0] - 'A';
        r = atoi(&coord[1]) - 1;
    }
    *row = r;
    *col = c;
    return coord;
}

// Imprime resultado tiro
void io_print_result(bool hit, bool sunk, char *ship_name) {
    if (hit) {
        if (sunk) {
            printf("Resultado: AFUNDOU %s!\n", ship_name);
        } else {
            printf("Resultado: ACERTOU no %s!\n", ship_name);
        }
    } else {
        printf("Resultado: AGUA.\n");
    }
}

// Imprime vencedor e stats
void io_print_winner(Game *game) {
    Player *winner = (fleet_all_sunk(game->p2.fleet)) ? &game->p1 : &game->p2;
    printf("*** FIM DE JOGO ***\n");
    printf("Vencedor: %s\n", winner->nickname);
    printf("Tiros: %d | Acertos: %d | Precisao: %.1f%%\n", winner->shots_fired, winner->hits, (float)winner->hits / winner->shots_fired * 100);

    printf("--- Estado final dos tabuleiros ---\n");
    printf("Tabuleiro de %s (seus navios):\n", game->p1.nickname);
    io_print_board(game->p1.board, true, false);
    io_print_legend(false);

    printf("Tabuleiro de %s (visao real):\n", game->p2.nickname);
    io_print_board(game->p2.board, true, false);
    io_print_legend(false);

    printf("Mapa de tiros de %s em %s:\n", game->p1.nickname, game->p2.nickname);
    io_print_board(game->p1.shots, false, true);
    io_print_legend(true);
}

// Imprime tabuleiro
void io_print_board(Board *board, bool show_ships, bool is_shots) {
    // Cabeçalho colunas
    printf("  ");
    for (int c = 0; c < board->cols; c++) {
        printf("%c ", 'A' + c);
    }
    printf("\n");

    for (int r = 0; r < board->rows; r++) {
        printf("%-2d", r + 1);
        for (int c = 0; c < board->cols; c++) {
            Cell *cell = board_get_cell(board, r, c);
            char sym;
            if (is_shots) {
                sym = (cell->state == CELL_HIT) ? 'X' : (cell->state == CELL_MISS ? '.' : ' ');
            } else {
                if (cell->state == CELL_HIT) sym = 'X';
                else if (cell->state == CELL_MISS) sym = '~';
                else if (cell->state == CELL_SHIP && show_ships) sym = 'S';
                else sym = '~';
            }
            printf("%c ", sym);
        }
        printf("\n");
    }
}

// Imprime legenda
void io_print_legend(bool is_shots) {
    if (is_shots) {
        printf("Legenda: X = tiro acertado | . = tiro errado\n");
    } else {
        printf("Legenda: S = Navio | X = Acertado | ~ = Agua\n");
    }
}