/**** INCLUDES ****/

#pragma once
#include <stdint.h>

/***** DEFINES *****/

#define CROSS    ('X')
#define NOUGHT   ('O')
#define EMPTY    ('-')
#define BOARDLEN (3u)
#define CHAR int
/***** MACROS ******/

#define IS_CROSS(x)  (CROSS==x)
#define IS_NOUGHT(x) (NOUGHT==x)
#define IS_EMPTY(x)  (EMPTY==x)

/***** DATA TYPES ****/

typedef enum SymbolT  {
  _EMPTY,
  _CROSS,
  _NOUGHT
} SymbolT;

/* Column and row typedefs */
typedef char RowT[BOARDLEN];
typedef RowT GridT[BOARDLEN];

/* 2D array board */
typedef struct BoardT {
  GridT Grid;
} Board;

typedef struct MoveT  {
  SymbolT  Piece;
  uint8_t  Row;
  uint8_t  Col;
} Move;


/**** FUNCTION PROTOTYPES ****/

char getSymbol(SymbolT sym);

Board makeBoard(void);

void makeMove(Board* b, Move* m);
