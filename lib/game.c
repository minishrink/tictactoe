/***** INCLUDES *****/

#include "game.h"
#include "helpers.h"

/**** DEFINES ***/

/***** PRIVATE IMPLEMENTATION *****/

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
