
int goLeft(Board *board);
int goUp(Board *board);
int goDown(Board *board);
int goRight(Board *board);
void swap(Board *board, int x1, int y1, int x2, int y2);
int isValidInput(char letter);



/*
Take Only Valid Input W,A,S,D,w,a,s,d . If Invalid input is entered ,Take input again . Keep Taking input until its valid
Hint : Use While Loop and isValidInput function
*/
char takeInput()
{
	char input='z';
	do{
		//printf("\nControls : \n\n");
		//printf("\t[UP]\t\t --->\t\t[W]");
		//printf("\n[Left]\t\t[Right]  --->\t[A]\t\t[D]");
		//printf("\n\t[Down]\t\t --->\t\t[S]\n");
		//printf("\n\nMove Input : ");
		fflush(stdin);
		input = getchar();
		
	} while (!isValidInput(input));
	/*
	Take input and return it ,Use fflush if scanf is being used .
	Does this function need fflush ? Whats fflush ? Post your observations in the forum ,if fflush is present/not present.
	*/
	return input;
}
/*
Return 1 for Valid Input ie if w,a,s,d,W,A,S,D are entered .
Return 0 for all other inputs
*/
int isValidInput(char letter){
	char Valid[8] = { 'w', 'a', 's', 'd', 'W', 'A', 'S', 'D' };
	bool ok = false;
	for (int i = 0; i<8; i++){
		if (letter == Valid[i])
			ok = true;
	}
	return ok;
}
/*
Process the Given Input .Ie Decide whether to move Left , Right , Up ,or Down based on W,A,S,D,w,a,s,d.
Call goLeft Function if A or a are entered.,similarly do for all valid inputs .
Output :
Returns 1 : If Input is Valid and Move is also Valid .
Returns 0 : If Input if Valid and Move is Invalid .
Returns 0: If Input is invalid ,like other letters are entered or sent through takeInput. 
*/
int processInput(Board *board, char inputChar)
{
	int ok = isValidInput(inputChar);
	if (!ok) return 0;

	int x = board->emptyTileRow;
	int y = board->emptyTileCol;

	if ((inputChar == 'w' || inputChar == 'W') && x == board->rows-1)
		return 0;
	if ((inputChar == 'a' || inputChar == 'A') && y == board->cols-1)
		return 0;
	if ((inputChar == 's' || inputChar == 'S') && x ==  0)
		return 0;
	if ((inputChar == 'd' || inputChar == 'D') && y ==  0 )
		return 0;
	/*
	Handle the input char inputChar ,which is either w,a,s,d,W,A,S,D for up,left,down and right

	*/
	return 1;
}

/*
This Method is invoked when a character is taken as input ie User has played his ValidMove ,and you need to proccess that Move .
Steps to be Done :
1)Call ProcessInput
2)Call modifyMoveCountBasedOnProccessInput and also pass Step 1s output
3)Call clearAndRedrawScreen
4)Call printUser
*/
void playMove(Board *board, User *user, char choice){
	int ok = processInput(board,choice);
	if (!ok)
		return;

	int processInputOutCome=0;

	if (choice == 'a' || choice == 'A')
		processInputOutCome = goLeft(board);
	else if (choice == 's' || choice == 'S')
		processInputOutCome = goDown(board);
	else if (choice == 'd' || choice == 'D')
		processInputOutCome = goRight(board);
	else if (choice == 'w' || choice == 'W')
		processInputOutCome = goUp(board);

	modifyMoveCountBasedOnProccessInput(user, processInputOutCome);
	clearAndRedrawScreen(board);
	//printf("Play move not implemented yet , Remove this printf btw ");
}

/*
Move the 0 Tile one position to the left .
Return 1 if the move is possible, 0 other wise .
*/
int goLeft(Board *board)
{
	int rows = board->rows;
	int cols = board->cols;
	int x = board->emptyTileRow;
	int y = board->emptyTileCol;

	swap(board, x, y, x, y+1);
	return 1;
}

/*
Move the 0 Tile one position to the Right.
Return 1 if the move is possible, 0 other wise .
*/
int goRight(Board *board)
{
	int rows = board->rows;
	int cols = board->cols;
	int x = board->emptyTileRow;
	int y = board->emptyTileCol;

	swap(board, x, y, x, y-1);
	return 1;
}

/*
Move the 0 Tile one position to the UP .
Return 1 if the move is possible, 0 other wise .
*/
int goUp(Board *board){
	int rows = board->rows;
	int cols = board->cols;
	int x = board->emptyTileRow;
	int y = board->emptyTileCol;

	swap(board, x, y, x+1, y);
	return 1;
}

/*
Move the 0 Tile one position to the Down .
Return 1 if the move is possible, 0 other wise .
*/
int goDown(Board *board){
	int rows = board->rows;
	int cols = board->cols;
	int x = board->emptyTileRow;
	int y = board->emptyTileCol;

	swap(board, x, y, x-1, y);

	return 1;
}


/*
You can use this Helper SWAP Function which can remove lots of extra Code from above functions .
*/
void swap(Board *board,int x1, int y1, int x2, int y2)
{
	//printf("%d %d %d %d\n", x1, y1, x2, y2);
	//system("PAUSE");
	
	int tempx = board->table[x1][y1];
	board->table[x1][y1] = board->table[x2][y2];
	board->table[x2][y2] = tempx;

	board->emptyTileRow = x2;
	board->emptyTileCol = y2;
	return;
}

