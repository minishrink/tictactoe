
#pragma once

/*** INCLUDES ***/
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "log.h"

/*** DEFINES ***/
#define CHAR uint8_t

/*** MACROS ***/
#define MALLOC(varType, varName) \
  varType* varName = (varType *)malloc(sizeof(varType))

#define BETWEEN(x,y,z) \
  (x <= y) && (y <= z)
