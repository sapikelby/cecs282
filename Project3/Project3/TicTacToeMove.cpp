#include "TicTacToeMove.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int TicTacToeMove::mOutstanding = 0;

TicTacToeMove::TicTacToeMove() : mRow(0), mCol(0) {
};

TicTacToeMove::TicTacToeMove(int row, int col) : mRow(row), mCol(col) {
};

TicTacToeMove::TicTacToeMove(const TicTacToeMove& move) : mRow(move.mRow), 
	mCol(move.mCol) {
};

GameMove& TicTacToeMove::operator=(const string& strMove) {
	istringstream is(strMove); 
	char temp;
	is >> temp >> mRow >> temp >> mCol >> temp; 
	
	return *this;
};

// ADD: an assignment operator taking a const OthelloMove& object.
TicTacToeMove& TicTacToeMove::operator=(const TicTacToeMove& otherMove)
{
	if (this == &otherMove) {
		return *this;
	}

	mRow = otherMove.mRow; 
	mCol = otherMove.mCol; 
	return *this;
};

/*
bool operator==(const OthelloMove &lhs, const OthelloMove &rhs) {
	return lhs.mRow == rhs.mRow && lhs.mCol == rhs.mCol; 
};
*/
bool TicTacToeMove::Equals(const GameMove& other) const {
	TicTacToeMove& move = (TicTacToeMove&)other;
	return mRow == move.mRow && mCol == move.mCol;
};

TicTacToeMove::operator string() const {
	ostringstream format; 
	format << "(" << mRow << "," << mCol << ")"; 
	return format.str(); // converts back to string
};
