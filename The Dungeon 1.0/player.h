#ifndef PLAYER_H
#define PLAYER_H
#include "type.h"

void PlayerSetUP(playerstate *player);
void gain_xp(playerstate *player, int amount);
void use_potion(playerstate *player);
void print_state(playerstate *plaer);

#endif
