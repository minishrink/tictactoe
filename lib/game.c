/***** INCLUDES *****/

#include "game.h"
#include "helpers.h"
#include <stdlib.h>

/**** DEFINES ***/

#define MOVELEN   (2u)
#define HDRSTART  (65u)
#define HDREND    (HDRSTART + BOARDLEN)
#define NUMOFFSET (49u)

/***** PRIVATE IMPLEMENTATION *****/

/* FIXME This function is not generalisable at all */
Move* parseMove(char m[MOVELEN], SymbolT Piece)  {
  MALLOC(Move, pMove);
  CHAR col, row;
  pMove->Piece = Piece;
  if (HDRSTART <= (CHAR) m[0] && (CHAR) m[0] < HDREND) {
    // convert letter to column index
    col = m[0] - HDRSTART;
    pMove->Col = col;
  }
  // convert char to row index
  row = m[1] - NUMOFFSET;
  if (row < BOARDLEN) {
    pMove->Row = row;
  }
  DEBUGF("Move: %s -> (Col: %d, Row: %d)\n", m, pMove->Col, pMove->Row);
  return pMove;
}

void move(Board* b, char m[MOVELEN], SymbolT Piece) {
  Move* pMove = parseMove(m, Piece);
  writeToCell(b, pMove->Col, pMove->Row, Piece);
}

/****** PUBLIC FUNCTIONS *****/

Game* initGame(void) {
  MALLOC(Game, g);
  g->state = NOT_STARTED;
  return g;
}

Player* initPlayer(char* name, SymbolT sym)  {
  MALLOC(Player, p);
  p->Name   = name;
  p->Symbol = getSymbol(sym);
  return p;
}
