// ----------- Kelby Sapien 
// ----------- Project 2
// ----------- CECS 282

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
	OthelloBoard board; // the state of the game board
	OthelloView v(&board); // a View for outputting the board via operator<<
	string userInput; // a string to hold the user's command choice
	vector<OthelloMove *> possMoves; // a holder for possible moves
	string temp;
	vector<string> possStrings;

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
				OthelloMove *move = board.CreateMove();
				*move = temp;  // overloading =


				char tempChar; // comma and parantheses in move

				istringstream getMove(temp);
				int row = 0, col = 0;
				getMove >> tempChar >> row >> tempChar >> col >> tempChar;

				try {
					
					if (board.InBounds(row, col) || move->IsPass()) {
						for (OthelloMove* i : possMoves) { //"for each int called 'i' inside intList, do this"
							cout << (string)*i << " ";
							if(*i == *move) {
								board.ApplyMove(move);
								validMove = true;
							}
						}

						if(!validMove) {
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
