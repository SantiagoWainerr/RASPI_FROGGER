#include <SDL2/SDL.h>
#include "audio.h"
#include "soundTrack.h"

#define STEP "src/step.wav"
#define LIFE "src/looseLife.wav"
#define TIME "src/runningOutOfTime.wav"
#define LEVEL "src/nextLevel.wav"

void levelSound (void){
    playSound(LEVEL, SDL_MIX_MAXVOLUME);
}