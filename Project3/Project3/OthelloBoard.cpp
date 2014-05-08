#include "OthelloBoard.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>    // std::sort
#include <vector>       // std::vector
using namespace std;

OthelloBoard::OthelloBoard() : mPassCount(0) { 
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

void OthelloBoard :: GetPossibleMoves(std::vector<GameMove *> *list) const {
	char player = (mNextPlayer == 1) ? 1 : -1;  // switch to obtain enemy piece 
	// checking whole board
	for(int row = 0; row<BOARD_SIZE; row++) {
		for(int col = 0; col<BOARD_SIZE; col++) {
			// checking all 8 directions after finding own piece
			if(mBoard[row][col] == player) {
				for (int rd = -1; rd <=1; rd++) {
					for (int cd = -1; cd <=1; cd++) {

						int newR = row, newC = col, eCount = 0;
						while (InBounds(newR, newC)) {  
							newR = newR + rd; 
							newC = newC + cd;

							// empty square, stop and add possible values
							if (mBoard[newR][newC] == 0) { 

								if (eCount > 0) {
									OthelloMove* move = (OthelloMove*)CreateMove();
									*move = OthelloMove(newR,newC);
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
								else { 
									eCount = 0;
								}
								break;
							}
							// found opposite piece... keep searching
							else if (mBoard[newR][newC] == -player) { 
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

void OthelloBoard::ApplyMove(GameMove *move) {
	// mPassCount -- updated
	// mValue  -- updated
	// mNextPlayer -- updated

	char player = (mNextPlayer == 1) ? 1 : -1;
	OthelloMove *m = (OthelloMove*)move;  

	// check for pass move and update mPassCount
	if (m->IsPass()) {
		mPassCount++;
		mHistory.push_back(m);
	}
	
	else if(!m->IsPass()) {
		mPassCount = 0; 
		mBoard[m->mRow][m->mCol] = player;
		mValue = mValue + player; // update score
		// add move to mHistory
		mHistory.push_back(move);
		for (int rd = -1; rd <=1; rd++) {
			for (int cd = -1; cd <=1; cd++) {
				bool valid = true; 
				int newR = m->mRow, newC = m->mCol, eCount = 0;
				while (valid && InBounds(newR, newC)) {
					newR = newR + rd; 
					newC = newC + cd;
					if (mBoard[newR][newC] == 0) { // empty square
						eCount = 0;
						break;
					}
					// found opposite piece
					else if (mBoard[newR][newC] == -player) { 
						eCount++;
					}
					else { // found same piece as player's
						if (eCount == 0) {
							valid = false; 
						}

						if (eCount > 0) {
							// add flip to flipset as enemy count goes up
							OthelloMove::FlipSet flip(eCount, rd, cd);  
							m->AddFlipSet(flip);
						}
						break;
					}
				}
				
				for (int i = 0; i < eCount; i++) {// update conquered game pieces
					mBoard[newR -= rd][newC -= cd] = player;
					mValue = mValue + player * 2;
				}

			}
		}
	}

	mNextPlayer = -mNextPlayer; // switch turns
	

};

void OthelloBoard::UndoLastMove() {
	// mPassCount -- updateds
	// mValue -- updated
	// mNextPlayer -- updated

	if (GetMoveCount() > 0) {
		OthelloMove* move = (OthelloMove*)mHistory.back();
		int flipSize = move->mFlips.size();

		if(move->IsPass()) {
			mPassCount--;
		}

		else {
			for (int i=0; i<flipSize; i++) {
				int newR = move->mRow, newC = move->mCol;
				int numSwitched = move->mFlips.back().switched; 
				int rd = move->mFlips.back().rowDelta, cd = move->mFlips.back().colDelta;

				for(int ii=0; ii<numSwitched; ii++) {
					// flip value by multiplying by -1
					mBoard[newR += rd][newC += cd] *= -1;  
					mValue = mValue + mNextPlayer * 2;
				}

				move->mFlips.pop_back(); // get rid of last flip 
			}

			mBoard[move->mRow][move->mCol] = 0; // set board piece to empty
			mValue = mValue + mNextPlayer;
		}

		
		// first delete from heap and then from vector
		delete(mHistory.back());
		mHistory.pop_back(); // delete move from history
		mNextPlayer = -mNextPlayer;
	}

};
