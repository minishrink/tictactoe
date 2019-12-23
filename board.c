/**** INCLUDES ****/

#include "board.h"
#include "debug.h"
#include <stdbool.h>
#include <stdlib.h>

/**** DEFINES ****/

/**** PRIVATE FUNCTIONS ****/

bool validCell(CHAR row, CHAR col)  {
  if (!((row < BOARDLEN) && (col < BOARDLEN))) {
    printf("INVALID CELL(%d, %d)\n", col, row);
  }
  return (row < BOARDLEN) && (col < BOARDLEN);
}

char getSymbol(SymbolT sym) {
  char symbol = EMPTY;
  switch(sym) {
    case _CROSS:
      symbol = CROSS;
      break;
    case _NOUGHT:
      symbol = NOUGHT;
      break;
    case _EMPTY:
    default:
      break;
  }
  return symbol;
}

/**** PRINT FNS ****/

void printRow(RowT R) {
  for (int i = 0; i < BOARDLEN; i++)  {
    printf("| %c ", R[i]);
  }
  printf("|\n");
}

void printSep(int len)  {
  printf("----");
  for (int i = 0; i < 4*BOARDLEN; i++)  {
    printf("%c", EMPTY);
  }
  printf("\n");
}

void printHeader(int len) {
  printf("   ||");
  for (int i = 0; i < BOARDLEN; i++)  {
    // print column labels starting with A
    printf(" %c |", 65+i);
  }
  printf("\n");
}

/**** PUBLIC IMPLEMENTATIONS ***/

void printBoard(Board* b) {
  printHeader(BOARDLEN);
  printSep(BOARDLEN);
  for (int i = 0; i < BOARDLEN; i++)  {
    printf(" %d |", i+1);
    printRow(b->Grid[i]);
    printSep(BOARDLEN);
  }
}

char readCell(Board* b, CHAR col, CHAR row) {
  if (validCell(col, row)) {
    return b->Grid[col][row];
  }
  else  { // FIXME, fail here?
    return EMPTY;
  }
}

void writeToCell(Board* b, CHAR col, CHAR row, SymbolT symbol) {
  if (validCell(col, row) && (IS_EMPTY(b->Grid[col][row])))  {
    b->Grid[col][row] = getSymbol(symbol);
  }
  else  {
    DEBUGF("(%i, %i) : u fucked it\n", col, row);
  }
}

Board* initBoard() {
  Board* pBoard = (Board *)malloc(sizeof(Board));
  for (int i = 0; i < BOARDLEN; i++)  {
    for (int j = 0; j < BOARDLEN; j++)  {
      pBoard->Grid[i][j] = EMPTY;
    }
  }
  return pBoard;
}
