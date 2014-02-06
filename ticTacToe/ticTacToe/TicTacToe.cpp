// function definitions
#include <iostream>
#include <string>;
using namespace std; 
// PrintBoard takes a 2-dimensional array parameter representing the game state
// and prints it to cout. See the spec for details on formatting the output.
void PrintBoard(char board[3][3]) {
	// replace values within board
	for (int r = 0; r<3; r++) {
		for (int c = 0; c<3; c++) {
			if (board[r][c] == '1') {   // . = 0
				board[r][c] = 'X';
			}
			else if(board[r][c] == '0') {
				board[r][c] = '.';
			}
			else {
				board[r][c] = '.';
			}
		}
	}

	string boardHeader = "- 0 1 2"; 
	cout << boardHeader << endl;
	cout << "0 " << board[0][0] << " " << board[0][1] << " " << board[0][2] << endl; 
	cout << "1 " << board[1][0] << " " << board[1][1] << " " << board[1][2] << endl;
	cout << "2 " << board[2][0] << " " << board[2][1] << " " << board[2][2] << endl;
	cout << endl;
}
// GetMove uses cin to read the user's choice for where to move next on the 
// board. It does NOT update the game board with the move choice; it simply
// scans in values to the row and col variables, which will update whatever
// variables were used as arguments in the main. Do not check move validity
// in this function.
void GetMove(int &row, int &col) {
	char comma; 
	cin >> row >> comma >> col; 
}

// MoveIsValid returns true if the board is empty at the requested row/col,
// and false otherwise. used in main to see if the move is valid and alert
// the user if it is not.
bool MoveIsValid(char board[3][3], int row, int col) {

	// check for spaces holding values
	for (int r = row; r<3; r++) {
		for (int c = col; c<3; c++) {
			if (board[r][c] == '.' || board[r][c] == '0') {   // . = 0
				return true;
			}
			else {
				return false; 
			}
		}
	}

	// check for out of bounds
	if(row >= 3 || col >= 3)
	{
		cout << "That space does not exist!" << endl;
		return false;
	}

	
}