/***** INCLUDES *****/

#include "game.h"
#include "helpers.h"

/**** DEFINES ***/

#define MOVELEN   (2u)
#define NUMOFFSET (49u)
#define HDRSTART  (65u)
#define HDREND    (HDRSTART + BOARDLEN)

/***** PRIVATE IMPLEMENTATION *****/

/* FIXME This function is not generalisable at all */
Move* parseMove(CHAR m[MOVELEN], SymbolT Piece)  {
  CHAR col = m[0];
  CHAR row = m[1];
  // DEBUGF("Move: %s -> (Col: %d, Row: %d)\n", m, row, col);
  MALLOC(Move, pMove);
  pMove->Piece = Piece;
  if (BETWEEN(HDRSTART, col, HDREND))  {
    // convert letter to column index
    col       -= (CHAR) HDRSTART;
    pMove->Col = col;
  }
  // convert CHAR to row index
  if (BETWEEN(0u, row, BOARDLEN + NUMOFFSET)) {
    row       -= (CHAR) NUMOFFSET;
    pMove->Row = row;
  }
  DEBUGF("Move: %s -> (Row: %d, Col: %d)\n", m, pMove->Row, pMove->Col);
  return pMove;
}

void move(Board* b, CHAR m[MOVELEN], SymbolT Piece) {
  Move* pMove = parseMove(m, Piece);
  writeToCell(b, pMove->Row, pMove->Col, Piece);
}

/****** PUBLIC FUNCTIONS *****/

Game* initGame(void) {
  MALLOC(Game, g);
  g->state = NOT_STARTED;
  return g;
}

Player* initPlayer(CHAR* name, SymbolT sym)  {
  MALLOC(Player, p);
  p->Name   = name;
  p->Symbol = getSymbol(sym);
  return p;
}
