/***** INCLUDES *****/

#include "game.h"

/**** DEFINES ***/

#define MOVELEN (2u)
#define HDRSTART (65u)
#define HDREND (HDRSTART + BOARDLEN)

/***** PRIVATE IMPLEMENTATION *****/

/* FIXME This function is not generalisable at all */
Move parseMove(char m[MOVELEN], SymbolT Piece)  {
  Move mv;
  mv.Piece = Piece;
  if (HDRSTART <= (CHAR) m[0] && (CHAR) m[0] < HDREND) {
    mv.Col = (CHAR) m[0] - (CHAR)HDRSTART;
    printf("Column %c = %d\n", m[0], mv.Col);
  }
  if (m[1] < BOARDLEN) {
    mv.Row = ((CHAR) (m[1])) - (CHAR) 1u;
    printf("Row %c = %d\n", m[0], mv.Row);
  }
  return mv;
}

void move(Board* b, char m[MOVELEN], SymbolT Piece) {
  Move mv = parseMove(m, Piece);
  writeToCell(b, mv.Col, mv.Row, Piece);
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
