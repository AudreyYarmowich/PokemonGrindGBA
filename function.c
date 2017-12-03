#include <stdio.h>
#include "myLib.h"
#include "images.h"
#define OFFSET(row,col,rowlen) ((row)*(rowlen)+(col))
unsigned short *videoBuffer = (unsigned short *)0x6000000;

extern int rand();

void delay(int n){
	volatile int size = 0;
	for (int i = 0; i < n*6000; i++) {
		size++;
	}
}

void setPixel(int row, int col, unsigned short color) {
	
	videoBuffer[OFFSET(row,col,240)] = color;
}

void wipeScreen(unsigned short color){
	int randy = rand() % 4;
	if (randy == 0) {
		for (int c = 240; c > 0; c--){
			for(int r = 0; r < 160; r++){
				setPixel(r,c, color);
			}
		}
	} else if (randy == 1) {
		for (int c = 0; c < 240; c++){
			for(int r = 0; r < 160; r++){
				setPixel(r,c, color);
			}
		}
	} else if (randy == 2) {
		for (int r = 160; r > 0; r--){
			for(int c = 0; c < 240; c++){
				setPixel(r,c, color);
			}
		}
	} else {
		for (int r = 0; r < 160; r++){
			for(int c = 0; c < 240; c++){
				setPixel(r,c, color);
			}
		}
	}

	delay(3);
}

void drawRect(int row, int col, int height, int width, unsigned short color){
	for (int r = row; r < height+row; r++){
		REG_DMA3SAD = (u32)&color;
		REG_DMA3DAD = (u32)&videoBuffer[OFFSET(r,col,240)];
		REG_DMA3CNT = (width)|DMA_ON|DMA_SOURCE_FIXED;
	}
}

void paintScreen(unsigned short color){
	REG_DMA3SAD = (u32)&color;
	REG_DMA3DAD = (u32)videoBuffer;
	REG_DMA3CNT = (160*240)|DMA_ON|DMA_SOURCE_FIXED;
}

void paintPicture(unsigned short *picture){
	REG_DMA3SAD = (u32)picture;
	REG_DMA3DAD = (u32)videoBuffer;
	REG_DMA3CNT = (160*240)|DMA_ON;
}

void paintSprite(int row, int col, int width, int height, unsigned short *picture){
	for (int r = 0; r < height; r++){
		REG_DMA3SAD = (u32)&picture[r*width];
		REG_DMA3DAD = (u32)&videoBuffer[OFFSET(r+row,col,240)];
		REG_DMA3CNT = (width)|DMA_ON;
	}
}

void drawBall(int row, int col, int width, int height, unsigned short *picture){
	for (int r = 0; r < height; r++){
		for (int c = 0; c < width; c++){
			unsigned short pixel = picture[OFFSET(r,c,width)];
			if (pixel != 0x715f) {setPixel(r+row,c+col, pixel);}
		}
	}
}


void drawPlayer(int row, int col, int width, int height, unsigned short *picture){
	for (int r = -6; r < height+6; r++){
		for (int c = -6; c < width+6; c++){
			if (r < 0 || c < 0 || r >= height|| c >= width){
				setPixel(r+row,c+col, map[OFFSET(r+row,c+col,240)]);
			} else {
				unsigned short pixel = picture[OFFSET(r,c,width)];
				if (pixel != 0x715f) {setPixel(r+row,c+col, pixel);}
				else {setPixel(r+row,c+col, map[OFFSET(r+row,c+col,240)]);}
			}
		}
	}
}

void coverTracks(int row, int col, int width, int height, unsigned short *picture) {
	for (int r = 0; r < height+2; r++){
		for (int c = 0; c < width+2; c++){
			setPixel(r+row,c+col, picture[OFFSET(r+row,c+col,240)]);
		}
	}
}

void paintBackground(const unsigned short *picture){
	for (int r = 0; r < 110; r++) {
		REG_DMA3SAD = (u32)&picture[r*240];
		REG_DMA3DAD = (u32)&videoBuffer[OFFSET(r,0,240)];
		REG_DMA3CNT = (240)|DMA_ON;
	}
}

void drawHollowRectangle(int row, int col, int width, int height, unsigned short color)
{
	for(int c = 0; c < width; c++){
		setPixel(row,c+col, color);
	}
	for(int r = 0; r < height; r++){
		setPixel(r+row,col, color);
	}
	for(int r = 0; r < height; r++){
		setPixel(r+row,col+width-1, color);
	}
	for(int c = 0; c < width; c++){
		setPixel(row+height-1,c+col, color);
	}
}


void drawChar(int row, int col, char ch, unsigned short color){
	extern const unsigned char fontdata_6x8[12288];
	for (int r = 0; r < 8; r++){
		for (int c = 0; c < 6; c++) {
			if (fontdata_6x8[OFFSET(r, c, 6) + ch*48] == 1){
				setPixel(r+row, c+col, color);
			}
		}
	}
}

void drawString(int row, int col, char *st, unsigned short color){
	int count = 0;
	char ch = st[count];
	while(ch != 0){
		drawChar(row, col + (count * 8), ch, color);
		count++;
		ch = st[count];
	}
}

void waitForVblank() {
	while(*SCANLINECOUNTER > 160);
	while(*SCANLINECOUNTER < 160);
}
