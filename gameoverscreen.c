#include <stdio.h>
#include "myLib.h"
#include "main.h"

int gameoverscreen() {
	//paints screen black
	paintPicture(over_background);
	
	//prints score
	drawChar(135,155,score+48,BLACK);

	//loops until confirmation
	while(!KEY_DOWN_NOW(BUTTON_A)&&!KEY_DOWN_NOW(BUTTON_B)&&
		!KEY_DOWN_NOW(BUTTON_SELECT)&&!KEY_DOWN_NOW(BUTTON_START));
	while(KEY_DOWN_NOW(BUTTON_A)||KEY_DOWN_NOW(BUTTON_B)||
		KEY_DOWN_NOW(BUTTON_SELECT)||KEY_DOWN_NOW(BUTTON_START));

	//returns to the homescreen
	return 0;
}
