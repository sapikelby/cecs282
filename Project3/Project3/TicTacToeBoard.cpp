#include "TicTacToeBoard.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>    // std::sort
#include <vector>       // std::vector
using namespace std;

TicTacToeBoard::TicTacToeBoard() { 
	cout << "initializing tic tac toe board" << endl;
	for (int i=0; i<BOARD2_SIZE; i++) {
		for(int j=0; j<BOARD2_SIZE; j++) {
			mBoard[i][j] = 0;
		}
	}
 
};

void TicTacToeBoard::GetPossibleMoves(std::vector<GameMove *> *list) const {
	char player = (mNextPlayer == 1) ? 1 : -1;  // switch to obtain enemy piece 
	// checking whole board
	for(int row = 0; row<BOARD2_SIZE; row++) {
		for(int col = 0; col<BOARD2_SIZE; col++) {
			if (mBoard[row][col] == 0) {
				TicTacToeMove* move = (TicTacToeMove*)CreateMove();
				*move = TicTacToeMove(row,col);
				bool existAlready = false;
				for(GameMove* i : *list) {
					if (*i == *move) {
						existAlready = true;
						//cout << string(*i) << endl;
					}
				}
				if (existAlready) {
					delete(move);
				}
				else {
					list->push_back(move);
				}
			}
		}
	}
};

void TicTacToeBoard::GetWinner() {
	
	char player = (mNextPlayer == 1) ? 1 : -1;  
	int count = 0;
	// checking whole board
	for(int row = 0; row<BOARD2_SIZE; row++) {
		for(int col = 0; col<BOARD2_SIZE; col++) {
			bool foundPiece = true;
			
			// checking all 8 directions after finding own piece
			//if(mBoard[row][col] == player) {
				for (int rd = -1; rd <=1; rd++) {
					for (int cd = -1; cd <=1; cd++) {
						
						int newR = row, newC = col;
						//cout << "(" << newR << "," << newC << ")" << endl;
						while (InBounds(newR, newC) && foundPiece) {  
							newR = newR + rd; 
							newC = newC + cd;

							cout << "inside while" << endl;

							if (mBoard[newR][newC] == player) { // found same piece as player's
								//break;
								cout << "Found same piece " << GetPlayerString(player) << endl;
								cout << "(" << newR << "," << newC << ")" << endl;
								cout << endl;
								if (count == 3)
								{
									cout << "updating mValue" << endl;
									mValue = player;
								}

								count++;
								cout << "count: " << count << endl;
							}

							// found opposite piece... keep searching
							else if (mBoard[newR][newC] == -player) { 
								//eCount++;
								//count = 0;
								cout << "Found opposite piece" << endl;

								if (count == 3)
								{
									cout << "updating mValue" << endl;
									mValue = player;
								}

								foundPiece = false;
								//break;
							}

							// empty square, stop and add possible values
							else {//(mBoard[newR][newC] == 0)
								cout << "Found empty piece" << endl;
								
								if (count == 3)
								{
									cout << "updating mValue" << endl;
									mValue = player;
								}
								//else count = 0;
								foundPiece = false;
								//break;
							}
							
							

						}

						
					}
				}
			//}
		}
	}

	//char player = (mNextPlayer == 1) ? 1 : -1;

	/*
	char s1 = mBoard[0][0];
	char s3 = mBoard[0][2];
	char s7 = mBoard[2][0];
	char s9 = mBoard[2][2];
	*/

	//  0 1 2
	//0 X . X
	//1 . . .
	//2 X . X



	/*
	// 0 1 2
	/0 X . X
	/1 . . .
	/2 X . X
 	for(int row = 0; row < BOARD2_SIZE; row++) {
		for (int col = 0; row < BOARD2_SIZE; col++) {
			if (mBoard[row][col] == mBoard[row][col+1] && col+1 != 3 && mBoard[row][col] != '.') {
				horCount++;
				cout << "updating count " << horCount << endl;
				//arrayS[(row + 1) * col] = 1;
			}
			
			else if (mBoard[row][col] == mBoard[row+1][col] && row+1 != 3 && mBoard[row][col] != '.') {
				verCount++;
				cout << "updating count" << verCount << endl;
			}
			else {
				horCount = 0; 
				verCount = 0;
			}

		}
	}
	
	if(horCount == 3 || verCount == 3) {
		mValue = mNextPlayer; // update with player's char
	}
	
	*/


	/*
	int player = (mNextPlayer == 1) ? 1 : -1;
	//int horCount = 0;
	//int verCount = 0;
	//int newR = 0; 
	//int newC = 0;
	bool hor = false;
	bool ver = false;
	bool foundPiece = false;
	for(int row = 0; row<BOARD2_SIZE; row++) {
		for(int col = 0; col<BOARD2_SIZE; col++) {
			int newR = row, newC = col;
			int horCount = 0;
			int verCount = 0;
			if(mBoard[row][col] == player) {
				horCount++;
				verCount++;
				cout << "current count: " << horCount << "h v" << verCount << endl;
				cout << "found piece : " << player << endl;
				foundPiece = true;
				while (foundPiece && InBounds(newR, newC)) {
					newR += 1; 
					newC += 1;

					// horizontal check
					if(mBoard[row][col] == mBoard[row][newC]) {
						//newC = newC + 1;
						horCount++;
						cout << "hor count: " << horCount << endl;
					}
					
					// vertical check
					if(mBoard[row][col] == mBoard[newR][col]) {
						
						//newR = newR + 1;
						verCount++;
						cout << "ver count: " << verCount << endl;
					}

					if(horCount == 3 || verCount == 3) {
						cout << "updating mValue" << endl;
						mValue = player;
					}

					if(mBoard[newR][newC] == -player || mBoard[newR][newC] == 0) {  // found empty piece or enemy piece
						cout << "exiting loop vCount: " << verCount << " hCount:" << horCount << endl;
						//horCount = 0, verCount = 0;
						newR = 0; 
						newC = 0;
						foundPiece = false;
						break;
					}

				}

				if(horCount == 3 || verCount == 3) {
					cout << "updating mValue" << endl;
					mValue = player;
				}
			}


			*/
				// search right, left, bottom, up and diagonally

				//cout << "inside 2nd for loop" << player << endl;
				/*
				for (int rd = -1; rd <=1; rd++) {
					for (int cd = -1; cd <=1; cd++) {
						cout << "in loop" << endl;
						int newR = row, newC = col; //count = 0;
						while (InBounds(newR, newC)) {  
							newR = newR + rd; 
							newC = newC + cd;

							if (mBoard[newR][newC] == 0) { 
								count = 0;
								break;
							}
							else if (mBoard[newR][newC] == player) { 
								count++;
								cout << "count: " << count << endl;
							}


						}

						if(count == 3) {
							mValue = player;
						}

					}
					*/
				//}
			//}
		

};

void TicTacToeBoard::ApplyMove(GameMove *move) {
	// mPassCount -- updated
	// mValue  -- updated
	// mNextPlayer -- updated

	char player = (mNextPlayer == 1) ? 1 : -1;
	TicTacToeMove *m = (TicTacToeMove*)move;  
		
	mBoard[m->mRow][m->mCol] = player;

	// add move to mHistory
	mHistory.push_back(m);
	
	//mValue = GetWinner(); // check for winner
	GetWinner(); // check for winner before switching turns
	mNextPlayer = -mNextPlayer; // switch turns
	

};

void TicTacToeBoard::UndoLastMove() {
	// mPassCount -- updateds
	// mValue -- updated
	// mNextPlayer -- updated

	if (GetMoveCount() > 0) {
		TicTacToeMove* move = (TicTacToeMove*)mHistory.back();

		mBoard[move->mRow][move->mCol] = 0; // set board piece to empty

		// first delete from heap and then from vector
		delete(mHistory.back());
		mHistory.pop_back(); // delete move from history
		mNextPlayer = -mNextPlayer;
		//GetWinner();
	}

};
