/*
 * Engineer: John Paul Terragnoli
 * Date Started: 21 - OCT - 14
 * Date Ended: 	21 - OCT - 14
 * Purpose: To draw either a black 8 by 8 square on a
 * Nokia LCD screen have it bounce around the screen.
 *
 */

#include <msp430g2553.h>

extern void init();
extern void initNokia();
extern void clearDisplay();
extern void drawBlock(unsigned char row, unsigned char col);

#define		TRUE			1
#define		FALSE			0
#define		UP_BUTTON		(P2IN & BIT5)
#define		DOWN_BUTTON		(P2IN & BIT4)
#define		AUX_BUTTON		(P2IN & BIT3)
#define		LEFT_BUTTON		(P2IN & BIT2)
#define		RIGHT_BUTTON	(P2IN & BIT1)
#define 	LENGTH			11
#define 	HEIGHT			7


void main() {

	unsigned char	x, y, button_press;
	signed char		xVel, yVel;
	unsigned long timeWaster,timeWaster2;

	// === Initialize system ================================================
	IFG1=0; /* clear interrupt flag1 */
	WDTCTL=WDTPW+WDTHOLD; /* stop WD */
	button_press = FALSE;


	init();
	initNokia();
	clearDisplay();
	x=LENGTH;
	y=HEIGHT;

	xVel = 1;
	yVel = 1;

	timeWaster = 0;
	timeWaster2 = 0;


	//sets the color to be black initialy :)  to omoimasu
	drawBlock(y,x);

	while(1) {


		//delays the code to make the ball move slower.
		for(timeWaster = 0; timeWaster<500; timeWaster++){
			for(timeWaster2 = 0; timeWaster2<500; timeWaster2++){

			}
		}


		//check if in bounds in the y direction:
		if(y>=HEIGHT||y<=0){
			yVel *= -1;
		}


		//check if in bounds in x direction
		if(x>=LENGTH||x<=0){
			xVel *= -1;
		}




		//moves it!!!
		x +=xVel;
		y +=yVel;


		//resets screen with new location of block
		clearDisplay();
		drawBlock(y,x);
	}
}
