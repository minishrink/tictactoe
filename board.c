/**** INCLUDES ****/

#include "board.h"
#include <stdio.h>
#include <stdbool.h>

/**** DEFINES ****/

/**** PRIVATE FUNCTIONS ****/

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

void printRow(RowT R) {
  // printf("    ");
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

bool validCell(CHAR row, CHAR col)  {
  if (!((row < BOARDLEN) && (col < BOARDLEN))) {
    printf("INVALID CELL(%d, %d)\n", col, row);
  }
  return (row < BOARDLEN) && (col < BOARDLEN);
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

char readCell(Board* b, CHAR row, CHAR col) {
  if (validCell(col, row)) {
    return b->Grid[col][row];
  }
  else  { // FIXME, fail here?
    return EMPTY;
  }
}

void writeToCell(Board* b, CHAR row, CHAR col, SymbolT symbol) {
  if (validCell(col, row) && (IS_EMPTY(b->Grid[col][row])))  {
    b->Grid[col][row] = getSymbol(symbol);
  }
  else  {
    printf("(%i, %i) : u fucked it\n", col, row);
  }
}

Board makeBoard() {
  Board b;
  for (int i = 0; i < BOARDLEN; i++)  {
    for (int j = 0; j < BOARDLEN; j++)  {
      b.Grid[i][j] = EMPTY;
    }
  }
  return b;
}
