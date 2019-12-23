
#include <stdio.h>

/* DEBUG switch outputs debug info */
#if defined(DEBUG)
#define DEBUGF(...) printf(__VA_ARGS__)
#else
#define DEBUGF(...) {}
#endif

#define MALLOC(varType, varName) \
  varType* varName = (varType *)malloc(sizeof(varType))
