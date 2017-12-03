#include "images.h"

//external functions
extern void waitForVblank();
extern void drawRect();
extern void drawString();
extern void paintPicture();
extern void paintSprite();
extern void drawChar();
extern void drawHollowRectangle();
extern void paintBackground();
extern int rand();



typedef struct{
	//Pokemon name
	unsigned char *name;

	//conditions
	int health;
	int level;

	//Attack Damage
	int attack1_dmg;
	int attack2_dmg;
	int attack3_dmg;
	int attack4_dmg;

	//Attack Stat
	int attack_mod;

	//Sprite Settings
	int height;
	int width;
	const unsigned short *image;

	//Attack names
	unsigned char *attack1;
	unsigned char *attack2;
	unsigned char *attack3;
	unsigned char *attack4;
	
} POKEMON;

//Declare Pokemon in the game
POKEMON charmander = {(unsigned char *)"Charmander",30,10,2,1,3,0,1, CHAR_BOOTY_HEIGHT,CHAR_BOOTY_WIDTH, Char_booty, (unsigned char*)"Iron Tail", (unsigned char*)"Bite", (unsigned char*)"Flamethrower", (unsigned char*)"Charm"};
POKEMON squirtle = {(unsigned char*)"Squirtle",30,10, 2,1,3,0,1, SQUIR_TUSH_HEIGHT,SQUIR_TUSH_WIDTH, Squir_tush, (unsigned char*)"Tail Slap",(unsigned char*) "Scratch",(unsigned char*) "Water Gun",(unsigned char*) "Growl"};
POKEMON bulbasaur = {(unsigned char*)"Bulbasaur",30,10, 2,1,3,0,1, BULBA_BUTT_HEIGHT,BULBA_BUTT_WIDTH, Bulba_butt, (unsigned char*)"Vine Whip",(unsigned char*) "Scratch",(unsigned char*) "Leaf Blade",(unsigned char*) "Growl"};
POKEMON zubat = {(unsigned char*)"Zubat", 10,4, 2,1,1,0,2, ZOOB_HEIGHT,ZOOB_WIDTH, Zoob,(unsigned char*) "Bite",(unsigned char*)"Leach Life",(unsigned char*) "Scratch", (unsigned char*)"Growl"};
POKEMON pidgey = {(unsigned char*)"Pidgey",10,4, 2,1,1,0,2, PIDGE_HEIGHT,PIDGE_WIDTH, Pidge, (unsigned char*)"Wing Attack",(unsigned char*)"Scratch",(unsigned char*) "Scratch",(unsigned char*) "Tail Whip"};
POKEMON rattata = {(unsigned char*)"Rattata",10,4,2,1,1,0,2, RATS_HEIGHT,RATS_WIDTH, Rats, (unsigned char*)"Bite", (unsigned char*)"Scratch",(unsigned char*) "Scratch", (unsigned char*)"Tail Whip"};
POKEMON mew2 = {(unsigned char*)"MewTwo",30,12,2,3,2,3,5, MEWTWO_HEIGHT,MEWTWO_WIDTH, mewtwo, (unsigned char*)"Rage", (unsigned char*)"Psychic",(unsigned char*) "Ice Punch", (unsigned char*)"Extrasensory"};