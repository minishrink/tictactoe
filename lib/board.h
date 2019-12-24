/**** INCLUDES ****/

#pragma once
#include <stdint.h>

/***** DEFINES *****/

#define BOARDLEN (3u)
#define CHAR     uint8_t

/***** MACROS ******/

#define IS_CROSS(x)  (CROSS==x)
#define IS_NOUGHT(x) (NOUGHT==x)
#define IS_EMPTY(x)  (EMPTY==x)

extern const CHAR CROSS ;
extern const CHAR NOUGHT;
extern const CHAR EMPTY ;

/***** DATA TYPES ****/

// ('X', 88); ('O', 79); ('-', 45)
typedef enum SymbolT  {
    _EMPTY
  , _NOUGHT
  , _CROSS
} SymbolT;

/* Column and row typedefs */
typedef CHAR RowT[BOARDLEN];
typedef RowT GridT[BOARDLEN];

/* 2D array board */
typedef struct BoardT {
  GridT Grid;
} Board;

typedef struct MoveT  {
  SymbolT Piece;
  CHAR    Row;
  CHAR    Col;
} Move;


/**** FUNCTION PROTOTYPES ****/

const CHAR getSymbol(SymbolT sym);

Board* initBoard(void);

void makeMove(Board* b, Move* m);
