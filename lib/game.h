#pragma once

/***** INCLUDES *****/

#include "board.h"

/*** DEFINES ***/

#define NUMPLAYERS (2u)

/*** MACROS ***/

/***** DATA TYPES ****/

typedef struct PlayerT  {
  const CHAR* Name;
  SymbolT     Piece;
} Player;

// recall enums are uint32 by default
typedef enum StateT {
  NOT_STARTED = 0u,
  IN_PROGRESS,
  OVER_STALE,
  OVER_WON
} StateT;

typedef struct GameT  {
  StateT       state;
  Board*       board;
  Player       players[NUMPLAYERS];
  unsigned int turns;
} Game;

/**** FUNCTION PROTOTYPES ****/

Game* initGame(const char* p1, const char* p2);

Player* initPlayer(const CHAR* m, SymbolT Piece);

void beginGame(Game* g);

void updateState(Game* g);

void turn(Game* g, char moveStr[MOVELEN]);

void play(Game* g);

void display(Game* g);
