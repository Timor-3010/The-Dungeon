#ifndef LEVEL_H
#define LEVEL_H
#include "type.h"



int handle_action(playerstate *player, Level *level, int depth);
void move_player(playerstate *player, Level *level, int dx, int dy, int depth);
void game_over(playerstate *player, int win);



#endif