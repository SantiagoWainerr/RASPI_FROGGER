#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "finalAnimation/final.h"
#include "driv/disdrv.h"
#include "driv/joydrv.h"
#include "inicialization/inicialization.h"
#include "driv/formas.h"
#include "menus/menu.h"
#include "menus/pause.h"
#include "menus/top.h"
#include "mundo/entities.h"
#include "mundo/config.h"
#include "mundo/renderWorld.h"
#include "audio/soundTrack.h"

independent_object_t frog = {
    .values.position = 5,
    .y_position = 0
};
// map_t objetitos = {
    independent_object_t * arreglooo[1] = {&frog};

map_t mapa;
uint32_t hola = 0;

int32_t a;


int main (void){
    a = fillMap(&mapa, hola);
    int time = 64;
    inicialization();
    int n = menu(), i;
    usleep(750000);
    bestPlayers_t jugadores = {{"VIC","SAN","LOR","MARC","AGU","PAP","SOS","MAT","NO","JOR"},{"2021","100","89","76","67","43","25","10","7","3"}};
    while(n != 0){
        switch(n){
            case START:
                music();
                levelSound();
                i = pause();
                if(i == CONTINUE){
                    disp_clear();
                    onceDead("123");
                    n = 0;
                }else if(i == RESTART){
                    time = 64;
                    contador = 0;
                    for(int i = 0; (time - 1) > 0; i++){
                        time--;
                        renderWorld(&mapa,arreglooo,1,time);
                        usleep(500000);
                    }
                }else{
                    disp_clear();
                    onceDead("999");
                    usleep(750000);
                    disp_clear();
                    usleep(750000);
                    n = menu();
                }
                break;
            case TOP:
                topTen(jugadores);
                usleep(750000);
                n = menu();
                break;
            case END:
                disp_clear();
                n = 0;
        }
    }
    
    disp_update();
}