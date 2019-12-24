/**** INCLUDES ****/

#include "board.h"
#include "helpers.h"
#include <stdbool.h>
#include <stdlib.h>

/**** DEFINES ****/
const CHAR CROSS  = 'X';
const CHAR NOUGHT = 'O';
const CHAR EMPTY  = '-';

/**** PRIVATE FUNCTIONS ****/

const CHAR getSymbol(SymbolT sym) {
  switch(sym) {
    case _CROSS:
      return CROSS;
      break;
    case _NOUGHT:
      return NOUGHT;
      break;
    default:
      DEBUGF("getSymbol(%d) = %c??\n", sym, sym);
      return EMPTY;
      break;
  }
}

bool validCell(CHAR row, CHAR col)  {
  if (!((row < BOARDLEN) && (col < BOARDLEN))) {
    DEBUGF("INVALID CELL(%d, %d)\n", row, col);
  }
  return (row < BOARDLEN) && (col < BOARDLEN);
}

/**** PRINT FNS ****/

void printRow(RowT R) {
  for (int i = 0; i < BOARDLEN; i++)  {
    printf("| %c ", R[i]);
  }
  printf("|\n");
}

void printSep(int len) {
  printf("----");
  for (int i = 0; i < 4*BOARDLEN; i++)  {
    printf("%c", EMPTY);
  }
  printf("-\n");
}

void printHeader(int len) {
  printf("|   |");
  for (int i = 0; i < BOARDLEN; i++)  {
    // print column labels starting with A
    printf(" %c |", 65+i);
  }
  printf("\n");
}

/**** PUBLIC IMPLEMENTATIONS ***/

void printBoard(Board* b) {
  printSep(BOARDLEN);
  printHeader(BOARDLEN);
  printSep(BOARDLEN);
  for (int i = 0; i < BOARDLEN; i++)  {
    printf("| %d ", i+1);
    printRow(b->Grid[i]);
    printSep(BOARDLEN);
  }
}

CHAR readCell(Board* b, CHAR row, CHAR col) {
  if (validCell(row, col)) {
    return b->Grid[col][row];
  }
  else  { // FIXME, fail here?
    DEBUGF("\nERROR: cannot read cell (%d, %d)\n", row, col);
    return EMPTY;
  }
}

void writeToCell(Board* b, CHAR row, CHAR col, SymbolT symbol) {
  if (validCell(row, col) && (IS_EMPTY(b->Grid[row][col])))  {
    b->Grid[row][col] = getSymbol(symbol);
  }
  else  {
    DEBUGF("invalid cell, cannot write to (%i, %i)\n", row, col);
    DEBUGF("read(%d, %d) = %c\n", row, col, readCell(b, row, col));
  }
}

Board* initBoard() {
  MALLOC(Board, pBoard);
  for (int i = 0; i < BOARDLEN; i++)  {
    for (int j = 0; j < BOARDLEN; j++)  {
      pBoard->Grid[i][j] = EMPTY;
    }
  }
  return pBoard;
}
