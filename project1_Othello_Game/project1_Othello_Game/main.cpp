#include <iostream>
#include <string>
#include "OthelloGame.h"

// Programmer: Kelby Sapien
// CECS 285 Project 1 (Othello Game)

using namespace std; 
const int MIDDLE = 3; 
const int PASS_LIMIT = 2;

int main(int argc, char* argv[])
{
	cout << "Welcome to Othello!" << endl << endl; 

	// create empty game board
	char board[BOARD_SIZE][BOARD_SIZE]; 
	for (int i=0; i<BOARD_SIZE; i++) {
		for (int j=0; j<BOARD_SIZE; j++) {
			board[i][j] = 0;
		}
	}

	// ctrl a, ctrl k, ctrl f

	// initial setup
	board[MIDDLE][MIDDLE] = -1;
	board[MIDDLE + 1][MIDDLE + 1] = -1;
	board[MIDDLE][MIDDLE + 1] = 1;
	board[MIDDLE + 1][MIDDLE] = 1;

	int row, column, passCount = 0;
	bool playerBlack = true;  // Black piece goes first

	int *rowPtr = &row; 
	int *colPtr = &column;


	while (passCount < PASS_LIMIT)
	{
		PrintBoard(board); 
		string turn = playerBlack ? "Black's turn: " : "White's turn:"; 
		cout << turn << endl << "Please choose a move: " << endl;

		GetMove(rowPtr, colPtr); // get move from user

		while (!IsValidMove(board, row, column)) //get move again if move is invalid
		{
			cout << "Invalid move! Please choose a move again: ";
			GetMove(rowPtr, colPtr); 
		}

		if (row == -1 && column == -1) { // check for pass
			cout << turn << " skipped" << endl;
			passCount++; 
		}
		else { // apply move and reset passCount if needed
			passCount = 0;
			ApplyMove(board, row, column, playerBlack); 
		}

		playerBlack = !playerBlack; 
	}

	// check for winner
	int score = GetValue(board); 

	string winner = (score > 0) ? "Black wins" : (score < 0 ?
		"White wins" : "Tie!");

	cout << "Game over! " << winner << endl;

	system("pause"); 
	return 0; 
}