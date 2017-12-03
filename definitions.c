#include <stdio.h>
#include "myLib.h"
#include "main.h"

//Declare Pokemon in the game
POKEMON charmander = {(char *)"Charmander",30,10,2,1,3,0,1, CHAR_BOOTY_HEIGHT,CHAR_BOOTY_WIDTH, Char_booty, (char*)"Iron Tail", (char*)"Bite", (char*)"Flamethrower", (char*)"Charm"};
POKEMON squirtle = {(char*)" Squirtle",30,10, 2,1,3,0,1, SQUIR_TUSH_HEIGHT,SQUIR_TUSH_WIDTH, Squir_tush, (char*)"Tail Slap",(char*) "Scratch",(char*) "Water Gun",(char*) "Growl"};
POKEMON bulbasaur = {(char*)"Bulbasaur",30,10, 2,1,3,0,1, BULBA_BUTT_HEIGHT,BULBA_BUTT_WIDTH, Bulba_butt, (char*)"Vine Whip",(char*) "Scratch",(char*) "Leaf Blade",(char*) "Growl"};
POKEMON zubat = {(char*)" Zubat", 10,4, 2,1,1,0,2, ZOOB_HEIGHT,ZOOB_WIDTH, Zoob,( char*) "Bite",(char*)"Leach Life",(char*) "Scratch", (char*)"Growl"};
POKEMON pidgey = {(char*)"Pidgey",10,4, 2,1,1,0,2, PIDGE_HEIGHT,PIDGE_WIDTH, Pidge, ( char*)"Wing Attack",(char*)"Scratch",(char*) "Scratch",(char*) "Tail Whip"};
POKEMON rattata = {(char*)"Rattata",10,4,2,1,1,0,2, RATS_HEIGHT,RATS_WIDTH, Rats, (char*)"Bite", (char*)"Scratch",(char*) "Scratch", (char*)"Tail Whip"};
POKEMON mew2 = {(char*)"MewTwo",30,12,2,3,2,3,5, MEWTWO_HEIGHT,MEWTWO_WIDTH, mewtwo, (char*)"Rage", (char*)"Psychic",(char*) "Ice Punch", (char*)"Extrasensory"};

SPRITE sf = {STANDINGF_HEIGHT,STANDINGF_WIDTH,standingf};
SPRITE sr = {STANDINGR_HEIGHT,STANDINGR_WIDTH,standingr};
SPRITE sl = {STANDINGL_HEIGHT,STANDINGL_WIDTH,standingl};
SPRITE sb = {STANDINGB_HEIGHT,STANDINGB_WIDTH,standingb};

SPRITE rl = {WRL_HEIGHT,WRL_WIDTH,wrl};
SPRITE rr = {WRR_HEIGHT,WRR_WIDTH,wrr};

SPRITE fr = {WFR_HEIGHT,WFR_WIDTH,wfr};
SPRITE fl = {WFL_HEIGHT,WFL_WIDTH,wfl};
SPRITE br = {WBR_HEIGHT,WBR_WIDTH,wbr};
SPRITE bl = {WBL_HEIGHT,WBL_WIDTH,wbl};
SPRITE lr = {WLR_HEIGHT,WLR_WIDTH,wlr};
SPRITE ll = {WLL_HEIGHT,WLL_WIDTH,wll};
