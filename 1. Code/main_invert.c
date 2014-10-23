/*
 * Engineer: John Paul Terragnoli
 * Date Started: 21 - OCT - 14
 * Date Ended: 	21 - OCT - 14
 * Purpose: To draw either a while or black 8 by 8 square on a
 * Nokia LCD screen and invert the block and background color on
 * demand when pressing the AUX button.  The block should bounce around the screen.
 *
 */

#include <msp430g2553.h>

extern void init();
extern void initNokia();
extern void clearDisplay();
extern void blackDisplay();
extern void drawBlock(unsigned char row, unsigned char col, signed int color);

#define		TRUE			1
#define		FALSE			0
#define		BLACK			0xFF
#define		WHITE			0X00
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
	signed int	color;
	unsigned long timeWaster,timeWaster2;

	// === Initialize system ================================================
	IFG1=0; /* clear interrupt flag1 */
	WDTCTL=WDTPW+WDTHOLD; /* stop WD */
	button_press = FALSE;

	//sets up the screen
	init();
	initNokia();
	clearDisplay();

	//initializing the location of the x and y coordinates.
	x=LENGTH;
	y=HEIGHT;

	//initializing the velocity of the block
	xVel = 1;
	yVel = 1;


	//variables used to ensure that the block moves at an appropriate rate.
	timeWaster = 0;
	timeWaster2 = 0;

	//ensures that the screen is initally non-inverted
	color = BLACK;




	//clears the screen and initializes the block
	clearDisplay();
	drawBlock(y,x,BLACK);

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


		//if the auxiliary button has been hit, then invert the block and the screen.
		if(AUX_BUTTON==0){
			for(timeWaster = 0; timeWaster<100;timeWaster++){
			}
			color ^=BLACK;
		}

		//actually draws the background of the screen as well as the block
		//in the appropriate colors.
		if(color == BLACK){
			clearDisplay();
			drawBlock(y,x,BLACK);
		}else if(color ==WHITE){
			blackDisplay();
			drawBlock(y,x,WHITE);
		}
	}
}
