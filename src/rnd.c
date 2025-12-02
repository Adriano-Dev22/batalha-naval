#include "rnd.h"

// Semente random
void rnd_seed() {
    srand(time(NULL));
}

// Gera int random
int rnd_int(int min, int max) {
    return min + rand() % (max - min + 1);
}