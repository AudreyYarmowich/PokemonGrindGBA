#include "images.h"
#include "background.h"
#include "playersprite.h"

#define REG_DISPCTR *(unsigned short *)0x4000000
#define MODE3 3
#define BG2_ENABLE	(1<<10)

#define OFFSET(row,col,rowlen) ((row)*(rowlen)+(col))
#define KEY_DOWN_NOW(key) (~(BUTTONS) & key)

//Functions
extern void setPixel(int row, int col, unsigned short color);
extern void drawRect(int row, int col, int height, int width, unsigned short color);
extern void drawChar(int row, int col, char ch, unsigned short color);
extern void drawString(int row, int col, char *ch, unsigned short color);
extern void drawHollowRectangle(int row, int col, int width, int height, unsigned short color);
extern void delay(int n);
extern void paintPicture(const unsigned short *picture);
extern void paintScreen(unsigned short color);
extern void paintBackground(const unsigned short *picture);
extern void paintSprite(int row, int col, int width, int height, const unsigned short *picture);
extern void drawPlayer(int row, int col, int width, int height, const unsigned short *picture);
extern void wipeScreen(unsigned short color);
extern void waitForVblank();
extern void drawSetUp();
extern void drawBall(int row, int col, int width, int height, const unsigned short *picture);
extern void coverTracks(int row, int col, int width, int height, const unsigned short *picture);

extern int rand();

//Screens
extern int homescreen(); 
extern int gamescreen(); 
extern int selectscreen();
extern int gameoverscreen();
extern int mapscreen();


//Structures
typedef struct{
	//Pokemon name
	char *name;

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
	char *attack1;
	char *attack2;
	char *attack3;
	char *attack4;
	
} POKEMON;

typedef struct {
	const int height;
	const int width;
	const unsigned short *address;
} SPRITE;

typedef struct{
	//position on screen
	int posX;
	int posY;

	//direction facing
	int compass;

	//image of the character
	SPRITE *image;
} PLAYER;

//Global Variables
int score;
int player;
POKEMON pPokemon;
unsigned char pokeballs;

//constants
extern POKEMON charmander;
extern POKEMON squirtle; 
extern POKEMON bulbasaur;
extern POKEMON zubat;
extern POKEMON pidgey;// = {(char*)"Pidgey",10,4, 2,1,1,0,2, PIDGE_HEIGHT,PIDGE_WIDTH, Pidge, ( char*)"Wing Attack",(char*)"Scratch",(char*) "Scratch",(char*) "Tail Whip"};
extern POKEMON rattata;// = {(char*)"Rattata",10,4,2,1,1,0,2, RATS_HEIGHT,RATS_WIDTH, Rats, (char*)"Bite", (char*)"Scratch",(char*) "Scratch", (char*)"Tail Whip"};
extern POKEMON mew2;// = {(char*)"MewTwo",30,12,2,3,2,3,5, MEWTWO_HEIGHT,MEWTWO_WIDTH, mewtwo, (char*)"Rage", (char*)"Psychic",(char*) "Ice Punch", (char*)"Extrasensory"};

extern SPRITE sf;// = {STANDINGF_HEIGHT,STANDINGF_WIDTH,standingf};
extern SPRITE sr;// = {STANDINGR_HEIGHT,STANDINGR_WIDTH,standingr};
extern SPRITE sl;// = {STANDINGL_HEIGHT,STANDINGL_WIDTH,standingl};
extern SPRITE sb;// = {STANDINGB_HEIGHT,STANDINGB_WIDTH,standingb};
extern SPRITE rl;// = {WRL_HEIGHT,WRL_WIDTH,wrl};
extern SPRITE rr;// = {WRR_HEIGHT,WRR_WIDTH,wrr};
extern SPRITE fr;// = {WFR_HEIGHT,WFR_WIDTH,wfr};
extern SPRITE fl;// = {WFL_HEIGHT,WFL_WIDTH,wfl};
extern SPRITE br;// = {WBR_HEIGHT,WBR_WIDTH,wbr};
extern SPRITE bl;// = {WBL_HEIGHT,WBL_WIDTH,wbl};
extern SPRITE lr;// = {WLR_HEIGHT,WLR_WIDTH,wlr};
extern SPRITE ll;// = {WLL_HEIGHT,WLL_WIDTH,wll};

PLAYER u;