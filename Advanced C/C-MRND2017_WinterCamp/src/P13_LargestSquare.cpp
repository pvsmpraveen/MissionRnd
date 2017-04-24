#include<stdio.h>
#include<stdlib.h>

/// Given a 2D map with 0s and 1s. 
/// Find the first largest square filled with 1s.
/// RETURN the side of the square found. 
///        -1 for abnormal cases.
/// Place the row, column of the top-left 1 in 'row' and 'col'.
/// If 'row' or 'col' is NULL, then assume that the caller decided that
/// he/she doesn't need that value.

int min(int a, int b) { return a < b ? a : b; }

int largestSquare(int *map, int nRows, int nCols, int *row, int *col) {
	if (map == NULL) return -1;
	int **arr = (int **)calloc(nRows + 1, sizeof(int *));
	for (int i = 0; i < nRows; i++){
		arr[i] = (int *)calloc(nCols + 1, sizeof(int));
		for (int j = 0; j < nCols; j++){
			arr[i][j] = map[nCols*i + j];
		}
	}

	int **dp = (int **)calloc(nRows + 1, sizeof(int *));
	for (int i = 0; i < nRows; i++){
		dp[i] = (int *)calloc(nCols + 1, sizeof(int));
	}
	int Max = 0, Row = 0, Col = 0;
	for (int i = 0; i < nRows; i++){
		for (int j = 0; j < nCols; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < nRows; i++){
		if (arr[i][0] == 1) {
			dp[i][0] = 1;
			Max = dp[i][0];
			Row = i;
		}

	}
	for (int i = 0; i < nCols; i++) {
		if (arr[0][i] == 1){
			dp[0][i] = 1;
			Max = 1;
			Col = i;
		}
	}
	for (int i = 0; i < nRows; i++){
		for (int j = 0; j < nCols; j++){
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}

	for (int i = 1; i < nRows; i++){
		for (int j = 1; j < nCols; j++){
			if (arr[i][j]== 0)
				dp[i][j] = 0;
			else{
				dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]))+1;
				if (dp[i][j]>Max){
					Row = i;
					Col = j;
					Max = dp[i][j];
				}
			}
		}
	}
	for (int i = 0; i < nRows; i++){
		for (int j = 0; j < nCols; j++){
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	int tmp = Max;
	if (row) *row = Row-Max+1;
	if (col) *col = Col-Max+1;

	return Max;
}