#pragma once

/***** INCLUDES *****/

#include "board.c"

/***** DATA TYPES ****/

typedef struct PlayerT  {
  char* Name;
  char  Symbol;
} Player;

// recall enums are uint32 by default
typedef enum StateT {
  NOT_STARTED = 0u,
  IN_PROGRESS,
  OVER_STALE,
  OVER_WON
} StateT;

typedef struct GameT  {
  enum StateT state;
  Board       board;
  Player*     players;
} Game;

/**** FUNCTION PROTOTYPES ****/

Game* initGame(void);

void beginGame(Game* g);

void updateState(Game* g);

void turn(Game* g);
