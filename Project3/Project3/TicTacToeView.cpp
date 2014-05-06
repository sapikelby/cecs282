#include "TicTacToeView.h"
#include <string>
#include <sstream>
using namespace std;

void TicTacToeView::PrintBoard(ostream &s) const
{
	string strBoard = "";

	s << "- 0 1 2"  << endl;
	for (int i=0; i<BOARD2_SIZE; i++) {
		cout << i << "";
		for (int j=0; j<BOARD2_SIZE; j++) {
			if (mTicTacToeBoard->mBoard[i][j] == 0) {
				strBoard =  strBoard + " .";
			}
			else if (mTicTacToeBoard->mBoard[i][j] == 1) {
				strBoard =  strBoard + " X";
			} 
			else {
				strBoard =  strBoard + " O";
			}
		}
		s << strBoard << "\n";
		strBoard = "";
	}
};



