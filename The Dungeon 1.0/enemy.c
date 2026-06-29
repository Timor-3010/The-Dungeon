#include <stdio.h>

#include "enemy.h"
void placeEnemies(Level *level, int currentLevel) {

    /* Each level has a known floor tile for the enemy.
       These positions match the fixed maps in loadLevel. */

    if (currentLevel == 1) {
        level->enemy.x = 10;
        level->enemy.y = 4;
        level->enemy.symbol = 'G';
        strcpy(level->enemy.name, "Goblin");

    } else if (currentLevel == 2) {
        level->enemy.x = 15;
        level->enemy.y = 3;
        level->enemy.symbol = 'O';
        strcpy(level->enemy.name, "Orc");

    } else if (currentLevel == 3) {
        level->enemy.x = 10;
        level->enemy.y = 6;
        level->enemy.symbol = 'S';
        strcpy(level->enemy.name, "Skeleton");

    } else if (currentLevel == 4) {
        level->enemy.x = 5;
        level->enemy.y = 5;
        level->enemy.symbol = 'T';
        strcpy(level->enemy.name, "Troll");

    } else {
        level->enemy.x = 10;
        level->enemy.y = 4;
        level->enemy.symbol = 'D';
        strcpy(level->enemy.name, "Dragon");
    }

    /* Enemy gets stronger each level */
    level->enemy.hp     = 5 + currentLevel * 2;
    level->enemy.attack = 2 + currentLevel;

    /* Stamp the enemy symbol onto the map */
    level->map[level->enemy.y][level->enemy.x] = level->enemy.symbol;
}
int any_enenmy_alive(Level *level){
    return level->enemy.hp>0;
}