#include "OthelloView.h"
#include <string>
#include <sstream>
using namespace std;


void OthelloView::PrintBoard(ostream &s) const
{
	string strBoard = "";
	
	s << "- 0 1 2 3 4 5 6 7" << endl;
	for (int i=0; i<BOARD_SIZE; i++) {
		cout << i << "";
		for (int j=0; j<BOARD_SIZE; j++) {
			if (mOthelloBoard->mBoard[i][j] == 0) {
				strBoard =  strBoard + " .";
			}
			else if (mOthelloBoard->mBoard[i][j] == 1) {
				strBoard =  strBoard + " B";
			} 
			else {
				strBoard =  strBoard + " W";
			}
		}
		s << strBoard << "\n";
		strBoard = "";
	}
};



