#include <stdio.h>

#include "combat.h"
#include "player.h"

int combat_encounter(playerstate *player, Enemy *enemy){
    int action;
    while(enemy->hp>0 && player->hp>0){
        printf("\nEnemy: %s | HP: %d\nYour HP: %d\n", enemy->name, enemy->hp, player->hp);
        printf("What will you do?\n1. Attack\n2. Use Potion\n3. Run\n> ");
        scanf("%d",action);

        if(action==1){
            enemy->hp -= player->attack;
            printf("\nYou dealt %d damage!\n", player->attack);
            if(enemy->hp<=0){
            printf("%s is defeated!\n",enemy->name);

            player->gold+=5;
            gain_xp(player,10);
            return 1;
            }
            player->hp -= enemy->attack;
            printf("%s attack you for %d damage!\n",enemy->name,enemy->attack);
        }else if(action==2){
            use_potion(player);
            if(enemy->hp>0){
                player->hp -= enemy->attack;
                printf("%s attacks you for %d damage!\n", enemy->name, enemy->attack);
            }
        }else if(action==3){
            printf("You run away!\n");
            return 0;
        }
    } 
    return 1;
}




