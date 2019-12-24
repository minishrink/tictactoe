
#pragma once
#include <stdlib.h>


/* DEBUG switch outputs debug info to stdinput */
#ifdef DEBUG
#include <stdio.h>
#define DEBUGF(...) printf(__VA_ARGS__)
#else
  /* LOG switch outputs debug info to file */
  #ifdef LOG
  #include "log.h"
  #define DEBUGF(...) writeLog((__VA_ARGS__))
  #else
  #define DEBUGF(...) {}
  #endif
#endif

#define MALLOC(varType, varName) \
  varType* varName = (varType *)malloc(sizeof(varType))

#define BETWEEN(x,y,z) \
  (x <= y) && (y <= z)
