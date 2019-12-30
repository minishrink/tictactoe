
#pragma once

/*** INCLUDES ***/
#include <stdio.h>
#include <stdarg.h>

/*** DEFINES ***/
#define NO_LOG     "NONE"

/*** MACROS ***/
#define STRINGIFY(x) #x

/* DEBUG switch outputs debug info to stdinput */
#if   defined(DEBUG)
  #define LOGLEVEL    (STRINGIFY(DEBUG))
  #define DEBUGF(...) (printf   (__VA_ARGS__))
/* LOGFILE is a CLI arg */
#elif defined(LOG) && defined(LOGFILE)
  #define LOGLEVEL    (STRINGIFY(LOG))
  #define DEBUGF(...) (writeLog (__VA_ARGS__))
#else
  #define LOGLEVEL    (NO_LOG)
  #define DEBUGF(...) {}
#endif

/*** PROTOTYPES ***/
void writeLog(const char* fmt, ...);

void debugModeMessage(void);
