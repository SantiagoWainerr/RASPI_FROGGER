#include "../driv/disdrv.h"
#include "../driv/formas.h"

#include "renderWorld.h"

#define OFFSET(v) (11 - v)
#define OFFSET_y(v) (15 - v)
#define COORDENADA(x,y) ((dcoord_t) {x, y})

#define DIVISOR 4

int contador = 0;
int flag_parpadeo = 1;

void renderWorld (map_t * map, independent_object_t * frog[], int size,int tiempo){
    disp_clear();
    if (tiempo % DIVISOR == 0 && contador < 15){
        contador++;
    }
    verticalLine(OFFSET_y(contador), (dcoord_t){ 0, contador});
    verticalLine(OFFSET_y(contador), COORDENADA(15, contador));
    
    int aux;
    for(int row = 0; row < 15; row++){
        if(((map->lanes)->objects)->doesExist){
            aux = map->lanes[row].kind->hitbox_width;
        }
        switch ((map->lanes[row]).background){
            case water:
                horizontalLine(12,COORDENADA(2, OFFSET_y(row)));
                break;
            default: // no importa que sea pasto o calle
                break;
        }
    }
   for(int i = 0; i < size; i++){
        if(flag_parpadeo){
            disp_write((dcoord_t) {OFFSET(frog[i]->values.position), frog[i]->y_position}, D_ON);
            
        }
        flag_parpadeo = !flag_parpadeo;
    } 
   
    

    disp_update();
}