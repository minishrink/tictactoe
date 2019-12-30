
#include "log.h"

#if defined(LOG) && defined(LOGFILE)
void writeLog(const char* fmt, ...)  {
  va_list args;
  va_start(args, fmt);
  FILE* pFile = fopen(LOGFILE, "a");
  vfprintf(pFile, fmt, args);
  fclose(pFile);
  va_end(args);
}
#endif

void debugModeMessage(void) {
  printf("Log level: %s\n", LOGLEVEL);
#if defined(LOG) && defined(LOGFILE)
  printf("Writing log to file: %s\n", LOGFILE);
#endif
}
