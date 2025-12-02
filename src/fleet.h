#ifndef FLEET_H
#define FLEET_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum { ORIENT_H, ORIENT_V } Orientation;

typedef struct {
    char name[20];
    int length;
    int hits;
    int placed;  // 0 ou 1
} Ship;

typedef struct {
    Ship *ships;
    int count;
} Fleet;

// Funções para frota
Fleet* fleet_init();
void fleet_free(Fleet *fleet);
bool fleet_all_sunk(Fleet *fleet);
void fleet_hit_ship(Fleet *fleet, int ship_id);
int fleet_get_ships_left(Fleet *fleet);

#endif