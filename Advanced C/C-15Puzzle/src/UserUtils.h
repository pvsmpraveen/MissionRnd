#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
Used to Store Name and His MovesCount , It will be later be used to generate High Scores Table
*/
typedef struct User{
	char *name;
	int movesCount;
};

/*
Create the user from Heap , Assign name to user->name , Make movesCount as 0. 
Return the user .
*/
User * createUser(char *name){
	User *user = (User *)calloc(1, sizeof(User));
	user->name = (char *)calloc(100, sizeof(char));
	user->movesCount = 0;
	strcpy(user->name, name);
	return user;
}


/*
Increase moveCount of user by 1 ,if processInputOutCome is 1 ,Otherwise Leave it .
*/
void modifyMoveCountBasedOnProccessInput(User *user,int processInputOutCome){
	if (processInputOutCome)
		user->movesCount++;
	return;
}

/*
Print the Following String from User Information .Replace accordingly .Dont ask what to Replace .
"Hey Abhijith , You have played 43 Moves "
*/
void printUser(User *user){
	printf("\n\nHey %s, You have Played %d Moves\n", user->name, user->movesCount);
}