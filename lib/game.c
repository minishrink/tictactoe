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

void beginGame(Game* g) {
  g->board = initBoard();
  g->state = IN_PROGRESS;
}

void updateState(Game* g) {
}

void move(Game* g, Player* p, CHAR moveStr[MOVELEN])  {
  placePiece(g->board, moveStr, p->Piece);
}

void turn(Game* g, CHAR moveStr[MOVELEN])  {
  Player* pCurrentPlayer = &(g->players[(g->turns)%2u]);
  move(g, pCurrentPlayer, moveStr);
  g->turns++;
}

void display(Game* g) {
  printBoard(g->board);
}
