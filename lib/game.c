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
  g->players[0] = initPlayer((const CHAR*) p1, _CROSS);
  g->players[1] = initPlayer((const CHAR*) p2, _NOUGHT);
  return g;
}

void beginGame(Game* g) {
  g->board = initBoard();
  g->state = IN_PROGRESS;
}

void updateState(Game* g) {
  if (g->state == IN_PROGRESS)  {
    if (g->turns >= BOARDLEN*BOARDLEN)  {
      g->state = COMPLETE;
    }
  }
}

void display(Game* g) {
  printBoard(g->board);
}

void move(Game* g, Player* p, CHAR moveStr[MOVELEN])  {
  placePiece(g->board, moveStr, p->Piece);
}

bool validTurn(Game* g) {
  return ((IN_PROGRESS == g->state) && (g->turns < BOARDLEN*BOARDLEN));
}

void turn(Game* g, char moveStr[MOVELEN])  {
  if (validTurn(g))  {
    Player* pCurrentPlayer = g->players[(g->turns)%MOVELEN];
    move(g, pCurrentPlayer, (CHAR*) moveStr);
    DEBUGF("Turn %d: %s -> %s\n", g->turns+1u, pCurrentPlayer->Name, moveStr);
    g->turns++;
  }
  else  {
    DEBUGF("Should fail here\n");
  }
}

void getInput(const CHAR* playerName, char* string)  {
  char moveTmp[MOVELEN];
  bool  validInput = false;
  printf("%s move: ", playerName);
  fgets("%s", *moveTmp, stdin);
  while (!validInput) {
    validInput = validMove((CHAR*) moveTmp);
    printf("Invalid move, please try again: ");
    fgets("%s", *moveTmp, stdin);
  }
  *string = *moveTmp;
}

void play(Game* g)  {
  char* string = NULL;
  while (validTurn(g))  {
    getInput(g->players[(g->turns%2u)]->Name, string);
    turn(g, string);
    // check if game over / won
    updateState(g);
    display(g);
  }
}

void endGame(Game* g) {
  FREE(g);
}
