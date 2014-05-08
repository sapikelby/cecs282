// ----------- Kelby Sapien 
// ----------- Project 3
// ----------- CECS 282

#include "GameBoard.h"
#include "OthelloBoard.h"
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

	// initialization of game pointers
	GameBoard *board; 
	//GameBoard *board2 = new GameBoard();  // can't instantiate an abstract class
	GameView *v;
	GameMove *move;

	char choice;
	cout << "-- Othello or Tic Tac Toe --" << endl;
	cout << "What game do you want to play? \n1) Othello \n2) Tic Tac Toe" 
		<< endl;
	cin >> choice;
	cin.ignore();


	string userInput = "";
	string temp;
	vector<GameMove *> possMoves; 
	vector<string> possStrings;

	if (choice == '1') {
		cout << "Othello " << endl;
		board = new OthelloBoard();
		v = new OthelloView(board);
		move = (OthelloMove*)board->CreateMove();
	}

	else {
		cout << "Tic Tac Toe" << endl;

		board = new TicTacToeBoard();
		v = new TicTacToeView(board);
		move = (TicTacToeMove*)board->CreateMove();

	}

		// Main loop
		do {
			
			// Print the game board using the OthelloView object
			cout << *v << endl;

			cout << board->GetPlayerString(board->GetNextPlayer()) << "'s turn:" 
				<< endl;
			// Print all possible moves
			board->GetPossibleMoves(&possMoves);

			for (int i = 0; i < possMoves.size(); i++) {
				GameMove* itr = possMoves.at(i);
				// pushes string rep. of move onto string vector
				possStrings.push_back(string(*itr));  
			}

			cout << endl;
			sort(possStrings.begin(), possStrings.end());

			for (int i = 0; i < possStrings.size(); i++) {
				string itr = possStrings.at(i);
				cout << itr << " ";
			}

			cout << endl;
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

					// create new pointer based on game (gets pushed to history vector)
					if(choice == 1) { 
						move = (OthelloMove*)board->CreateMove();
					}
					else {
						move = (TicTacToeMove*)board->CreateMove();
					}

					*move = temp;  // overloading =

					char tempChar; // comma and parantheses in move

					istringstream getMove(temp);
					int row = 0, col = 0;
					getMove >> tempChar >> row >> tempChar >> col >> tempChar;

					try {

						for (GameMove* i : possMoves) { 
							//cout << (string)*i << " ";
							// check and apply move if allowed move
							if (move->Equals(*i)) {
								board->ApplyMove(move);
								validMove = true;
							}
						}

						if(!validMove) {
							throw exc;
						}
					}

					catch (GameException &exc) {
						cout << exc.GetMessage() << endl << endl;
						delete(move); // delete invalid move from heap
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
							string plyrStr = ((player == 1) ? board->GetPlayerString(1): 
								board->GetPlayerString(-1));
							cout << plyrStr << " " << string(**itr) << endl;
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

			 //display board for the last time if game over
			if(board->IsFinished()) {
				cout << *v << endl;
			}

		} while (!board->IsFinished());

		string winner = ((board->GetValue() > 0) ? board->GetPlayerString(1) : 
			board->GetPlayerString(-1));
		cout << ((board->GetValue() == 0) ? "Tied game" : 
			(board->GetValue() > 0) ? winner +  " wins" : winner + " wins") 
			<<  endl;


		delete v;
		delete board;
		delete move;

};