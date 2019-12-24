/**** INCLUDES ****/

#pragma once
#include <stdint.h>

/***** DEFINES *****/

/*
#define CROSS    ('X')
#define NOUGHT   ('O')
#define EMPTY    ('-')
*/

#define BOARDLEN (3u)
#define CHAR     uint8_t

/***** MACROS ******/

#define IS_CROSS(x)  (CROSS==x)
#define IS_NOUGHT(x) (NOUGHT==x)
#define IS_EMPTY(x)  (EMPTY==x)

/***** DATA TYPES ****/

// ('X', 88); ('O', 79); ('-', 45)
typedef enum SymbolT  {
  _EMPTY  = 45,
  _NOUGHT = 79,
  _CROSS  = 88
} SymbolT;

extern const char CROSS ;
extern const char NOUGHT;
extern const char EMPTY ;

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

const char getSymbol(SymbolT sym);

Board* initBoard(void);

void makeMove(Board* b, Move* m);
