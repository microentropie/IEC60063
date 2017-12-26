#include "E-series.h"


// E3 (>20%) IEC 60063
#define E3size 6
static const byte E3[E3size + 1] = { 10, 22, 47, 100 };


float E3Value(float r)
{
  return EserieValue(E3, E3size, r);
}

char *E3FormattedValue(char *buf, int len, float r, char unitTypeChar)
{
  return EserieFormattedValue(buf, len, E3, E3size, r, unitTypeChar);
}
