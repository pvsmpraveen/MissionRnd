#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//Helper Utils
#include "BoardUtils.h"
#include "UserUtils.h"
#include "MovesUtils.h"

/*
Objective of the Game .

Given a Random Board of 15 Pieces .You need to move the pieces in such a way that all pieces will be in asceding order or correct order .
You can refer the below link for the Game details .The Correct order is the one shown in the picture .
Link : https://en.wikipedia.org/wiki/15_puzzle

How we are going to Design the Game .?

We are using a Board structure to store the Table information , which also stores rows,cols,Empty Tile Row and Empty Tile Column .
All The Board Related functions are in BoardUtils.h
We are representing the emptyTile using 0 in the 2d Array .
We are using a User struct to store Who is playing the game and the number of moves he made .We are going to revisit this game again ,So make sure you are
implementing every feature .
User related functions are present in UserUtils.h 

How Game is played :
It is played by moving some other Tile into the empty Space .
Ex if the first row has 1,0,2,4 [0 specifying empty Tile ] ,By pressing D and Enter , The First row will be modified as 0,1,2,4 .

W is used to move any Tile to the Up , S is used to move any Tile down , A for left and D for right .

Ex Move 'A' or 'a' :

1 2 3      1 2 3
4   5  ==> 4 5
6 7 8      6 7 8

Ex Move 'D' or 'd' :

1 2 3      1 2 3
4   5  ==>   4 5
6 7 8      6 7 8

Ex Move 'W' or 'w' :

1 2 3      1 2 3
4   5  ==> 4 7 5
6 7 8      6   8

Ex Move 'S' or 's' :

1 2 3      1   3
4   5  ==> 4 2 5
6 7 8      6 7 8

If by making moves you reach the final Correct position ,The game is completed .

Moves Related Functions are There in MovesUtils.h

What you need to do .
Just go over every function in all 3 files ,once and Read the description .[If you dont get it its okay ]
Now read the Comments in the main function .
Implement Step by Step .

You need to fill all the helper functions in all Utils Files and the test cases will directly call them and check .
Make sure you satisfy all constraints of the helper Functions.Main Function is for you to get a feel of how game is played and see any errors .

We want you to learn how to get Good Code in this lesson and how to modularise ,
If you really think through ,you will easily get that by writing game in this way ,It can be scalable for any more features ,
and anyone else can understand our code easily .You can go through the Test Cases , and Have fun building more test cases too .

Example Video of Game :https://www.youtube.com/watch?v=DDkCt5tv3_k

Btw ,If you think you are wasting a lot of time by writing more 
and more functions for simple Tasks ,get over that thought as soon as possible .Maintainable Code is far more important than 0.0001 Seconds improvement
which might be acheived with less functions .
When you are in really good product company(In summer camp also),This is the way we expect you to write code ,Actually far more better than this .
*/


int main()
{

	
	//Create a User and store it in user .You can take the name as input from keyboard.
	char username[100];

	printf("Enter User Name : ");
	scanf("%s", username);
	
	User *user1 = createUser(username);

	user1->movesCount = 0;
	//Declare two variables called rows&cols
	int rows = 4, cols = 4;

	//Declare a 2D Array ,and assign some values to it .Let this array be table .
	int table[][4] = {
		{ 1, 2, 3, 4 },
		{ 0, 5, 7, 8 },
		{ 10, 6, 11, 12 },
		{ 9, 13, 14, 15 }
	};

	//Create a board using rows and cols
	Board *temp = createBoard(4, 4);

	//Initalize the board with table ,Pass it as (int *)table
	initializeBoard(temp, (int *)table, 4, 4);

	//First Clear and Redraw the Screen ,First Time we need to show the board right ?
	clearAndRedrawScreen(temp);
	printUser(user1);

	//Also call printUser , You also need to show ,his name and movesCount.
	char input;
	//Use a Loop which repeatedly takes input from User and calls playMove function ,till the Game is Won (ie checkBoard shoudl return ??? ) .
	
	while (!checkBoard(temp)){
		do{
			printf("\nEnter Move : ");
			input = takeInput();
			clearAndRedrawScreen(temp);
			printUser(user1);
		} while (!processInput(temp, input));
		playMove(temp,user1,input);
		printUser(user1);
	}

	//Display Game is completed in 2324 Moves ,Good work <Name>

	printf("Game is completed in %d Moves,Good Work %s", user1->movesCount, user1->name);
	system("PAUSE");
	
	//printf("GAME NOT IMPLEMENTED YET\n");

	return 0;
}





