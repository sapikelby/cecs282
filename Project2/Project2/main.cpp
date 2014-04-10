#include "OthelloExceptions.h"
#include "OthelloBoard.h"
#include "OthelloView.h"
#include "OthelloMove.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {

	cout << "Othello Game" << endl;

	// Initialization
	OthelloBoard board; // the state of the game board
	OthelloView v(&board); // a View for outputting the board via operator<<
	string userInput; // a string to hold the user's command choice
	vector<OthelloMove *> possMoves; // a holder for possible moves

	/*
	cout << v;

	board.GetPossibleMoves(&possMoves); 
	cout << "after get poss moves" << endl;
	int i =0;

	vector<OthelloMove*>::iterator itr; 
	for (itr = possMoves.begin(); itr != possMoves.end();itr++) {
			cout << "------inside first for loop" << endl;
			cout << "" << *itr << endl;
			cout << i << endl;
	}

	for (OthelloMove* i : possMoves) { // "for each int called 'i' inside intList, do this"
		cout << (string)*i << " ";
		cout << "possible move" << endl;
	}
	cout << "after loops" << endl;
	
	*/
	
   
	   // Print the game board using the OthelloView object
		cout << v;
      //Prints out who turn it is
      cout << ((board.GetNextPlayer() == 1) ? "Black's " : "White's ") 
       << "turn \n";
      // Print all possible moves
		cout << "Possible moves:" << endl;
		board.GetPossibleMoves(&possMoves);
		
		for (int i = 0; i < possMoves.size(); i++) {
			OthelloMove itr = *possMoves.at(i);
			cout << (string)itr << endl;
			//delete(&possMoves.at(i));
			
		}
		
		//delete(&possMoves);

		//cout <<	possMoves.size() << endl;
		
		cout << "Applied move " << possMoves.at(0) << endl;
		board.ApplyMove(possMoves.at(0));

		cout << "value: " << board.GetValue() << endl; 
		//possMoves.clear();
		cout << v;
		/*
		cout << "Possible moves:" << endl;
		board.GetPossibleMoves(&possMoves);

		for (int i = 0; i < possMoves.size(); i++) {
			OthelloMove itr = *possMoves.at(i);
			cout << (string)itr << endl;
		}
		cout << ((board.GetNextPlayer() == 1) ? "Black's " : "White's ") 
       << "turn \n";
		cout << v;
		cout << "Applied move " << possMoves.at(1) << endl;
		board.ApplyMove(possMoves.at(4));
		cout << v;

		cout << "value: " << board.GetValue() << endl; 

		


		cout << endl;

		*/


		board.UndoLastMove();

		cout << v;

		cout << endl << board.GetValue();

		/*
		const vector<OthelloMove*> *history = board.GetMoveHistory();

		int count = 0;
		// use a reverse iterator
		for (vector<OthelloMove*>::const_iterator itr = history->begin(); itr != history->end();
			itr++) { // doesn't even fit on one line :(
				cout << "history (" << count++ << ")" << (string)**itr << endl;
		}
		// memory management 
		// delete from heap, then clear vector using clear function

		//cout << board.GetMoveHistory();
	/*
	// Main loop
	do {
		// Print the game board using the OthelloView object

		// Print all possible moves

		// Ask to input a command

		// Command loop:
		// move (r,c)
		// undo n
		// showValue
		// showHistory
		// quit

	} while (!board.IsFinished()); 

	*/
}
