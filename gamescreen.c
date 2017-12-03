#include <stdio.h>
#include "myLib.h"
#include "main.h"

int drawTurnStart();
int drawAttackMenu();
int drawMenu();
void attack1Turn();
void attack2Turn();
void attack3Turn();
void attack4Turn();
void replaceE();
void paintCorners();

int enemy;

POKEMON ePokemon = {0};

int gamescreen() {
	paintScreen(WHITE);

	replaceE();
	drawSetUp();
	int death = 0;
	int attack = 0;
	
	while(death == 0) {
		attack = drawTurnStart();
		if(attack == 0) {return 0;}
		drawRect(114,6,40,228,WHITE);
		if (attack == 1) {
			attack1Turn();
		} else if (attack == 2) {
			attack2Turn();
		} else if (attack == 3) {
			attack3Turn();
		} else {attack4Turn();}

		if (ePokemon.health <= 0) {
			score++;
			wipeScreen(BLACK);
			return 2;
		} else{
			drawRect(114,6,40,228,WHITE);
			paintCorners();
			drawString(130,33,ePokemon.name,BLACK);
			drawString(130,88," used ", BLACK);
			int choose = rand()%4;
			if (choose == 0 && ePokemon.attack1_dmg+ePokemon.attack_mod > 0) {
				drawString(130,138, ePokemon.attack1,BLACK);	
				pPokemon.health -= ePokemon.attack1_dmg + ePokemon.attack_mod;
			} else if (choose == 1 && ePokemon.attack2_dmg+ePokemon.attack_mod>0) {
				drawString(130,138, ePokemon.attack2,BLACK);
				pPokemon.health -= ePokemon.attack2_dmg + ePokemon.attack_mod;
			} else if (choose == 2 && ePokemon.attack3_dmg+ePokemon.attack_mod>0) {
				drawString(130,138, ePokemon.attack3,BLACK);
				pPokemon.health -= ePokemon.attack3_dmg + ePokemon.attack_mod;
			} else if (ePokemon.attack4_dmg+ePokemon.attack_mod>0){
				drawString(130,138, ePokemon.attack4,BLACK);
				pPokemon.health -= ePokemon.attack4_dmg + ePokemon.attack_mod;
			}
			while (KEY_DOWN_NOW(BUTTON_A));
			while (!(KEY_DOWN_NOW(BUTTON_A))&&!KEY_DOWN_NOW(BUTTON_SELECT));
		}			
		if (pPokemon.health <= 0) {death = 1;}
	}
	wipeScreen(WHITE);
	return 4;
}

void attack1Turn() {
	drawRect(114,6,40,228,WHITE);
	paintCorners();
	drawString(130,10,pPokemon.name,BLACK);
	drawString(130,88," used ", BLACK);
	drawString(130,138, pPokemon.attack1,BLACK);
	if (pPokemon.attack1_dmg == 0) { ePokemon.attack_mod--;
	} else {ePokemon.health -= pPokemon.attack1_dmg+pPokemon.attack_mod;}
	while (KEY_DOWN_NOW(BUTTON_A));
	while (!(KEY_DOWN_NOW(BUTTON_A))&&!KEY_DOWN_NOW(BUTTON_SELECT));
}

void attack2Turn() {
	drawRect(114,6,40,228,WHITE);
	paintCorners();
	drawString(130,10,pPokemon.name,BLACK);
	drawString(130,88," used ", BLACK);
	drawString(130,138, pPokemon.attack3,BLACK);
	if (pPokemon.attack3_dmg == 0) { ePokemon.attack_mod--;
	} else {ePokemon.health -= pPokemon.attack3_dmg+pPokemon.attack_mod;}
	while (KEY_DOWN_NOW(BUTTON_A));
	while (!(KEY_DOWN_NOW(BUTTON_A))&&!KEY_DOWN_NOW(BUTTON_SELECT));
}

void attack3Turn() {
	drawRect(114,6,40,228,WHITE);
	paintCorners();
	drawString(130,10,pPokemon.name,BLACK);
	drawString(130,88," used ", BLACK);
	drawString(130,138, pPokemon.attack2,BLACK);
	if (pPokemon.attack2_dmg == 0) { ePokemon.attack_mod--;
	} else {ePokemon.health -= pPokemon.attack2_dmg+pPokemon.attack_mod;}
	while (KEY_DOWN_NOW(BUTTON_A));
	while (!(KEY_DOWN_NOW(BUTTON_A))&&!KEY_DOWN_NOW(BUTTON_SELECT));
}

void attack4Turn() {
	drawRect(114,6,40,228,WHITE);
	paintCorners();
	drawString(130,10,pPokemon.name,BLACK);
	drawString(130,88," used ", BLACK);
	drawString(130,138, pPokemon.attack4,BLACK);
	if (pPokemon.attack4_dmg == 0) { ePokemon.attack_mod--;
	} else {ePokemon.health -= pPokemon.attack4_dmg+pPokemon.attack_mod;}
	while (KEY_DOWN_NOW(BUTTON_A));
	while (!(KEY_DOWN_NOW(BUTTON_A))&&!KEY_DOWN_NOW(BUTTON_SELECT));
	
}

void replaceE() {
	pPokemon.level++;
	enemy = rand() % 1000;
	ePokemon.health = 10;
	ePokemon.attack_mod = 2;
	if (enemy == 0) {ePokemon = mew2;}
	else if (enemy%3 == 0) {ePokemon = rattata;}
	else if (enemy%3 == 1) {ePokemon = pidgey;}
	else {ePokemon = zubat;} 
}

void drawStatBoxes() {
	waitForVblank();
	drawRect(5,5,39,80,WHITE);
	drawHollowRectangle(4, 4,82,40, BLACK);
	drawString(22,22,"  /10",BLACK);
	drawChar(22,62,3,BLACK);
	drawString(32,16,"Level: 4",BLACK);
	drawRect(67,155, 40,82,WHITE);
	drawHollowRectangle(67, 155, 82,40, BLACK);
	drawString(72,157,pPokemon.name,BLACK);
	drawString(85,173,"  /30",BLACK);
	drawChar(85,216,3,BLACK);
	drawString(95,167,"Level: ",BLACK);
	drawString(9,20,ePokemon.name,BLACK);
	paintSprite(1,150,ePokemon.width,ePokemon.height,ePokemon.image);
	paintSprite(45,35,pPokemon.width,pPokemon.height,pPokemon.image);
	char ehealthy[2];
	ehealthy[1] = ePokemon.health%10 + 48;
	ehealthy[0] = ePokemon.health/10 + 48;
	ehealthy[2] =0;
	char healthy[2];
	healthy[1] = pPokemon.health%10 + 48;
	healthy[0] = pPokemon.health/10 + 48;
	healthy[2] = 0;
	char levely[2];
	levely[1] = pPokemon.level%10 + 48;
	levely[0] = pPokemon.level/10 + 48;
	levely[2] = 0;

	drawString(22,22,ehealthy,BLACK);
	drawString(85,173,healthy,BLACK);
	drawString(95,215,levely,BLACK);
}

void drawSetUp() {
	waitForVblank();
	paintBackground(bg1);
	drawStatBoxes();

	drawHollowRectangle(110,2,236,48,BLACK);
	drawHollowRectangle(112,4,232,44,BLACK);

	paintCorners();
}

void paintCorners() {
	drawBall(108,1,PKBALLM_WIDTH,PKBALLM_HEIGHT,pkballm);
	drawBall(108,229,PKBALLM_WIDTH,PKBALLM_HEIGHT,pkballm);
	drawBall(149,1,PKBALLM_WIDTH,PKBALLM_HEIGHT,pkballm);
	drawBall(149,229,PKBALLM_WIDTH,PKBALLM_HEIGHT,pkballm);
}

int drawTurnStart(){
	drawStatBoxes();
	int action = 0;
	int attack = 0;
	while(attack == 0) {	
		drawRect(114,6,40,228,WHITE);
		waitForVblank();
		action = drawMenu();
		if (action == 0) {return 0;}
		waitForVblank();
		drawRect(114,6,40,228,WHITE);
		paintCorners();
		if (action == 1) {
			attack = drawAttackMenu();
			if (attack == 0) {return 0;}		
		} else if (action == 2) {
			drawString(130,10,"You only have one pokemon",BLACK);
		} else if (action == 3) {
			drawString(130,10,"You have no items",BLACK);
		} else if (action == 4) {
			drawString(130,10,"There is no running",BLACK);
		}
		if(KEY_DOWN_NOW(BUTTON_SELECT)){
			return 0;
		}	
		while(!KEY_DOWN_NOW(BUTTON_A)&&!KEY_DOWN_NOW(BUTTON_B)&&
			!KEY_DOWN_NOW(BUTTON_SELECT));
		while(KEY_DOWN_NOW(BUTTON_A)||KEY_DOWN_NOW(BUTTON_B));
	}
	return attack;
}
int drawAttackMenu() {
	drawRect(114,6,40,228,WHITE);
	drawString(120,35,pPokemon.attack1,BLACK);
	drawString(140,35,pPokemon.attack2,BLACK);
	drawString(120,125,pPokemon.attack3,BLACK);
	drawString(140,125,pPokemon.attack4,BLACK);
	paintCorners();
	int row0 = 118;
	int col0 = 30;
	int row1 = 138;
	int col1 = 120;
	int height0 = 80;
	int height1 = 105;
	int height2 = 75;
	int height3 = 55;

	int row = row0;
	int col = col0;
	int height = height0;
	int width = 12;
	int action = 0;
	int button = 0;
	int prevButton = 0;
	waitForVblank();
	drawHollowRectangle(row,col,height,width,BLACK);
	while(action == 0){
		if (prevButton != button) {
			waitForVblank();
			drawHollowRectangle(row,col,height,width,WHITE);
			if(button == 0) {col = col0; row = row0; height = height0;}
			if(button == 1) {col = col1; row = row0; height = height1;}
			if(button == 2) {col = col0; row = row1; height = height2;}
			if(button == 3) {col = col1; row = row1; height = height3;}
			drawHollowRectangle(row,col,height,width,BLACK); 
			prevButton = button;
		}
		
		if(KEY_DOWN_NOW(BUTTON_LEFT)||KEY_DOWN_NOW(BUTTON_RIGHT)){
			if(button == 0) {button++;}
			else if(button == 1) {button--;}
			else if(button == 2) {button++;}
			else if(button == 3) {button--;}
		}
		else if(KEY_DOWN_NOW(BUTTON_UP)||KEY_DOWN_NOW(BUTTON_DOWN)){
			if(button == 0) {button = 2;}
			else if(button == 1) {button = 3;}
			else if(button == 2) {button = 0;}
			else if(button == 3) {button = 1;}
		}
		if(KEY_DOWN_NOW(BUTTON_A)){
			action = button+1;
		}
		if(KEY_DOWN_NOW(BUTTON_SELECT)){
			return 0;
		}	
		while(KEY_DOWN_NOW(BUTTON_RIGHT)||KEY_DOWN_NOW(BUTTON_LEFT)||
			KEY_DOWN_NOW(BUTTON_UP)||KEY_DOWN_NOW(BUTTON_DOWN));
		waitForVblank();
	}
	return action;
}
int drawMenu() {
	drawHollowRectangle(114,110,124,40,BLACK);
	paintCorners();
	drawString(120,124,"FIGHT",BLACK);
	drawString(140,124,"ITEM",BLACK);
	drawString(120,190,"PKMN",BLACK);
	drawString(140,190,"RUN",BLACK);
	int row0 = 118;
	int col0 = 122;
	int row1 = 138;
	int col1 = 188;
	int height0 = 44;
	int height1 = 36;
	int height2 = 28;

	int row = row0;
	int col = col0;
	int height = height0;
	int width = 12;
	int action = 0;
	int button = 0;
	int prevButton = 0;
	drawHollowRectangle(row,col,height,width,BLACK);
	while(action == 0){
		if (prevButton != button) {
			drawHollowRectangle(row,col,height,width,WHITE);
			if(button == 0) {col = col0; row = row0; height = height0;}
			if(button == 1) {col = col1; row = row0; height = height1;}
			if(button == 2) {col = col0; row = row1; height = height1;}
			if(button == 3) {col = col1; row = row1; height = height2;}
			drawHollowRectangle(row,col,height,width,BLACK); 
			prevButton = button;
		}
		
		if(KEY_DOWN_NOW(BUTTON_LEFT)||KEY_DOWN_NOW(BUTTON_RIGHT)){
			if(button == 0) {button++;}
			else if(button == 1) {button--;}
			else if(button == 2) {button++;}
			else if(button == 3) {button--;}
		}
		else if(KEY_DOWN_NOW(BUTTON_UP)||KEY_DOWN_NOW(BUTTON_DOWN)){
			if(button == 0) {button = 2;}
			else if(button == 1) {button = 3;}
			else if(button == 2) {button = 0;}
			else if(button == 3) {button = 1;}
		}
		if(KEY_DOWN_NOW(BUTTON_A)){
			action = button+1;
		}
		if(KEY_DOWN_NOW(BUTTON_SELECT)){
			return 0;
		}	
		while(KEY_DOWN_NOW(BUTTON_RIGHT)||KEY_DOWN_NOW(BUTTON_LEFT)||
			KEY_DOWN_NOW(BUTTON_UP)||KEY_DOWN_NOW(BUTTON_DOWN)||
			KEY_DOWN_NOW(BUTTON_A));
		waitForVblank();
	}
	return action;
}
