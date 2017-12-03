#include <stdio.h>
#include "myLib.h"
#include "main.h"

//external variables
extern int level;
extern int score;
extern int health;
/*
void called();
void note_Prep();
void note_Play();
void sos();
*/
int homescreen() {
	waitForVblank();

	//Initialize the game stats
	score = 0;

	//Display screen
	char playing = 1;
	paintPicture(homescreen_background);
	//called();
	//Wait for input
	while(playing == 1){
		if(KEY_DOWN_NOW(BUTTON_A)){
			playing = 0;
			while(KEY_DOWN_NOW(BUTTON_A));
		}
	}
	
	//Move to the player select screen
	return 1;
}
/*
#define SDMG_SQR1    0x01
#define SDMG_SQR2    0x02
#define SDMG_WAVE    0x04
#define SDMG_NOISE   0x08

#define SDMG_BUILD(_lmode, _rmode, _lvol, _rvol)    \
    ( ((_lvol)&7) | (((_rvol)&7)<<4) | ((_lmode)<<8) | ((_rmode)<<12) )

#define SDMG_BUILD_LR(_mode, _vol) SDMG_BUILD(_mode, _mode, _vol, _vol)
#define SND_RATE(note, oct) ( 2048-(__snd_rates[note]>>(4+(oct))) )
#define REG_SNDDMGCNT (SOUNDCNT_L / SGCNT0_L ) @ 0400:0080h
#define REG_SND1CNT (SOUND1CNT_H / SG10_H) @ 0400:0062h 
#define REG_SND2CNT (SOUND2CNT_L / SG20_L) @ 0400:0068h
#define REG_SND1FREQ (SOUND1CNT_X / SG11) @ 0400:0062h 
#define REG_SND2FREQ (SOUND2CNT_H / SG21) @ 0400:006Ch

typedef enum 
{
    NOTE_C=0, NOTE_CIS, NOTE_D,   NOTE_DIS, 
    NOTE_E,   NOTE_F,   NOTE_FIS, NOTE_G, 
    NOTE_GIS, NOTE_A,   NOTE_BES, NOTE_B
} eSndNoteId;

const u32 __snd_rates[12]=
{
    8013, 7566, 7144, 6742, // C , C#, D , D#
    6362, 6005, 5666, 5346, // E , F , F#, G
    5048, 4766, 4499, 4246  // G#, A , A#, B
};
u8 txt_scrolly= 8;

const char *names[]=
{   "C ", "C#", "D ", "D#", "E ", "F ", "F#", "G ", "G#", "A ", "A#", "B "  };

// === FUNCTIONS ======================================================

// Show the octave the next note will be in
void note_prep(int octave)
{
    char str[32];
    siprintf(str, "[  %+2d]", octave);
}


// Play a note and show which one was played
void note_play(int note, int octave)
{
    // Play the actual note
    REG_SND1FREQ = SFREQ_RESET | SND_RATE(note, octave);
}


// Play a little ditty
void sos()
{
    const u8 lens[6]= { 1,1,4, 1,1,4 };
    const u8 notes[6]= { 0x02, 0x05, 0x12,  0x02, 0x05, 0x12 };
    int ii;
    for(ii=0; ii<6; ii++)
    {
        note_play(notes[ii]&15, notes[ii]>>4);
        VBlankIntrDelay(8*lens[ii]);
    }
}

int called()
{
    REG_DISPCNT= DCNT_MODE0 | DCNT_BG0;

    irq_init(NULL);
    irq_add(II_VBLANK, NULL);

    txt_init_std();
    txt_init_se(0, BG_CBB(0) | BG_SBB(31), 0, CLR_ORANGE, 0);
    pal_bg_mem[0x11]= CLR_GREEN;
    
    int octave= 0;

    // turn sound on
    REG_SNDSTAT= SSTAT_ENABLE;
    // snd1 on left/right ; both full volume
    REG_SNDDMGCNT = SDMG_BUILD_LR(SDMG_SQR1, 7);
    // DMG ratio to 100%
    REG_SNDDSCNT= SDS_DMG100;

    // no sweep
    REG_SND1SWEEP= SSW_OFF;
    // envelope: vol=12, decay, max step time (7) ; 50% duty
    REG_SND1CNT= SSQR_ENV_BUILD(12, 0, 7) | SSQR_DUTY1_2;
    REG_SND1FREQ= 0;

    sos();

    while(1)
    {
        VBlankIntrWait();
        key_poll();

        // Change octave:
        octave += bit_tribool(KEY_DOWN_NOW(-1), KI_R, KI_L);
        octave= wrap(octave, -2, 6);
        note_prep(octave);

        // Play note
        if(KEY_DOWN_NOW(KEY_DIR|KEY_A))
        {
            if(KEY_DOWN_NOW(BUTTON_UP))
                note_play(NOTE_D, octave+1);
            if(KEY_DOWN_NOW(BUTTON_LEFT))
                note_play(NOTE_B, octave);
            if(KEY_DOWN_NOW(BUTTON_RIGHT))
                note_play(NOTE_A, octave);
            if(KEY_DOWN_NOW(BUTTON_DOWN))
                note_play(NOTE_F, octave);
            if(KEY_DOWN_NOW(BUTTON_A))
                note_play(NOTE_D, octave);
        }

        // Play ditty
        if(KEY_DOWN_NOW(BUTTON_B))
            sos();      
    }
    return 0;
}

*/