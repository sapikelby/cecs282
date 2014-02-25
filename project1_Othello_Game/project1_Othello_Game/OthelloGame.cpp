#include <iostream>
#include <string>
#define BOARD_SIZE 8

using namespace std; 

// prints board squares based on value at each array index
void PrintBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
	string strBoard = string();

	cout << "- 0 1 2 3 4 5 6 7" << endl;
	for (int i=0; i<BOARD_SIZE; i++) {
		cout << i << "";
		for (int j=0; j<BOARD_SIZE; j++) {
			if (board[i][j] == 0) {
				strBoard =  strBoard + " .";
			}
			else if (board[i][j] == 1) {
				strBoard =  strBoard + " B";
			} 
			else {
				strBoard =  strBoard + " W";
			}
		}
		cout << strBoard << endl;
		strBoard = "";
	}
}

void GetMove(int *row, int *column)
{
	//input = (row , col)
	// dereferenced to update vals
	char trash;
	cin >> trash >> *row >> trash >>  *column >> trash; 
}

bool InBounds(int row, int column)
{
	return (row >= 0 && row < BOARD_SIZE && 
		column >= 0 && column < BOARD_SIZE); 
}

bool IsValidMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int column)
{
	return (InBounds(row, column) && board[row][column] == 0 || 
		(row == -1 && column == -1));

}

int GetValue(char board[BOARD_SIZE][BOARD_SIZE])
{
	int score = 0;
	for (int i=0; i<BOARD_SIZE; i++) {
		for (int j=0; j<BOARD_SIZE; j++) {
			score = score + board[i][j];
		}
	}
	return score;
}


void ApplyMove(char board[BOARD_SIZE][BOARD_SIZE], int row, 
			   int column, bool playerBlack) 
{
	int eCount = 0;
	board[row][column] = playerBlack ? 1 : -1; //update square with player's color

	for (int rd = -1; rd <=1; rd++) {
		for (int cd = -1; cd <=1; cd++) {
			bool valid = true; 
			int newR = row, newC = column;
			while (valid) {
				newR = newR + rd; 
				newC = newC + cd;
				if (board[newR][newC] == 0) { // empty square
					eCount = 0;
					break;
				}
				else if (board[newR][newC] != board[row][column]) { // found opposing piece
					eCount++;
				}
				else { // found same piece as player's
					if (eCount == 0) {
						valid = false; 
					}
					break;
				}
			}

			for (int i = 0; i < eCount; i++) {// update conquered game pieces
				board[newR -= rd][newC -= cd] = board[row][column];
			}
		}

	}

}
