#ifndef __TICTACTOEMOVE_H
#define __TICTACTOEMOVE_H
#include "GameMove.h"
#include <string>
#include <vector>
#include <iostream>
/*
An OthelloMove encapsulates a single potential move on an OthelloBoard. It
is represented internally by a row and column, both 0-based.
*/
class TicTacToeMove : public GameMove {
private:
   // OthelloBoard is a friend so it can access mRow and mCol.
	friend class TicTacToeBoard;
   
   int mRow, mCol;


   // KEEP THESE CONSTRUCTORS PRIVATE.
   TicTacToeMove();
   /*
   2-parameter constructor: initializes this move with the given 
   row and column.
   */
   TicTacToeMove(int row, int col);
   
   static int mOutstanding;


public:
/*
   static void* operator new(std::size_t sz) {
      mOutstanding++;
      std::cout << "operator new: " << mOutstanding << " moves outstanding" << std::endl;
      return ::operator new(sz);
   }

   static void operator delete(void* ptr, std::size_t sz) {
      mOutstanding--;
      std::cout << "operator delete: " << mOutstanding << " moves oustanding" << std::endl;
      ::operator delete(ptr);
   }*/
   virtual ~TicTacToeMove() {};

   TicTacToeMove(const TicTacToeMove &);
   TicTacToeMove& operator=(const TicTacToeMove &rhs);

   /*
   This assignment operator takes a string representation of an Othellomove
   and uses it to initialize the move. The string is in the format
   (r, c); OR is the string "pass". [The user will not enter (-1,-1) to pass
   anymore.]
   */
	virtual GameMove& operator=(const std::string &);

   /*
   Compares two OthelloMove objects for equality.
   */
   virtual bool Equals(const GameMove &other) const;
   
   // Converts the OthelloMove into a string representation, one that could be
   // used correctly with operator=(string). Returns "pass" if move is a pass.
	operator std::string() const;

   virtual GameMove *Clone() const {
      return new TicTacToeMove(*this);
   }
};

//int OthelloMove::mOutstanding = 0;
#endif