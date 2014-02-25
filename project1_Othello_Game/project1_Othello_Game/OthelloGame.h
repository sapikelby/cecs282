#define BOARD_SIZE 8
//const int BOARD_SIZE = 8; 
/*
PrintBoard: this function takes the game board array as a parameter and prints it to the screen.
First, print a header row of the numbers 0 through 7 with spaces inbetween, showing the indices of
each column. Then print one row of the board at a time: start with the row index, then print: a
period if the space is empty; a B if the black player has a piece there; a W for a white piece. Example
for the initial board setup:

- 0 1 2 3 4 5 6 7
0 . . . . . . . .
1 . . . . . . . .
2 . . . . . . . .
3 . . . W B . . .
4 . . . B W . . .
5 . . . . . . . .
6 . . . . . . . .
7 . . . . . . . .
*/
void PrintBoard(char board[BOARD_SIZE][BOARD_SIZE]);


/*
 GetMove: this function uses cin to read a line of input from the user representing their move, in the
format (row, col) ; then parses the line and returns a row and column from the function. Since the
function needs to return two pieces of information, it will need to take pointer parameters from the
main, and then dereference those pointers to store the information read from cin. This function should
not output anything; the main is responsible for asking the user to type in a move.
*/
void GetMove(int *row, int *column);

/*
 InBounds: this function takes a row and column, and returns true if the position specied is in bounds
of the board: that is, if both are at least 0 and less than the size of the board.
*/
bool InBounds(int row, int column);

/*
 IsValidMove: this function takes the game board, and integer values for a row and column that
the player would like to move to. This function only checks that the destination is in-bounds (use
InBounds) and does not have a piece already at the location; OR alternatively, if the move is a pass
(both row and column are -1). This function does not check to make sure the player will actually
surround enemy pieces with the move.
*/
bool IsValidMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int column);
/*
 ApplyMove: this is the hardest function and contains the bulk of the game logic. Given a game board
array, a row, a column, and the current player, this function applies the move requested by the current
player by turning the requested square to the player's color, and then searches all eight directions
from that square looking to see if there is a run of the opponent's pieces to ip according to the game
rules. Because you can't count on the user moving to a specic game location, you must use loops to
iterate through all 8 directions and continue moving in each direction looking for a run of enemy pieces.
*/
void ApplyMove(char board[BOARD_SIZE][BOARD_SIZE], int row, int column, bool playerBlack);



int GetValue(char board[BOARD_SIZE][BOARD_SIZE]);
/*
GetValue: given the boared, this function returns an integer for the value of the board.
*/