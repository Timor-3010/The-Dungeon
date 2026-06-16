#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>

#define HEIGHT 10
#define WIDTH 10
#define MAX_LEVEL 5
#define MAX_HP 20

typedef struct{
    int x,y;
    int hp,max_hp;
    int damge;
    int bonus_damage;
    int level;
    int potions;
    char name[30];

}player_state;
typedef struct{
    int x,y;
    int hp;
    int damage;
    char name[30];
}Enemy;
typedef struct{
    char map[HEIGHT][WIDTH];
    Enemy enemy;
    int exit_x,exit_y;
}Dungeon_level;

void moveplayer(int dx, int dy);
void printmap(Dungeon_level *level,player_state player);
char map[HEIGHT][WIDTH] = {
    {'#','#','#','#','#','#','#','#','#','#'},
    {'#','@','.','.','.','.','.','.','E','#'},
    {'#','.','#','#','.','#','#','.','.','#'},
    {'#','.','.','.','.','.','#','.','.','#'},
    {'#','.','#','.','#','.','#','.','.','#'},
    {'#','.','#','.','#','.','.','.','.','#'},
    {'#','.','#','.','#','#','#','#','.','#'},
    {'#','.','.','.','.','.','.','#','.','#'},
    {'#','.','.','.','.','.','.','.','.','#'},
    {'#','#','#','#','#','#','#','#','#','#'}
};
int player_x=1;
int player_y=1;


int main(){
    char choice;
    printf("The last dungeon\n");
    while(1){
        system("clear");
        drawmap();
        printf("\nMove Player with WSAD: \n");
        scanf(" %c",&choice);
        if(choice=='w'){
            moveplayer(-1,0);
        }else if(choice=='s'){
            moveplayer(1,0);
        }else if(choice=='a'){
            moveplayer(0,-1);
        }else if(choice=='d'){
            moveplayer(0,1);
        }
    }


return 0;
}
void drawmap(){
    for(int i=0; i<HEIGHT; i++){
        for(int j=0; j<WIDTH; j++){
            printf("%c ",map[i][j]);
        }
        printf("\n");
    }
}
void moveplayer(int dx, int dy){
    int newX=player_x+dx;
    int newY=player_y+dy;
    if(map[newX][newY]=='#'){
        return;
    }
    if(map[newX][newY]=='E'){
        printf("You win");
        exit(0);
    }
    map[player_x][player_y]='.';
    player_x=newX;
    player_y=newY;
    map[player_x][player_y]='@';
}