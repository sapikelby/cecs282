#include "OthelloMove.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int OthelloMove::mOutstanding = 0;

OthelloMove::OthelloMove() : mRow(-1), mCol(-1) {
	//mRow = -1; 
	//mCol = -1; 
	//cout << "Constructed move" << endl;
};

OthelloMove::OthelloMove(int row, int col) : mRow(row), mCol(col) {
	//mRow = row; 
	//mCol = col;
	//cout << "constructed move with parameters" << endl;
};

OthelloMove::OthelloMove(const OthelloMove& move) : mRow(move.mRow), 
	mCol(move.mCol) {
		//cout << "copy constructed move";
};
	
OthelloMove& OthelloMove::operator=(const string& strMove) {
	istringstream is(strMove); 
	char temp;
	if(strMove.compare("pass") == 0) {
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
	if(this == &otherMove) {
		return *this;
	}
	
	//cout << "Operator ="; 
	mRow = otherMove.mRow; 
	mCol = otherMove.mCol; 
	return *this;
};

bool operator==(const OthelloMove &lhs, const OthelloMove &rhs) {
	return lhs.mRow == rhs.mRow && lhs.mCol == rhs.mCol; 
};

OthelloMove::operator string() const {
	ostringstream format; 
	IsPass() ? format << "pass" : format << "(" << mRow << "," << mCol << ")"; 
	return format.str(); // converts back to string
};
