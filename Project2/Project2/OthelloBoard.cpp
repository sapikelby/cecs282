#include "OthelloBoard.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>    // std::sort
#include <vector>       // std::vector
using namespace std;

OthelloBoard::OthelloBoard() : mNextPlayer(1), mValue(0), mPassCount(0), 
	mHistory(0) { 
	
		for (int i=0; i<BOARD_SIZE; i++) {
			for(int j=0; j<BOARD_SIZE; j++) {
				mBoard[i][j] = 0;
			}
		}

		mBoard[MIDDLE][MIDDLE] = -1; // (3, 3)
		mBoard[MIDDLE][MIDDLE + 1] = 1; 
		mBoard[MIDDLE + 1][MIDDLE] = 1; 
		mBoard[MIDDLE + 1][MIDDLE + 1] = -1; 
};

void OthelloBoard :: GetPossibleMoves(std::vector<OthelloMove *> *list) const {
	//cout << "inside GetPossibleMoves" << endl;
	char player = (mNextPlayer == 1) ? 1 : -1;  // switch to obtain enemy piece 
	// checking whole board
	for(int row = 0; row<BOARD_SIZE; row++) {
		for(int col = 0; col<BOARD_SIZE; col++) {
			// checking all 8 directions
			if(mBoard[row][col] == player) {
				for (int rd = -1; rd <=1; rd++) {
					for (int cd = -1; cd <=1; cd++) {

						int newR = row, newC = col, eCount = 0;
						while (InBounds(newR, newC)) {  // &&valid) {
							//cout << "still in loop " << "row: " << row << "col: " << col << endl;
							newR = newR + rd; 
							newC = newC + cd;

							if (mBoard[newR][newC] == 0) { // empty square, stop and add possible values
								

								if (eCount > 0) { // set valid = false to add moves
									//valid = false;
									OthelloMove* move = CreateMove();
									*move = OthelloMove(newR,newC);
									bool existAlready = false;
									for(OthelloMove* i : *list) {
										if (*i == *move) {
											existAlready = true;
										}
										//break;
									}
									if (existAlready) {
										delete(move);
									}
									else {
										//sameRow = true;
										list->push_back(move);
									}
								}
								else { 
									eCount = 0;
								}
								break;
							}
							else if (mBoard[newR][newC] == -player) { // found opposite piece... keep searching
								eCount++;
							}
							else { // found same piece as player's
								break;

							}

						}

						
					}
				}
			}
		}
	}
	// if no move was added, add pass move
	if (list->empty()) {
		list->push_back(&OthelloMove());
	}
};

void OthelloBoard::ApplyMove(OthelloMove *move) {
	// mPassCount -- updated
	// mValue  -- updated
	// mNextPlayer -- updated

	char player = (mNextPlayer == 1) ? 1 : -1;

	
	// check for pass move and update mPassCount
	if (move->IsPass()) {
		mPassCount++;
		mHistory.push_back(move);
	}
	
	// assume valid move, check if it's on the vector list
	//if(move->mRow >= 0 && move->mCol >=0) {
	else if(!move->IsPass()) {
		mPassCount = 0; 
		mBoard[move->mRow][move->mCol] = player;
		mValue = mValue + player; // update score
		// add move to mHistory
		mHistory.push_back(move);
		for (int rd = -1; rd <=1; rd++) {
			for (int cd = -1; cd <=1; cd++) {
				bool valid = true; 
				int newR = move->mRow, newC = move->mCol, eCount = 0;
				while (valid) {
					newR = newR + rd; 
					newC = newC + cd;
					if (mBoard[newR][newC] == 0) { // empty square
						eCount = 0;
						break;
					}
					else if (mBoard[newR][newC] == -player) { // found opposing piece
						eCount++;
					}
					else { // found same piece as player's
						if (eCount == 0) {
							valid = false; 
						}

						if (eCount > 0) {
							// add flip to flipset as enemy count goes up
							OthelloMove::FlipSet flip(eCount, rd, cd);  
							move->AddFlipSet(flip);
						}
						break;
					}
				}
				
				for (int i = 0; i < eCount; i++) {// update conquered game pieces
					//cout << "updating pieces" << endl;
					mBoard[newR -= rd][newC -= cd] = player;
					mValue = mValue + player * 2;
					//cout << "board val: " << mValue << endl;
				}
				
				/*
				while(eCount > 0) {
					mBoard[newR -= rd][newC -= cd] = player;
					eCount--;
					//mValue = mValue + player * 2;
					cout << "board val: " << mValue << endl;
					
				}
				*/

			}
		}
	}

	
	mNextPlayer = -mNextPlayer; // switch turns
	
	/*
	mValue = 0; // update the value of the board
	for(int row =0; row<BOARD_SIZE; row++) {
		for(int col=0; col<BOARD_SIZE; col++) {
			mValue = mValue + mBoard[row][col];
		}
	}
	*/
	

};

void OthelloBoard::UndoLastMove() {
	// mPassCount -- updateds
	// mValue -- updated
	// mNextPlayer -- updated

	//OthelloMove* move;
	if(GetMoveCount() > 0) {
		OthelloMove* move = mHistory.back();
		int flipSize = move->mFlips.size();

		if(move->IsPass()) {
			mPassCount--;
		}

		else {
			for(int i=0; i<flipSize; i++) {
				int newR = move->mRow, newC = move->mCol;
				int numSwitched = move->mFlips.back().switched; 
				int rd = move->mFlips.back().rowDelta, cd = move->mFlips.back().colDelta;

				for(int ii=0; ii<numSwitched; ii++) {
					//cout << "undoing moved pieces" << endl;
					mBoard[newR += rd][newC += cd] *= -1;  // flip value by multiplying by -1
					mValue = mValue + mNextPlayer * 2;
				}

				move->mFlips.pop_back(); // get rid of last flip 
			}

			mBoard[move->mRow][move->mCol] = 0; // set board piece to empty
			mValue = mValue + mNextPlayer;
			// first delete from heap and then from vector
		}
		delete(mHistory.back());
		mHistory.pop_back(); // delete move from history
		mNextPlayer = -mNextPlayer;
	}



	/*
	// update mValue 
	mValue = 0; // update the value of the board
	for(int row =0; row<BOARD_SIZE; row++) {
		for(int col=0; col<BOARD_SIZE; col++) {
			mValue = mValue + mBoard[row][col];
		}
	}
	*/
};
