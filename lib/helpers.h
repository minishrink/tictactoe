
#pragma once
#include <stdlib.h>
  #include <stdio.h>

/* DEBUG switch outputs debug info to stdinput */
#if defined   DEBUG
  #define DEBUGF(...) (printf   (__VA_ARGS__))
/* FIXME LOG switch outputs debug info to file */
#elif defined LOG
  #include "log.h"
  #define DEBUGF(...) (writeLog (__VA_ARGS__))
#else
  #define DEBUGF(...) ({})
#endif

#define MALLOC(varType, varName) \
  varType* varName = (varType *)malloc(sizeof(varType))

#define BETWEEN(x,y,z) \
  (x <= y) && (y <= z)
