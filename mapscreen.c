#include <stdio.h>
#include "myLib.h"
#include "main.h"

void drawRemainingPokeballs();
SPRITE pkb = {PKBALLM_HEIGHT,PKBALLM_WIDTH,pkballm};

int mapscreen(){

	int inBattle = 0;
	int battleChance = 10;
	paintPicture(map);

	while(inBattle != 1){
		if (u.compass == 0) {u.image = &sf;}
		else if (u.compass == 1) {u.image = &sr;}
		else if (u.compass == 2) {u.image = &sb;}
		else {u.image = &sl;}
		waitForVblank();
		//coverTracks(u.posY,u.posX,(*u.image).width,(*u.image).height,map);
		drawPlayer(u.posY,u.posX,(*u.image).width,(*u.image).height,(*u.image).address);
		drawRemainingPokeballs();

		while(KEY_DOWN_NOW(BUTTON_DOWN)||KEY_DOWN_NOW(BUTTON_LEFT)||KEY_DOWN_NOW(BUTTON_UP)||KEY_DOWN_NOW(BUTTON_RIGHT)||KEY_DOWN_NOW(BUTTON_SELECT));
		while(!KEY_DOWN_NOW(BUTTON_DOWN)&&!KEY_DOWN_NOW(BUTTON_LEFT)&&!KEY_DOWN_NOW(BUTTON_UP)&&!KEY_DOWN_NOW(BUTTON_RIGHT)&&!KEY_DOWN_NOW(BUTTON_SELECT)&&!KEY_DOWN_NOW(BUTTON_A));
		if (KEY_DOWN_NOW(BUTTON_RIGHT)){
			u.compass = 1;
			int left = 1;
			int touchingEdge = u.posX > 196;;
			while(KEY_DOWN_NOW(BUTTON_RIGHT)&&!touchingEdge&&inBattle != 1){
				inBattle = rand() % battleChance;
				touchingEdge = u.posX > 196;
				if (!touchingEdge){
					//coverTracks(u.posY,u.posX,(*u.image).width,(*u.image).height,map);
					u.posX += 5;
					if (left == 1) {u.image = &rl;}
					else {u.image = &rr;}
				} else {
					u.image = &sr;
					//coverTracks(u.posY,u.posX,(*u.image).width,(*u.image).height,map);
				}
				drawPlayer(u.posY,u.posX,(*u.image).width,(*u.image).height,(*u.image).address);
				delay(3);
				left = -left;
			}
		}
		if (KEY_DOWN_NOW(BUTTON_UP)){
			u.compass = 2;
			int left = 1;
			int touchingEdge = u.posY < 10;
			while(KEY_DOWN_NOW(BUTTON_UP)&&!touchingEdge&&inBattle != 1){
				inBattle = rand() %battleChance;
				touchingEdge = u.posY < 10;;
				if (!touchingEdge){
					//coverTracks(u.posY,u.posX,(*u.image).width,(*u.image).height,map);
					u.posY -= 5;
					if (left == 1) {u.image = &bl;}
					else {u.image = &br;}
				} else {
					u.image = &sb;
					//coverTracks(u.posY,u.posX,(*u.image).width,(*u.image).height,map);
				}
				drawPlayer(u.posY,u.posX,(*u.image).width,(*u.image).height,(*u.image).address);
				delay(3);
				left = -left;
			}
		}
		if (KEY_DOWN_NOW(BUTTON_LEFT)){
			u.compass = 3;
			int left = 1;
			int touchingEdge = u.posX < 33;
			//int touchingEdge = u.posX < 33||((pokeballs>>2) %2 == 1 && u.posY > 114 && u.posX < 47)||(pokeballs %2 == 1 && u.posY > 22 && u.posX > 47);
			while(KEY_DOWN_NOW(BUTTON_LEFT)&&!touchingEdge&&inBattle != 1){
				inBattle = rand() %battleChance;
				touchingEdge = u.posX < 33;
				//touchingEdge = u.posX < 33||((pokeballs>>2) %2 == 1 && u.posY > 114 && u.posX < 47)||(pokeballs %2 == 1 && u.posY > 22 && u.posX > 47);
				if (!touchingEdge){
					//coverTracks(u.posY,u.posX,(*u.image).width,(*u.image).height,map);
					u.posX -= 5;
					if (left == 1) {u.image = &ll;}
					else {u.image = &lr;}
				} else {
					u.image = &sl;
					//coverTracks(u.posY,u.posX,(*u.image).width,(*u.image).height,map);
				}
				drawPlayer(u.posY,u.posX,(*u.image).width,(*u.image).height,(*u.image).address);
				delay(3);
				left = -left;
			}
		}
		if (KEY_DOWN_NOW(BUTTON_DOWN)){
			u.compass = 0;
			int left = 1;
			//int touchingEdge = (u.posY > 127);
			int touchingEdge = (u.posY > 127)||((pokeballs>>2) %2 == 1 && u.posY > 114 && u.posX < 47)||((pokeballs>>3) %2 == 1 && u.posY > 114 && u.posX > 171);
			while(KEY_DOWN_NOW(BUTTON_DOWN)&&!touchingEdge&&inBattle != 1){
				inBattle = rand() %battleChance;
				//touchingEdge = (u.posY > 127);
				touchingEdge = (u.posY > 127)||((pokeballs>>2) %2 == 1 && u.posY > 114 && u.posX < 47)||((pokeballs>>3) %2 == 1 && u.posY > 114 && u.posX > 171);
				if (!touchingEdge){
					//coverTracks(u.posY,u.posX,(*u.image).width,(*u.image).height,map);
					u.posY += 5;
					if (left == 1) {u.image = &fl;}
					else {u.image = &fr;}
				} else {
					u.image = &sf;
					//coverTracks(u.posY,u.posX,(*u.image).width,(*u.image).height,map);
				}
				drawPlayer(u.posY,u.posX,(*u.image).width,(*u.image).height,(*u.image).address);
				delay(3);
				left = -left;
			}
		}
		if(KEY_DOWN_NOW(BUTTON_SELECT)){
			//moves to homescreen
			return 0;
		}
		if(KEY_DOWN_NOW(BUTTON_A)){
			if(((pokeballs>>2) %2 == 1 && u.posY > 114 && u.posX < 47)){
				drawChar(20,50,pokeballs,RED);
				pokeballs = pokeballs && 0xB;
				drawRemainingPokeballs();
				drawChar(40,50,pokeballs,RED);
			}
			if((pokeballs>>3) %2 == 1 && u.posY > 114 && u.posX > 171){
				drawChar(20,40,pokeballs,RED);
				pokeballs = pokeballs && 0x7;
				drawRemainingPokeballs();
				drawChar(40,40,pokeballs,RED);
			}
		}
	}
	wipeScreen(BLACK);
	return 3;
}

void drawRemainingPokeballs(){
	if (pokeballs % 2 == 1){
		drawPlayer(9,33,pkb.width,pkb.height,pkb.address);
	}
	if ((pokeballs>>1) %2 == 1){
		drawPlayer(9,196,pkb.width,pkb.height,pkb.address);
	}
	if ((pokeballs>>2) %2 == 1){
		drawPlayer(140,33,pkb.width,pkb.height,pkb.address);
	}
	if ((pokeballs>>3) %2 == 1){
		drawPlayer(140,196,pkb.width,pkb.height,pkb.address);
	}
}