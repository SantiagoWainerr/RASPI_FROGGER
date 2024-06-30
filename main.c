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

independent_object_t frog = {
    .values.position = 5,
    .y_position = 0
};
// map_t objetitos = {
    independent_object_t * arreglooo[1] = {&frog};
// };
// lane_t lane1 = { 0,0,grass,&((object_kind_t){.hitbox_width = 2}),0,
//                     {(object_t){.position = 0, .doesExist = 1},(object_t){.position = 3, .doesExist = 0},
//                     (object_t){.position = 6, .doesExist = 0},(object_t){.position = 9, .doesExist = 11},
//                     (object_t){.position = 12, .doesExist = 1}, 0}
// };
// lane_t lane2 = { 0,0,grass,&((object_kind_t){.hitbox_width = 2}),0,
//                     {(object_t){.position = 0, .doesExist = 1},(object_t){.position = 3, .doesExist = 0},
//                     (object_t){.position = 6, .doesExist = 0},(object_t){.position = 9, .doesExist = 11},
//                     (object_t){.position = 12, .doesExist = 1}, 0}
// };
// lane_t lane3 = { 0,0,grass,&((object_kind_t){.hitbox_width = 2}),0,
//                     {(object_t){.position = 0, .doesExist = 1},(object_t){.position = 3, .doesExist = 0},
//                     (object_t){.position = 6, .doesExist = 0},(object_t){.position = 9, .doesExist = 11},
//                     (object_t){.position = 12, .doesExist = 1}, 0}
// };
// lane_t lane4 = { 0,0,grass,&((object_kind_t){.hitbox_width = 2}),0,
//                     {(object_t){.position = 0, .doesExist = 1},(object_t){.position = 3, .doesExist = 0},
//                     (object_t){.position = 6, .doesExist = 0},(object_t){.position = 9, .doesExist = 11},
//                     (object_t){.position = 12, .doesExist = 1}, 0}
// };
// lane_t lane5 = { 0,0,grass,&((object_kind_t){.hitbox_width = 2}),0,
//                     {(object_t){.position = 0, .doesExist = 1},(object_t){.position = 3, .doesExist = 0},
//                     (object_t){.position = 6, .doesExist = 0},(object_t){.position = 9, .doesExist = 11},
//                     (object_t){.position = 12, .doesExist = 1}, 0}
// };
// lane_t lane6 = { 0,0,grass,&((object_kind_t){.hitbox_width = 2}),0,
//                     {(object_t){.position = 0, .doesExist = 1},(object_t){.position = 3, .doesExist = 0},
//                     (object_t){.position = 6, .doesExist = 0},(object_t){.position = 9, .doesExist = 11},
//                     (object_t){.position = 12, .doesExist = 1}, 0}
// };
// lane_t lane7 = { 0,0,grass,&((object_kind_t){.hitbox_width = 2}),0,
//                     {(object_t){.position = 0, .doesExist = 1},(object_t){.position = 3, .doesExist = 0},
//                     (object_t){.position = 6, .doesExist = 0},(object_t){.position = 9, .doesExist = 11},
//                     (object_t){.position = 12, .doesExist = 1}, 0}
// };
// lane_t lane8 = { 0,0,grass,&((object_kind_t){.hitbox_width = 2}),0,
//                     {(object_t){.position = 0, .doesExist = 1},(object_t){.position = 3, .doesExist = 0},
//                     (object_t){.position = 6, .doesExist = 0},(object_t){.position = 9, .doesExist = 11},
//                     (object_t){.position = 12, .doesExist = 1}, 0}
// };
// lane_t lane9 = { 0,0,grass,&((object_kind_t){.hitbox_width = 2}),0,
//                     {(object_t){.position = 0, .doesExist = 1},(object_t){.position = 3, .doesExist = 0},
//                     (object_t){.position = 6, .doesExist = 0},(object_t){.position = 9, .doesExist = 11},
//                     (object_t){.position = 12, .doesExist = 1}, 0}
// };
// lane_t lane10 = { 0,0,grass,&((object_kind_t){.hitbox_width = 2}),0,
//                     {(object_t){.position = 0, .doesExist = 1},(object_t){.position = 3, .doesExist = 0},
//                     (object_t){.position = 6, .doesExist = 0},(object_t){.position = 9, .doesExist = 11},
//                     (object_t){.position = 12, .doesExist = 1}, 0}
// };
// lane_t lane11 = { 0,0,grass,&((object_kind_t){.hitbox_width = 2}),0,
//                     {(object_t){.position = 0, .doesExist = 1},(object_t){.position = 3, .doesExist = 0},
//                     (object_t){.position = 6, .doesExist = 0},(object_t){.position = 9, .doesExist = 11},
//                     (object_t){.position = 12, .doesExist = 1}, 0}
// };
// lane_t lane12 = { 0,0,grass,&((object_kind_t){.hitbox_width = 2}),0,
//                     {(object_t){.position = 0, .doesExist = 1},(object_t){.position = 3, .doesExist = 0},
//                     (object_t){.position = 6, .doesExist = 0},(object_t){.position = 9, .doesExist = 11},
//                     (object_t){.position = 12, .doesExist = 1}, 0}
// };
// lane_t lane13 = { 0,0,grass,&((object_kind_t){.hitbox_width = 2}),0,
//                     {(object_t){.position = 0, .doesExist = 1},(object_t){.position = 3, .doesExist = 0},
//                     (object_t){.position = 6, .doesExist = 0},(object_t){.position = 9, .doesExist = 11},
//                     (object_t){.position = 12, .doesExist = 1}, 0}
// };
// lane_t lane14 = { 0,0,grass,&((object_kind_t){.hitbox_width = 2}),0,
//                     {(object_t){.position = 0, .doesExist = 1},(object_t){.position = 3, .doesExist = 0},
//                     (object_t){.position = 6, .doesExist = 0},(object_t){.position = 9, .doesExist = 11},
//                     (object_t){.position = 12, .doesExist = 1}, 0}
// };
// lane_t lane15 = { 0,0,grass,&((object_kind_t){.hitbox_width = 2}),0,
//                     {(object_t){.position = 0, .doesExist = 1},(object_t){.position = 3, .doesExist = 0},
//                     (object_t){.position = 6, .doesExist = 0},(object_t){.position = 9, .doesExist = 11},
//                     (object_t){.position = 12, .doesExist = 1}, 0}
// };
// lane_t lane16 = { 0,0,grass,&((object_kind_t){.hitbox_width = 2}),0,
//                     {(object_t){.position = 0, .doesExist = 1},(object_t){.position = 3, .doesExist = 0},
//                     (object_t){.position = 6, .doesExist = 0},(object_t){.position = 9, .doesExist = 11},
//                     (object_t){.position = 12, .doesExist = 1}, 0}
// };

// map_t lineas = {{lane1, lane2, (lane_t)lane3, (lane_t)lane4}};

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