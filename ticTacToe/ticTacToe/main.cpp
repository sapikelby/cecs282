/*
** Programmer: Kelby Sapien
** Course: CECS 282, CSULB
** Assignment: Lab 2
*/

#include <iostream>; 
#include "TicTacToe.h";
using namespace std; 


int main(int argc, char* argv[]) {
	int row = 0; 
	int column = 0; 

	// creates 3x3 matrix
	char board[3][3] = 
	{ {'0', '0', '0'},
	  {'0', '0', '0'},	  {'0', '0', '0'}	};

	bool player1 = true;  // player 1 goes first (1)
	bool player2 = false; // player 2 goes after (-1)

	for (int counter = 0; counter<5; counter++) {
		// print tic tac toe board
		PrintBoard(board); 

		if (player1) {
			cout << "X's turn: ";	
			GetMove(row, column);
			
			while (!MoveIsValid(board, row, column)) {
				cout << "That space is already taken!" << endl;
				cout << "X's turn: ";
				GetMove(row, column);
			}
			
			board[row][column] = '1';

			player2 = true;
			player1 = false;
		}

		cout << endl;
		PrintBoard(board); 
		
		if (player2 && counter != 4) {
			cout << "O's turn: ";
			GetMove(row, column);
			
			while (!MoveIsValid(board, row, column)) {
				cout << "That space is already taken!" << endl;
				cout << "O's turn: ";
				GetMove(row, column);
			}
			
			board[row][column] = -1; 
			
			player1 = true;
			player2 = false;
		}
		cout << endl;
	}

	cout << "Thank you for playing!" << endl;
	system("pause");
	return 0; 
}
