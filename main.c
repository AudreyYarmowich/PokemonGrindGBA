#include <stdio.h>
#include "myLib.h"
#include "main.h"

int main() {
	REG_DISPCTR = MODE3 | BG2_ENABLE;
	player = 0;
	int screen = 0;
	while(1){
		if (screen == 0) {
			screen = homescreen();
			player = 0;
			u.posX = 112;
			u.posY = 69;
			u.compass = 0;
			u.image = &sf;
			pokeballs = 0x0;
		}
		if (screen == 1) {
			screen = selectscreen();
		}
		if (screen == 2) { 
			screen = mapscreen(); 
		}
		if (screen == 3) { 
			screen = gamescreen(); 
		}
		if (screen == 4) { 
			screen = gameoverscreen(); 
		}
	}
}

