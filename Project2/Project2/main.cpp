#include "OthelloExceptions.h"
#include "OthelloBoard.h"
#include "OthelloView.h"
#include "OthelloMove.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {


	cout << "--- Othello Game ---" << endl << endl;

	// Initialization
	//OthelloBoard board; // the state of the game board
	//OthelloView v(&board); // a View for outputting the board via operator<<
	//string userInput; // a string to hold the user's command choice
	//vector<OthelloMove *> possMoves; // a holder for possible moves

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

	/*
	// Print the game board using the OthelloView object
	cout << v;
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
	cout << v;
	cout << "Applied move " << possMoves.at(1) << endl;
	board.ApplyMove(possMoves.at(4));
	cout << v;

	cout << "value: " << board.GetValue() << endl; 




	cout << endl;




	board.UndoLastMove();

	cout << v;

	cout << endl << board.GetValue();

	board.ApplyMove(possMoves.at(0));

	cout << v;

	const vector<OthelloMove*> *history = board.GetMoveHistory();

	int count = 0;
	// use a reverse iterator
	for (vector<OthelloMove*>::const_reverse_iterator itr = history->rbegin(); itr != history->rend();
	itr++) { // doesn't even fit on one line :(
	cout << "inside iterator" << endl;
	cout << "history (" << count++ << ")" << (string)**itr << endl;
	}


	cout << "After history" << endl;

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
	*/


	// Initialization
	OthelloBoard board; // the state of the game board
	OthelloView v(&board); // a View for outputting the board via operator<<
	string userInput; // a string to hold the user's command choice
	vector<OthelloMove *> possMoves; // a holder for possible moves
	string temp;


	//
	vector<string> possStrings;

	//sort(possMoves.begin(), possMoves.end());

	//int i= 0;
	// Main loop
	do {
		// Print the game board using the OthelloView object
		cout << v;

		cout << (board.GetNextPlayer() == 1 ? "Black's turn: " : "White's turn:") 
			<< endl;
		// Print all possible moves
		board.GetPossibleMoves(&possMoves);


		for (int i = 0; i < possMoves.size(); i++) {
			OthelloMove itr = *possMoves.at(i);
			//cout << (string)itr << " ";
			possStrings.push_back(string(itr));  // pushes string rep. of move onto string vector
		}

		cout << endl << endl;

		sort(possStrings.begin(), possStrings.end());

		for (int i = 0; i < possStrings.size(); i++) {
			string itr = possStrings.at(i);
			cout << itr << " ";
		}

		cout << endl << endl;

		// Ask to input a command
		cout << "Enter a command: " << endl;
		getline(cin, userInput);

		try {

			OthelloException exc("Invalid move");
			bool validMove = false;


			// Command loop

			// move (r,c)
			if (userInput.find("move") != string::npos) {
				istringstream moveInput(userInput);

				moveInput >> temp >> temp;

				//temp = userInput.substr(5,8);
				//cout << temp << endl;
				OthelloMove *move = board.CreateMove();
				*move = temp;  // overloading =


				char tempChar; // comma and parantheses in move

				istringstream getMove(temp);
				int row = 0, col = 0;
				getMove >> tempChar >> row >> tempChar >> col >> tempChar;
				//cout << row << "," << col << endl;

				//cout << "Move: " << (string)*move << endl;
				// check for inbounds 
				//move (3,2)
				//int row = stoi(userInput.substr(6,1));
				//int col = stoi(userInput.substr(8,1));
				//char tempVar;
				//cout << row << "," << col << endl;

				try {
					/*
					if (move->IsPass()) { // only allow to pass when no moves available
					//cout << "pass" << endl;
					if (possMoves.empty()) {
					cout << (string)*move << endl;
					board.ApplyMove(move);
					validMove = true;
					}
					}
					*/
					if (board.InBounds(row, col) || move->IsPass()) {
						//cout << "if" << endl;
						for (OthelloMove* i : possMoves) { // "for each int called 'i' inside intList, do this"
							cout << (string)*i << " ";
							//cout << "possible move" << endl;
							if(*i == *move) {
								//cout << "valid move" << endl;
								board.ApplyMove(move);
								validMove = true;
							}
						}


						if(!validMove) {
							//cout << "throws exception" << endl;
							throw exc;
						}


					}
					else {
						throw exc; 
					}
				}

				catch (OthelloException &exc) {
					cout << exc.GetMessage() << endl << endl;
					delete(move); // delete invalid move
				}
			}

			// undo n
			else if (userInput.find("undo") != string::npos) {
				int numUndos = 0;
				istringstream input(userInput);

				// "undo 130" == userInput
				input >> temp >> numUndos;

				while (numUndos > 0)
				{
					board.UndoLastMove();
					numUndos--;
				}
			}

			// showValue
			else if (userInput.find("showValue") != string::npos) {
				cout << "Board value: " << board.GetValue() << endl;
			}

			// showHistory
			else if (userInput.find("showHistory") != string::npos) {
				const vector<OthelloMove*> *history = board.GetMoveHistory();
				int player = -board.GetNextPlayer();

				for (vector<OthelloMove*>::const_reverse_iterator itr = 
					history->rbegin(); itr != history->rend(); itr++) {
						cout << (player == 1 ? "Black's turn: ":"White's turn: ") 
							<< string(**itr) << endl;
						player = -player;
				}

			}

			// quit
			else if (userInput.find("quit") != string::npos) {
				break;
			}

			else {
				throw OthelloException("Invalid command, try again");
			}
		}

		catch (OthelloException &exc) {
			cout << exc.GetMessage() << endl;
		}


		// finally, delete from heap and clear possMoves
		for (int i = 0; i < possMoves.size(); i++) {
			OthelloMove* ptr = possMoves.at(i);
			delete(ptr);
		}

		possMoves.clear();
		possStrings.clear();


	} while (!board.IsFinished());

	cout << ((board.GetValue() == 0) ? "Tied game" : 
		(board.GetValue() > 0) ? "Black wins!" : "White wins!") << endl;

}
