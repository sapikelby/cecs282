#include "OthelloMove.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int OthelloMove::mOutstanding = 0;

OthelloMove::OthelloMove() : mRow(-1), mCol(-1) {
};

OthelloMove::OthelloMove(int row, int col) : mRow(row), mCol(col) {
};

OthelloMove::OthelloMove(const OthelloMove& move) : mRow(move.mRow), 
	mCol(move.mCol) {
};

GameMove& OthelloMove::operator=(const string& strMove) {
	istringstream is(strMove); 
	char temp;
	if (strMove.compare("pass") == 0) {
		mRow = -1; 
		mCol = -1;
	}
	else {
		is >> temp >> mRow >> temp >> mCol >> temp; 
	}
	return *this;

};

// ADD: an assignment operator taking a const OthelloMove& object.
OthelloMove& OthelloMove::operator=(const OthelloMove& otherMove)
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
bool OthelloMove::Equals(const GameMove& other) const {
	OthelloMove& move = (OthelloMove&)other;
	return mRow == move.mRow && mCol == move.mCol;
};

OthelloMove::operator string() const {
	ostringstream format; 
	IsPass() ? format << "pass" : format << "(" << mRow << "," << mCol << ")"; 
	return format.str(); // converts back to string
};
