#include <iostream>; 
#include "TicTacToe.h";
using namespace std; 

void initializeBoard(char board[3][3]) {
	
}

int main(int argc, char* argv[]) {
	//char gameBoard[3][3]; 
	int row = 0; 
	int column = 0; 
	bool player1 = true;  // player 1 goes first (1)
	bool player2 = false; // player 2 goes next (-1)

	char gameBoard[3][3] = 
	{ {'0', '0', '0'},
	  {'0', '0', '0'},	  {'0', '0', '0'}	};
	/*
	PrintBoard(gameBoard);
	GetMove(row, column); 

	cout << row << " " << column << endl;
	
	if(MoveIsValid(gameBoard, row, column)) {
		cout << "Move is valid" << endl; 
	}
	else {
		cout << "That space is taken already" << endl;
	}

	*/

	for(int counter = 0; counter<10; counter++) {
		PrintBoard(gameBoard);

		if(player1) {
			cout << "X's turn: "; //<< endl;	
			GetMove(row, column);
			while(!MoveIsValid(gameBoard, row, column)) {
				cout << "That space is already taken!" << endl;
				cout << "X's turn: ";
				GetMove(row, column);
				//cout << counter; 
			}

			if(MoveIsValid(gameBoard, row, column))
			{
				gameBoard[row][column] = '1'; 
			}
			player2 = true;
			player1 = false;
		}

		PrintBoard(gameBoard);

		if(player2) {
			cout << "O's turn: "; //<< endl;
			GetMove(row, column);
			while(!MoveIsValid(gameBoard, row, column)) {
				cout << "That space is already taken!" << endl;
				cout << "O's turn: ";
				GetMove(row, column);
				//cout << counter;
			}

			if(MoveIsValid(gameBoard, row, column))
			{
				gameBoard[row][column] = '-1'; 
			}
			player1 = true;
			player2 = false;
		}


	}

	system("pause");
	return 0; 
}
