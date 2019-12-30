
#include "log.h"

const char* FILENAME = "tictactoe.log";

void writeLog(const char* fmt, ...)  {
  va_list args;
  va_start(args, fmt);
  FILE* pFile = fopen(FILENAME, "a");
  vfprintf(pFile, fmt, args);
  fclose(pFile);
  va_end(args);
}

void debugModeMessage(void) {
  printf("Log level: %s\n", LOGLEVEL);
#ifdef LOG
  printf("Writing log to file: %s\n", FILENAME);
#endif
}
