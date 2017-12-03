#include <stdio.h>
#include "myLib.h"
#include "main.h"

//internal functions
void setScreen();

//messages to be displayed
char *header = "Select Your Pokemon";

typedef struct {
	int width;
	int height;
	const unsigned short *image;
	char *message;
	int mStart;
} STARTER;

STARTER selected;

STARTER starter1 = {BULBASAUR_WIDTH, BULBASAUR_HEIGHT,Bulbasaur,(char*)"Bulbasaur the Seed Pokemon",18};
STARTER starter2 = {SQUIRTLE_WIDTH, SQUIRTLE_HEIGHT,Squirtle,(char*) "Squirtle the Turtle Pokemon",13};
STARTER starter3 = {CHARMANDER_WIDTH, CHARMANDER_HEIGHT,Charmander,(char*) "Charmander the Lizard Pokemon",5};

//Prepares the dimensions of rectangles
	int messageR = 145;
	int size = 40;
	int row = 28;
	int col = 40;

int selectscreen() {
	waitForVblank();

	//selects bulbasaur by default
	selected = starter1;

	//sets up the screen
	setScreen();
	
	//prepares the selector loop
	int prev = 0;
	int select = 0;
	int done = 0;

	//loops while player has not selected a pokemon
	while(done == 0) {
		col = (select*14) + ((select + 1)*42);
		if (select != prev) {
			if (select == 0) {selected = starter1;}
			else if (select == 1) {selected = starter2;}
			else {selected = starter3;}
			waitForVblank();
			setScreen();
			prev = select;
		}
		drawHollowRectangle(row, col, size, size, BLACK);
		if(KEY_DOWN_NOW(BUTTON_LEFT)){
			if(select == 0) {select = 2;
			} else {select--;}
		}
		if(KEY_DOWN_NOW(BUTTON_RIGHT)){
			if(select == 2) {select = 0;
			} else {select++;}
		}
		if(KEY_DOWN_NOW(BUTTON_A)){
			if (select == 1) {pPokemon = squirtle;}
			else if (select == 2) {pPokemon = charmander;}
			else {pPokemon = bulbasaur;}
			done = 1;
		}
		if(KEY_DOWN_NOW(BUTTON_SELECT)){
			//moves to homescreen
			return 0;
		}
		while(KEY_DOWN_NOW(BUTTON_RIGHT)||KEY_DOWN_NOW(BUTTON_LEFT));
		waitForVblank();
		drawHollowRectangle(row, col, size, size, WHITE);
		
	}
	
	//moves to gamescreen
	return 2;
}

void setScreen(){
	//paints background
	paintPicture(selectScreen);
	//paints selected sprite
	paintSprite(80, 90, selected.width, selected.height,selected.image);
	//prints the header
	drawString(5,40,header,BLACK);
	//shows selected message
	drawString(messageR,selected.mStart,selected.message,BLACK);
}
