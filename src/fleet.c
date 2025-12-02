#include "fleet.h"

// Inicializa frota mínima com malloc
Fleet* fleet_init() {
    Fleet *fleet = (Fleet*)malloc(sizeof(Fleet));
    if (fleet == NULL) return NULL;
    fleet->count = 6;  // 1+1+2+2
    fleet->ships = (Ship*)malloc(fleet->count * sizeof(Ship));
    if (fleet->ships == NULL) {
        free(fleet);
        return NULL;
    }
    strcpy(fleet->ships[0].name, "Porta-avioes");
    fleet->ships[0].length = 5;
    fleet->ships[0].hits = 0;
    fleet->ships[0].placed = 0;

    strcpy(fleet->ships[1].name, "Encouracado");
    fleet->ships[1].length = 4;
    fleet->ships[1].hits = 0;
    fleet->ships[1].placed = 0;

    strcpy(fleet->ships[2].name, "Cruzador1");
    fleet->ships[2].length = 3;
    fleet->ships[2].hits = 0;
    fleet->ships[2].placed = 0;

    strcpy(fleet->ships[3].name, "Cruzador2");
    fleet->ships[3].length = 3;
    fleet->ships[3].hits = 0;
    fleet->ships[3].placed = 0;

    strcpy(fleet->ships[4].name, "Destroyer1");
    fleet->ships[4].length = 2;
    fleet->ships[4].hits = 0;
    fleet->ships[4].placed = 0;

    strcpy(fleet->ships[5].name, "Destroyer2");
    fleet->ships[5].length = 2;
    fleet->ships[5].hits = 0;
    fleet->ships[5].placed = 0;

    return fleet;
}

// Libera frota
void fleet_free(Fleet *fleet) {
    if (fleet != NULL) {
        free(fleet->ships);
        free(fleet);
    }
}

// Verifica se todos navios afundados
bool fleet_all_sunk(Fleet *fleet) {
    for (int i = 0; i < fleet->count; i++) {
        if (fleet->ships[i].hits < fleet->ships[i].length) {
            return false;
        }
    }
    return true;
}

// Incrementa hits em navio
void fleet_hit_ship(Fleet *fleet, int ship_id) {
    if (ship_id >= 0 && ship_id < fleet->count) {
        fleet->ships[ship_id].hits++;
    }
}

// Conta navios restantes
int fleet_get_ships_left(Fleet *fleet) {
    int left = 0;
    for (int i = 0; i < fleet->count; i++) {
        if (fleet->ships[i].hits < fleet->ships[i].length) {
            left++;
        }
    }
    return left;
}