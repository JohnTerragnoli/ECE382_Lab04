/*
 * Engineer: John Paul Terragnoli
 * Date Started: 21 - OCT - 14
 * Date Ended: 	21 - OCT - 14
 * Purpose: To draw either a  black 8 by 8 square on a
 * Nokia LCD screen and a paddle.  Plays one player
 * pong on the screen.  When the ball misses the paddle
 * the game ends.
 *
 */

#include <msp430g2553.h>

extern void init();
extern void initNokia();
extern void clearDisplay();
extern void drawBlock(unsigned char row, unsigned char col);
extern void drawPaddle(unsigned char row, unsigned char col);

#define		TRUE			1
#define		FALSE			0
#define		UP_BUTTON		(P2IN & BIT5)
#define		DOWN_BUTTON		(P2IN & BIT4)
#define		AUX_BUTTON		(P2IN & BIT3)
#define		LEFT_BUTTON		(P2IN & BIT2)
#define		RIGHT_BUTTON	(P2IN & BIT1)
#define 	LENGTH			11
#define 	HEIGHT			7
#define 	PADDLECOL		94


void main() {

	unsigned char	x, y, button_press;
	signed char		xVel, yVel;
	unsigned long timeWaster,timeWaster2;
	unsigned char	paddleRow;
	unsigned char	playGame;

	// === Initialize system ================================================
	IFG1=0; /* clear interrupt flag1 */
	WDTCTL=WDTPW+WDTHOLD; /* stop WD */
	button_press = FALSE;

	//sets up the screen
	init();
	initNokia();
	clearDisplay();

	//initializes the position of the block
	x=1;
	y=1;

	//initializes the velocity of the block
	xVel = 1;
	yVel = 1;


	//wastes time to make the block move slower.
	timeWaster = 0;
	timeWaster2 = 0;

	//intializes the location of the paddle.
	paddleRow = 4;


	//sets the color to be black initialy :)  to omoimasu
	drawBlock(y,x);

	//first we need to draw the paddle.
	drawPaddle(paddleRow,PADDLECOL);

	playGame = 1;

	while(playGame) {
		//delays the code to make the ball move slower.
		for(timeWaster = 0; timeWaster<350; timeWaster++){
			for(timeWaster2 = 0; timeWaster2<350; timeWaster2++){
				//want to give the user a chance to hit the button before the block is moved.
				//therefore, check this every time you run through the for loop!!!!
				//might have to alter how long the loop delays for after this.

			}

		}


		//check if the up or down buttons have been hit!!
		if (UP_BUTTON == 0) {
			for(timeWaster = 0; timeWaster<60;timeWaster++){
			}
				if (paddleRow>=1) paddleRow = paddleRow-1;
				button_press = TRUE;
		} else if (DOWN_BUTTON == 0) {
			for(timeWaster = 0; timeWaster<60;timeWaster++){
			}
				if (paddleRow<=6) paddleRow=paddleRow+1;
				button_press = TRUE;
		}



		//check if too far left
		if(y<=0||y>=HEIGHT){
			yVel *= -1;
		}


		//check if in bounds in x direction
		if(x<=0){
			xVel *= -1;
		}

		//did it hit the paddle?
		if(x>=LENGTH&&y==paddleRow){
			xVel *= -1;
		}else if (x==LENGTH){
			//if it hit the right wall instead.
			//make the game end!!!
			playGame = 0;
		}




		//moves it!!!
		x +=xVel;
		y +=yVel;


		//resets screen with new location of block
		clearDisplay();
		drawBlock(y,x);
		drawPaddle(paddleRow,PADDLECOL);
	}

	while(1){
		clearDisplay();
	}

}
