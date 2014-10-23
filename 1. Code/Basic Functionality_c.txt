/*
 * Engineer: John Paul Terragnoli
 * Date Started: 21 - OCT - 14
 * Date Ended: 	21 - OCT - 14
 * Purpose: To draw either a while or black 8 by 8 square on a
 * Nokia LCD screen and leave a trail of the color with the
 * directional buttons
 *
 */

#include <msp430g2553.h>

extern void init();
extern void initNokia();
extern void clearDisplay();
//add an int to the end.  This ensures that the value 0x00 or 0xFF can be passed into the .asm file.
extern void drawBlock(unsigned char row, unsigned char col, signed int color);

#define		TRUE			1
#define		FALSE			0
#define		UP_BUTTON		(P2IN & BIT5)
#define		DOWN_BUTTON		(P2IN & BIT4)
#define		AUX_BUTTON		(P2IN & BIT3)
#define		LEFT_BUTTON		(P2IN & BIT2)
#define		RIGHT_BUTTON	(P2IN & BIT1)


void main() {

	unsigned char	x, y, button_press;

	//to pass in the color as a direct parameter.
	signed int	color;

	// === Initialize system ================================================
	IFG1=0; /* clear interrupt flag1 */
	WDTCTL=WDTPW+WDTHOLD; /* stop WD */
	button_press = FALSE;


	init();
	initNokia();
	clearDisplay();
	x=4;		y=4;

	//initializes the code
	color = 0xFF;

	//sets the color to be black initialy :)  to omoimasu
	drawBlock(y,x,color);

	while(1) {

		//if the AUX button is hit, then it will alternate it between
		//0x00 and 0xFF using XOR.
		if(AUX_BUTTON==0){
			while(AUX_BUTTON == 0);
			color ^= 0xFF;
			button_press = TRUE;
		}else if (UP_BUTTON == 0) {
				while(UP_BUTTON == 0);
				if (y>=1) y=y-1;
				button_press = TRUE;
		} else if (DOWN_BUTTON == 0) {
				while(DOWN_BUTTON == 0);
				if (y<=6) y=y+1;
				button_press = TRUE;
		} else if (LEFT_BUTTON == 0) {
				while(LEFT_BUTTON == 0);
				if (x>=1) x=x-1;
				button_press = TRUE;
		} else if (RIGHT_BUTTON == 0) {
				while(RIGHT_BUTTON == 0);
				if (x<=10) x=x+1;
				button_press = TRUE;
		}

		if (button_press) {
				button_press = FALSE;
				//clearDisplay();
				drawBlock(y,x,color);
		}
	}
}
