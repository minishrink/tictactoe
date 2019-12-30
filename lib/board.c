/**** INCLUDES ****/

#include "board.h"

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
      DEBUGF("ERROR: getSymbol(%d) = %c??\n", sym, sym);
      return EMPTY;
      break;
  }
}

bool validCell(CHAR row, CHAR col)  {
  if (!((row < BOARDLEN) && (col < BOARDLEN))) {
    DEBUGF("ERROR: invalid cell(%d, %d)\n", row, col);
  }
  return (row < BOARDLEN) && (col < BOARDLEN);
}

bool validMove(CHAR m[MOVELEN]) {
  CHAR col = m[0];
  CHAR row = m[1];
  return ((BETWEEN(HDRSTART, col, HDREND))
      && (BETWEEN(0u, row, BOARDLEN + NUMOFFSET)));
}

/* FIXME This function is not generalisable at all */
Move* initMove(CHAR m[MOVELEN])  {
    CHAR col = m[0];
    CHAR row = m[1];
    MALLOC(Move, pMove);
    if (validMove(m)) {
      // convert letter to column index
      col       -= (CHAR) HDRSTART;
      // convert CHAR to row index
      row       -= (CHAR) NUMOFFSET;
      // initialise Move*
      pMove->Col = col;
      pMove->Row = row;
    }
  else  {
    DEBUGF("ERROR: %s out of bounds\n", m);
  }
  return pMove;
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
    DEBUGF("ERROR: cannot write to cell (%d, %d)\n", row, col);
  }
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
  printf("\n");
  printSep(BOARDLEN);
  printHeader(BOARDLEN);
  printSep(BOARDLEN);
  for (int i = 0; i < BOARDLEN; i++)  {
    printf("| %d ", i+1);
    printRow(b->Grid[i]);
    printSep(BOARDLEN);
  }
  printf("\n");
}


Board* initBoard(void) {
  MALLOC(Board, pBoard);
  for (int i = 0; i < BOARDLEN; i++)  {
    for (int j = 0; j < BOARDLEN; j++)  {
      pBoard->Grid[i][j] = EMPTY;
    }
  }
  return pBoard;
}

void placePiece(Board* b, CHAR m[MOVELEN], SymbolT Piece) {
  if (validMove(m)) {
    Move* pMove = initMove(m);
    pMove->Piece = Piece;
    writeToCell(b, pMove->Row, pMove->Col, Piece);
  }
  else  {
    DEBUGF("ERROR: %s is an invalid move\n", m);
  }
}

