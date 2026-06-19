#ifndef MAP_H
#define MAP_H
#include "type.h"

void fill_floor(Level *level);
void place_walls(Level *level);
void place_stairs(Level *level, playerstate *player);
void generate_map(Level *level, int depth, playerstate *player);
void print_map(Level *level, playerstate *player);
void place_player_start(playerstate *player);



#endif