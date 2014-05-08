#include "TicTacToeBoard.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>    // std::sort
#include <vector>       // std::vector
using namespace std;

TicTacToeBoard::TicTacToeBoard() { 
	
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
	
	for(int i=0; i<BOARD2_SIZE; i++)
	{
		// checking horizontals
		if (mBoard[i][0] == mBoard[i][1] && mBoard[i][0] == mBoard[i][BOARD_EDGE] && 
			mBoard[i][0] != 0) {
				mValue = mBoard[i][0];
		}

		// checking vertical
		if (mBoard[0][i] == mBoard[1][i] && mBoard[0][i] == mBoard[BOARD_EDGE][i] && 
			mBoard[0][i] != 0) {
				mValue = mBoard[0][i];
		}

	}

	// check diagonals
	if (mBoard[0][0] == mBoard[1][1] && mBoard[0][0] == mBoard[BOARD_EDGE][BOARD_EDGE] && 
		mBoard[0][0] != 0) {
		mValue = mBoard[0][0];
	}

	if (mBoard[BOARD_EDGE][0] == mBoard[1][1] && mBoard[BOARD_EDGE][0] == mBoard[0][BOARD_EDGE] && 
		mBoard[BOARD_EDGE][0] != 0) {
		mValue = mBoard[BOARD_EDGE][0];
	}
	
};

void TicTacToeBoard::ApplyMove(GameMove *move) {
	TicTacToeMove *m = (TicTacToeMove*)move;  
		
	mBoard[m->mRow][m->mCol] = mNextPlayer;

	// add move to mHistory
	mHistory.push_back(m);
	//check for winner
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
	}

};
