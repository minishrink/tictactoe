/***** INCLUDES *****/

#include "game.h"

/**** DEFINES ***/

/***** PRIVATE IMPLEMENTATION *****/

/****** PUBLIC FUNCTIONS *****/

Player* initPlayer(const CHAR* name, SymbolT sym)  {
  MALLOC(Player, p);
  p->Name  = name;
  p->Piece = sym;
  return p;
}

Game* initGame(const char* p1, const char* p2) {
  MALLOC(Game, g);
  g->state = NOT_STARTED;
  g->turns = 0u;
  g->players[0] = *initPlayer((const CHAR*) p1, _CROSS);
  g->players[1] = *initPlayer((const CHAR*) p2, _NOUGHT);
  return g;
}

Player* initPlayer(CHAR* name, SymbolT sym)  {
  MALLOC(Player, p);
  p->Name   = name;
  p->Symbol = getSymbol(sym);
  return p;
}
