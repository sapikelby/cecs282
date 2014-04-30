// ----------- Kelby Sapien 
// ----------- Project 3
// ----------- CECS 282

#include "GameBoard.h"
#include "OthelloBoard.h";
#include "TicTacToeBoard.h"
#include "GameView.h"
#include "OthelloView.h"
#include "TicTacToeView.h"
#include "GameMove.h"
#include "OthelloMove.h"
#include "TicTacToeMove.h"
#include "GameExceptions.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>


using namespace std;

int main(int argc, char* argv[]) {

	//map <string, char> list;

	GameBoard *board;
	GameView *v;
	char choice;
	cout << "-- Othello or Tic Tac Toe --" << endl;
	cout << "What game do you want to play? \n1) Othello \n2) Tic Tac Toe" 
		<< endl;
	cin >> choice;
	cin.ignore();

	if (choice == '1') {
		
		board = new OthelloBoard();
		v = new OthelloView(board);
		string userInput = "";
		string temp;
		vector<GameMove *> possMoves; 
		vector<string> possStrings;


		//cout << *v << endl;


		cout << "--- Othello Game ---" << endl << endl;
		/*
		// Initialization
		OthelloBoard board; // the state of the game board
		OthelloView v(&board); // a View for outputting the board via operator<<
		string userInput; // a string to hold the user's command choice
		vector<OthelloMove *> possMoves; // a holder for possible moves
		string temp;
		vector<string> possStrings;
		*/

		// Main loop
		do {
			
			// Print the game board using the OthelloView object
			cout << *v << endl;

			//cout << (board->GetNextPlayer() == 1 ? "Black's turn: " : "White's turn:") 
			//	<< endl;
			cout << board->GetPlayerString(board->GetNextPlayer()) << "'s turn:" 
				<< endl;
			// Print all possible moves
			board->GetPossibleMoves(&possMoves);

			for (int i = 0; i < possMoves.size(); i++) {
				GameMove* itr = possMoves.at(i);
				possStrings.push_back(string(*itr));  // pushes string rep. of move onto string vector
			}

			cout << endl << endl;

			sort(possStrings.begin(), possStrings.end());

			for (int i = 0; i < possStrings.size(); i++) {
				string itr = possStrings.at(i);
				cout << itr << " ";
			}

			cout << endl;
			//cin.clear();
			//cin.ignore(INT_MAX,'\n'); 
			//cout.flush();
			// Ask to input a command
			cout << "Enter a command: " << endl;
			getline(cin, userInput);
			cout << endl;

			try {

				GameException exc("Invalid move");
				bool validMove = false;
				// Command loop

				// move (r,c)
				if (userInput.find("move") != string::npos) {
					istringstream moveInput(userInput);

					moveInput >> temp >> temp;
					OthelloMove *move = (OthelloMove*)board->CreateMove();
					*move = temp;  // overloading =


					char tempChar; // comma and parantheses in move

					istringstream getMove(temp);
					int row = 0, col = 0;
					getMove >> tempChar >> row >> tempChar >> col >> tempChar;

					try {
						bool yes = true;
						if (yes/*OthelloBoard)board->InBounds(row, col) || move->IsPass()*/) {
							for (GameMove* i : possMoves) { //"for each int called 'i' inside intList, do this"
								cout << (string)*i << " ";
								if(*i == *move) {
									board->ApplyMove(move);
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

					catch (GameException &exc) {
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
						board->UndoLastMove();
						numUndos--;
					}
				}

				// showValue
				else if (userInput.find("showValue") != string::npos) {
					cout << "Board value: " << board->GetValue() << endl;
				}

				// showHistory
				else if (userInput.find("showHistory") != string::npos) {
					const vector<GameMove*> *history = board->GetMoveHistory();
					int player = -board->GetNextPlayer();

					for (vector<GameMove*>::const_reverse_iterator itr = 
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
					throw GameException("Invalid command, try again");
				}
			}

			catch (GameException &exc) {
				cout << "Throwing exception" << endl;
				cout << exc.GetMessage() << endl;
			}


			// finally, delete from heap and clear possMoves
			for (int i = 0; i < possMoves.size(); i++) {
				GameMove* ptr = possMoves.at(i);
				delete(ptr);
			}

			possMoves.clear();
			possStrings.clear();

			//cin.clear();
			//cin.ignore(INT_MAX,'\n'); 

		} while (!board->IsFinished());

		cout << ((board->GetValue() == 0) ? "Tied game" : 
			(board->GetValue() > 0) ? "Black wins!" : "White wins!") << endl;
		
	}

	else {
		cout << "Tic Tac Toe" << endl;

		board = new TicTacToeBoard();
		v = new TicTacToeView(board);
		string userInput = "";
		string temp;
		vector<GameMove *> possMoves; 
		vector<string> possStrings;

		// Main loop
		do {

			// Print the game board using the OthelloView object
			cout << *v << endl;

			//cout << (board->GetNextPlayer() == 1 ? "Black's turn: " : "White's turn:") 
			//	<< endl;
			cout << board->GetPlayerString(board->GetNextPlayer()) << "'s turn:" 
				<< endl;
			// Print all possible moves
			board->GetPossibleMoves(&possMoves);

			for (int i = 0; i < possMoves.size(); i++) {
				GameMove* itr = possMoves.at(i);
				possStrings.push_back(string(*itr));  // pushes string rep. of move onto string vector
			}

			cout << endl << endl;

			sort(possStrings.begin(), possStrings.end());

			for (int i = 0; i < possStrings.size(); i++) {
				string itr = possStrings.at(i);
				cout << itr << " ";
			}

			cout << endl;
			//cin.clear();
			//cin.ignore(INT_MAX,'\n'); 
			//cout.flush();
			// Ask to input a command
			cout << "Enter a command: " << endl;
			getline(cin, userInput);
			cout << endl;

			try {

				GameException exc("Invalid move");
				bool validMove = false;
				// Command loop

				// move (r,c)
				if (userInput.find("move") != string::npos) {
					istringstream moveInput(userInput);

					moveInput >> temp >> temp;
					TicTacToeMove *move = (TicTacToeMove*)board->CreateMove();
					*move = temp;  // overloading =


					char tempChar; // comma and parantheses in move

					istringstream getMove(temp);
					int row = 0, col = 0;
					getMove >> tempChar >> row >> tempChar >> col >> tempChar;

					try {
						bool yes = true;
						if (yes/*OthelloBoard)board->InBounds(row, col) || move->IsPass()*/) {
							for (GameMove* i : possMoves) { //"for each int called 'i' inside intList, do this"
								cout << (string)*i << " ";
								if(*i == *move) {
									board->ApplyMove(move);
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

					catch (GameException &exc) {
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
						board->UndoLastMove();
						numUndos--;
					}
				}

				// showValue
				else if (userInput.find("showValue") != string::npos) {
					cout << "Board value: " << board->GetValue() << endl;
				}

				// showHistory
				else if (userInput.find("showHistory") != string::npos) {
					const vector<GameMove*> *history = board->GetMoveHistory();
					int player = -board->GetNextPlayer();

					for (vector<GameMove*>::const_reverse_iterator itr = 
						history->rbegin(); itr != history->rend(); itr++) {
							//cout << (player == 1 ? "Black's turn: ":"White's turn: ") 
							//	<< string(**itr) << endl;
							cout << board->GetPlayerString(player) << "'s turn:" 
								<< string(**itr) << endl;
							player = -player;
					}

				}

				// quit
				else if (userInput.find("quit") != string::npos) {
					break;
				}

				else {
					throw GameException("Invalid command, try again");
				}
			}

			catch (GameException &exc) {
				//cout << "Throwing exception" << endl;
				cout << exc.GetMessage() << endl;
			}


			// finally, delete from heap and clear possMoves
			for (int i = 0; i < possMoves.size(); i++) {
				GameMove* ptr = possMoves.at(i);
				delete(ptr);
			}

			possMoves.clear();
			possStrings.clear();

			//cin.clear();
			//cin.ignore(INT_MAX,'\n'); 

		} while (!board->IsFinished());

		cout << ((board->GetValue() == 0) ? "Tied game" : 
			(board->GetValue() > 0) ? "X wins!" : "O wins!") << endl;

	}

	return 0;
};