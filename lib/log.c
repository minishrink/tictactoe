
#include "log.h"

const char* FILENAME = "tictactoe.log";

void writeLog(const char* fmt, ...)  {
  va_list args;
  va_start(args, fmt);
  FILE* pFile = fopen(FILENAME, "a");
  fprintf((pFile), fmt, args);
  va_end(args);
  fclose(pFile);
}
