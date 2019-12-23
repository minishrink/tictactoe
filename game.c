/***** INCLUDES *****/

#include "game.h"
#include "debug.h"
#include <stdlib.h>

/**** DEFINES ***/

#define MOVELEN (2u)
#define HDRSTART (65u)
#define HDREND (HDRSTART + BOARDLEN)

/***** PRIVATE IMPLEMENTATION *****/

/* FIXME This function is not generalisable at all */
Move* parseMove(char m[MOVELEN], SymbolT Piece)  {
  Move *pMove = (Move *)malloc(sizeof(Move));
  pMove->Piece = Piece;
  if (HDRSTART <= (CHAR) m[0] && (CHAR) m[0] < HDREND) {
    pMove->Col = (CHAR) m[0] - (CHAR)HDRSTART;
    DEBUGF("Column %c = %d\n", m[0], pMove->Col);
  }
  if (m[1] < BOARDLEN) {
    pMove->Row = ((CHAR) (m[1])) - (CHAR) 1u;
    DEBUGF("Row %c = %d\n", m[0], pMove->Row);
  }
  return pMove;
}

void move(Board* b, char m[MOVELEN], SymbolT Piece) {
  Move* pMove = parseMove(m, Piece);
  writeToCell(b, pMove->Col, pMove->Row, Piece);
}

/****** PUBLIC FUNCTIONS *****/

Game makeGame(void) {
  Game g;
  g.state = NOT_STARTED;
  return g;
}

Player makePlayer(char* name, SymbolT sym)  {
  Player p;
  p.Name   = name;
  p.Symbol = getSymbol(sym);
  return p;
}
