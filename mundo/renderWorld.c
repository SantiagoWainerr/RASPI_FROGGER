#include "../driv/disdrv.h"
#include "../driv/formas.h"

#include "renderWorld.h"

#define OFFSET(v) (12 - v)
#define OFFSET_y(v) (15 - v)


#define DIVISOR 4

int contador = 0;
int flag_parpadeo = 1;

void renderWorld (map_t * map, independent_object_t * frog[], int size,int tiempo){
    disp_clear();
    if (tiempo % DIVISOR == 0 && contador < 15){
        contador++;
    }
    verticalLine(16-contador, (dcoord_t){ 0, contador});
    // verticalLine(16-contador, (dcoord_t){ 1, contador});
    // verticalLine(16-contador, (dcoord_t){14, contador});
    verticalLine(16-contador, (dcoord_t){15, contador});
    
    int aux;
    for(int row = 0; row < 15; row++){
        if(((map->lanes)->objects)->doesExist){
            aux = map->lanes[row].kind->hitbox_width;
        }
        switch ((map->lanes[row]).background){
            case water:
                horizontalLine(12,(dcoord_t) {2, row});
                if(((map->lanes)->objects)->doesExist && OFFSET(((map->lanes)->objects)->position) + 3 <=12){
                    for(int i = 0; i < MAX_OBJECTS_PER_LANE; i++){
                        horizontalLineOff(aux, (dcoord_t){OFFSET(((map->lanes[row]).objects[i]).position), OFFSET_y(row)});
                    }
                }
                break;
            default: // no importa que sea pasto o calle
                for(int i = 0; i < MAX_OBJECTS_PER_LANE; i++){
                    if(((map->lanes)->objects)->doesExist && OFFSET(((map->lanes)->objects)->position) + 3 <=12){
                        horizontalLine(aux, (dcoord_t){OFFSET(((map->lanes[row]).objects[i]).position), OFFSET_y(row)});
                    }
                }
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