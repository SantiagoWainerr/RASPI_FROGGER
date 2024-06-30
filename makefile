ejecutable: inicialization/inicialization.o main.o driv/formas.o driv/disdrv.o driv/joydrv.o menus/menu.o menus/pause.o menus/top.o finalAnimation/final.o mundo/renderWorld.o mundo/entities.o audio/soundTrack.o audio/libAudioSDL2.o -lSDL2
	gcc inicialization/inicialization.o main.o driv/formas.o driv/joydrv.o driv/disdrv.o menus/menu.o menus/pause.o menus/top.o finalAnimation/final.o mundo/renderWorld.o mundo/entities.o audio/soundTrack.o audio/libAudioSDL2.o -lSDL2 -o ejecutable -Wall

main.o: main.c inicialization/inicialization.h driv/formas.h menus/menu.h menus/pause.h menus/top.h finalAnimation/final.h mundo/renderWorld.h mundo/entities.h  audio/soundTrack.h
	gcc -Wall -c main.c

inicialization.o: inicialization/inicialization.c  inicialization/inicialization.h driv/formas.h driv/disdrv.h driv/joydrv.h  audio/audio.h
	gcc -Wall -c inicialization/inicialization.c

formas.o: driv/formas.c driv/formas.h driv/disdrv.h
	gcc -Wall -c driv/formas.c

menu.o: menus/menu.c menus/menu.h driv/disdrv.h driv/joydrv.h driv/formas.h
	gcc -Wall -c menus/menu.c

pause.o: menus/pause.c menus/pause.h driv/disdrv.h driv/joydrv.h driv/formas.h
	gcc -Wall -c menus/pause.c

top.o: menus/top.c menus/top.h driv/disdrv.h driv/joydrv.h driv/formas.h
	gcc -Wall -c menus/top.c

final.o: finalAnimation/final.c finalAnimation/final.h driv/disdrv.h driv/joydrv.h driv/formas.h
	gcc -Wall -c finalAnimation/final.c

# HASTA ACA PUSHEE

soundTrack.o: audio/soundTrack.h audio/audio.h audio/soundTrack.c 
	gcc -Wall -c soundTrack.c

input.o: input/input.h input/input.c driv/joydrv.h
	gcc -Wall -c finalAnimation

renderWorld.o: driv/disdrv.h driv/formas.h mundo/renderWorld.h mundo/renderWorld.c
	gcc -Wall -c mundo/renderWorld.c
 
entities.o: mundo/entities.h -D RPI mundo/entities.c mundo/config.h
	gcc -Wall -c mundo/entities.c

clean:
	rm *.o

