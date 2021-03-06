Etch-a-Sketch and Pong (LAB04)
==============================



#Prelab

##Data Types

| Size    | Signed/Unsigned | Type           | Min Value      | Max Value |
|---------|-----------------|----------------|----------------|-----------|
| 8 bit   | Unsigned        | unsigned char,bool, _Bool               |0                |    255       |
| 8 bit   | Signed          |     signed char          |       -128         |      127     |
| 16 bit  | Unsigned        | Unsigned Short |      0          |      65 535       |
| 16 bit  | Signed          | short, signed short                |-32 768                |   32 767        |
| 32 bit  | Unsigned        |    unsigned long            |          0      |    4 294 967 295       |
| 32 bit  | Signed          |  long, signed long              | -2,147,483,648 |    2 147 483 647       |
| 64 bit  | Unsigned        |        unsigned long long        |         0       |    18 446 744 073 709 551 615       |
| 64 bit  | Signed  | long long, signed long long | -9 223 372 036 854 775 808  | 9 223 372 036 854 775 807 |


##Code Definitions

| Type   | Meaning               | C typedef Declaration        |
|--------|-----------------------|------------------------------|
| int8   | unsigned 8 bit value  | typedef unsigned char int8  |
| sint8  | signed 8 bit value    |  typedef signed char sint8   |
| int16  | unsigned 16 bit value | typedef unsigned short int16 |
| sint16 | signed 16 bit value   | typedef signed short sint16 |
| int32  | unsigned 32 bit value | typedef unsigned long int32   |
| sint32 | signed 32 bit value   |  typedef signed long sint32  |
| int64  | unsigned 64 bit value |  typedef unsigned long long int64   |
| sint64 | signed 64 bit value |  typedef signed long long sint64  |


##Calling/Returning Convention

| Iteration | a | b | c | d | e |
|-----------|---|---|---|---|---|
| 1st       | 10  | 9  |  8 |  7 |  10 |
| 2nd       |  16 |  15 |  14 | 13  | 16  |
| 3rd       |  22 |  21 |   20|  19 | 22  |
| 4th       |  28 |  27 |  26 | 25  | 28  |
|5th|34|33|32|31|34|


Note: The values for these variables were found *after* each interation was completed.  



##Registers and Parameters

| Parameter                     | Value Sought |
|-------------------------------|--------------|
| Starting Address of Function  |  0xC0BA     |
| Ending Address of Function    |  0xC0C6    |
| Register holding w            |   R12           |
| Register holding x            |   R13           |
| Register holding y            |   R14           |
| Register holding z            |   R15           |
| Register holding return value |   R12           |

The picture for the proof of the location of "fuct" can be seen below:
![alt tag](https://raw.githubusercontent.com/JohnTerragnoli/ECE382_Lab04/master/2.%20Pictures/2.%20Function%20location%20in%20Simple.PNG "func location")

##Cross Language Build Constructs

1. What is the role of the extern directive in a .c file? Hint: check out the external variable Wikipedia page.

"An external variable is a variable defined outside any function block. On the other hand, a local (automatic) variable is a variable defined inside a function block" (Wiki page).  Therefore, an extern directive is a directive that calls variables which are defined outside of its block function. The difference between being declared and defined is that if something is declared, then it is defined elsewhere.  So whenever an extern variable is called, its definition is being referenced from outside of that function.  These can act almost as global variables so that they can be accessed from many different functions.  This would also allow you to call external variables defined in other files, like the .asm file we used in class the other day.  

2. What is the role of the .global directive in an .asm file (used in lines 28-32)? Hint: reference section 2.6.2 in the MSP 430 Assembly Language Tools v4.3 User's Guide. 

*see below*


The big idea for 1 and 2:::
As Dr. Coulston put it "extern directives allow .c files to communicate with variables and methods stored in .asm files, and .global directives allow .c files to "see" specific functions defined in .asm files."  This is evidently seen in the code used in Lesson 22.  

Additionally, extern and .global directives set up the relocatable object code in such as way as to allow the linker to link the appropriate functions and variables between the .asm and .c code.  


#Basic Functionality

Achieving basic functionality was relatively easy.  The code for the .c and .asm files are below: 

[Basic Functionality.c](https://raw.githubusercontent.com/JohnTerragnoli/ECE382_Lab04/master/1.%20Code/main_basic.c)

[Basic Functionality.asm](https://raw.githubusercontent.com/JohnTerragnoli/ECE382_Lab04/master/1.%20Code/nokia_basic.asm)

##Basic Functionality Process:
1. First, I ensured that Dr. Coulston's code worked by uploading it to the MSP430 and moving the square around the LCD screen.
2. Then I tried to make a "slug" on the screen.  To do this I tried to find the subroutine responsible for clearing the screen continuously. I tried this with many of the subroutines in the .asm file.  Then I realized that the method clearDisplay exists in the .c file.  I deleted this and it made a beautiful slug.  Success.  
2. I edited the .asm file and the function "drawBlock" to intake one more parameter.  I wanted to either pass in the value of 0x00 or 0xFF to the .asm file, which would either draw a white or a black square.  
2. To do this, I defined another parameter for drawBlock called "color," which is a 16 bit long integer.  This is the parameter that will either be 0x00 or 0xFF.  Then, I went into the .asm file and added a push/pop at the beginning and the end of the drawBlock subroutine, respectively.  This was done R14, which is where the third parameter goes when passed into the .asm file.
3. Then, I changed the line "	mov		0xFF, R13" to be "	mov		R14, R13", so that whatever value was passed in with R14 would determine the color of the block drawn.  
4. Then, in the .c code, I needed to determine if the AUX button was pressed or not.  I simply added a check for this in the while loop that runs through all of the other buttons and designed the AUX if statement based on the if statements for the other buttons.  
5. I created a variable in .c called "color," which will be the method passed into the drawBlock method.  
6. I changed all of the callings of the drawBlock subroutine to include color.  
7. At first, I tried switching the value of color in the AUX if statement using nested if statements.  The computer did not like this idea at all and the code would not work for the longest time.  Eventually, I decided that I stared at the screen for too long and worked on a different approach.  
8. I decided that a simpler way to switch the value of color was just to XOR whatever value it was with 0xFF, which would switch it back and fourth from 0x00 to 0xFF.  


The video showing [Required Functionality](https://drive.google.com/file/d/0Bymb7kjtbzuqTldsYmhtQzNCZ2s/view?usp=sharing) is shown here.  

#B Functionality

**B Development Process**
1. First to make this program I thought it was necessary just to have some sort of code that just moves the ball.  I did this by creating two new variables, xVel and yVel, and adding them to the positions x and y each interation of the while loop.  I did not worry about boundaries at first.  
2. When I did this, I just saw a quick blur on the screen.  I realized that the machine was creating and moving the block too quickly.  To fix this I tried to find a delay function on Google.  It seemed that the closest thing there is is just to make a really large "for" loop, which holds nothing but goes through many iterations. 
3. When I first did this, the block appeared but did not move at all.  I figured this was because my delay was just too long.  I shortened the number of iterations.  Then I realized that the number type I was using "char," would never be able to count up to the number I was using.  This meant the "for" loop would never finish!  To fix this I just made the counter of type "long." 
4. Once I changed the number type, I was able to see the ball move.  I adjusted the number of interations for an ideal movement speed of the ball.  
5. Once this occured, the ball moved right and down until it went off of the screen.  
6. Once this was done, I made boundaries to keep the ball on the screen in the x and in the y direction.  Then, I tested to see where the position of the ball was, and when it hit a boundary, the velocity of the ball in that specific component was negated.  This made the ball switch directions.  
7. This was the last thing done.  I have done many labs like this one before.  
8. After this I ran a couple of test cases, such as starting from each of the corners and starting in different directions.  
9. No more errors were encountered.  

The code for the .c and .asm files are below: 

[B Functionality.c](https://raw.githubusercontent.com/JohnTerragnoli/ECE382_Lab04/master/1.%20Code/main_b.c)

[B Functionality.asm](https://raw.githubusercontent.com/JohnTerragnoli/ECE382_Lab04/master/1.%20Code/nokia_B.asm)

The video showing [B Functionality](https://drive.google.com/file/d/0Bymb7kjtbzuqa1FNRWdETEs5Tk0/view?usp=sharing) is shown here.  
A second test case for [B Functionality](https://drive.google.com/file/d/0Bymb7kjtbzuqOGd4bUIzZUx6d0E/view?usp=sharing) is shown here.  

#A Functionality

**Process for A Functionality**
1. This process was a little more difficult. First, I decided that I needed to make a paddle.  Instead of changing the createBlock subroutine, I decided to create another one called "createPaddle."  This subroutine just created a bar for the paddle on the screen. 
2. To do this, I had to create X and Y position variables for the paddle.  The column would always be constant, only the X needed to change.  At first, I was getting errors on the screen which were not pointing to a location in the code.  I then realized I forgot to put the .global and extern prefixes at the front of the code for the createPaddle subroutine.  I added them in and the errors vanished.  
3. Then, I initialized the paddle on the screen.  
4. A problem I had with this was that I did not know how wide the screen was.  I had to use a lot of guessing and checking at first.  Then I remembered that each block is 8 wide and that 11 blocks can fit across the screen.  I used this measurement to pinpoint exactly the column needed to have the paddle on the right side of the screen.  
5. Next, I just wanted to be able to move the paddle while allowing the ball to keep moving.  I just modled this if statment after the ones used in the given functionality.  The issue with this style was that when I pressed down the up or down button to move the paddle, the movement of the ball stopped while the button was held down.  This is clearly an issue!!
6. To fix this, I got rid of the line that pauses the program while the button is held down.  This was created to prevent the bouncing affect.  Because I got rid of this, the paddle and the ball were able to move at the same time, however, the bouncing affect became a larger issue.  This made the button only work sporatically.  Sometimes when it was pressed down the paddle wouldn't move at all.  
7. To combat this, I created a slight delay function for after the buttons were pressed down.  This allowed the mechanics of the button to settle before and action was taken on the button.  The result was a more accurate movement of the paddle.
8. Then I wanted to modify B functionality so that the game "ends" when the ball hits the right side of the screen.  To do this I just created a boolean variable of sorts.  This variable determines whether the program should stay in the "game" while loop or not.  It starts off as TRUE.  When the ball hits the right side of the wall, the variable is changed to FALSE.  The game moves onto the next empty while loop for eternity.  This part was easy to implement and there were no issues. 
9. Then, I made sure that when the ball hit the paddle the ball bounces off as if it hit another wall.  This was fairly simple, as I just made sure the xVel switched when the ball equaled the coordinates of the paddle.  
10. This last part worked well and was implemented easily. 
11. The hardest part of the game was playing it.  I am still pretty bad at it :( 

The code for the .c and .asm files are below: 

[A Functionality.c](https://raw.githubusercontent.com/JohnTerragnoli/ECE382_Lab04/master/1.%20Code/main_A.c)

[A Functionality.asm](https://raw.githubusercontent.com/JohnTerragnoli/ECE382_Lab04/master/1.%20Code/nokia_A.asm)

The video showing [A Functionality](https://drive.google.com/file/d/0Bymb7kjtbzuqaWE0NEkyNHFOOWc/view?usp=sharing) is shown here.  

#Bonus Functionality

##Inverted Screen:

The purpose of this was to recreate B Functionality.  When the AUX button is pressed, however, the color of the ball and of the background must be inverted.  

**Production Process and Trials**
1. First, I altered by code for B Functionality so that the createBlock subroutine included a color parameter that could be passed in.  I did this by stealing the code from Basic Functionality.  
2. Then, I created a sensor which decided whether the AUX button had been clicked or not.  Everytime the AUX button was clicked, the variable "color" was inverted.  At the end of the while loop the block was drawn onto the screen.  The result of this code was that the ball would be bouncing around the screen, the AUX button would be pressed, and the ball would dissapear.  When the AUX button was pressed again the ball would reappear at the further location on its trajectory.  
3. After I got this to occur, all I had to do was ensure that the color of the background changed as well.  To do this, I created a subroutine that is the exact oposite as clearDisplay().  I named it blackDisplay().  
4. To make blackDisplay(), I just copied the code for clearDisplay() and made 0xFF move into R12 and R13 instead of 0x00.  Therefore, blackDisplay() should make the entire screen black. 
5. To test this, I just got rid of all of the other code in the while loop.  Then, I called the blackDisplay() subroutine.  The screen turned black!!! Just like it should have.  
6. Then, I created a color variable, which could either be black or white. 
7. If the color is white, then I call the subroutine by drawBlock(y,x,WHITE), which draws a white block, and blackDisplay(), which resets the screen with a black color every time the ball moves.  
8. If the color is black, then I call the subroutine by drawBlock(y,x,BLACK), which draws a black block, and clearDisplay(), which means the program will operate the exact same way as regular B functionality.  
9. To test these if statements, I just initiated the color either WHITE or BLACK in the beginning of the code.  Then I just tested it to make sure that the screen was displaying the way it was supposed to.  
10. Next, I created a sensor for the AUX button, just like in basic functionality.  When the button is hit, but value of color changes from white to black or black to white.  I did this by XORing the value of color with 0xFF.  This worked fairly easily.  
11. The largest issue I had was that the button was not as responsive as I wish it would be.  Sometimes when it is pressed, it will not negate.  Again, I suspected this to be because of the mechanical bouncing effect.  To fix this, I just made a slight delay from when the button senses that it has been pressed to the time when it is executed.  This did not fix the problem completely, but it did make the AUX button slightly more reliable.  

The largest issue that I forgot to mention was that originally I tried to use the clearDisplay() subroutine with parameters so that it could be used to make the screen black or white.  This gave me a lot of trouble, so I ended up just making the blackDisplay() subroutine.  


The code for the .c and .asm files are below: 

[Inverted Functionality.c](https://raw.githubusercontent.com/JohnTerragnoli/ECE382_Lab04/master/1.%20Code/main_invert.c)

[Inverted Functionality.asm](https://raw.githubusercontent.com/JohnTerragnoli/ECE382_Lab04/master/1.%20Code/nokia_invert.asm)

Here is the video proving [inverting functionality](https://drive.google.com/file/d/0Bymb7kjtbzuqOE9ob1dRSmFYeFE/view?usp=sharing) 






#Documentation: 
##Prelab: NONE
##Rest of Lab: 
C2C Sabin Park told me that it is easier to store code in folder on gitHub and he explained to me how to do it.  




