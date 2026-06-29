#ifndef TYPE_H
#define TYPE_H
 
#define WIDTH 20
#define HEIGHT 10
#define MAX_LEVEL 5
#define BASE_MAX_HP 20

typedef struct{
    int x,y;
    int hp,max_hp;
    int potions;
    int gold;
    int level;
    int attack;
    int xp;
    char name[50];
}playerstate;

typedef struct{
    int x,y;
    int hp;
    int attack;
    char symbol;
    char name[50];
}Enemy;

typedef struct{
    char map[HEIGHT][WIDTH];
    Enemy enemy;
    int exit_x, exit_y;
}Level;
#endif