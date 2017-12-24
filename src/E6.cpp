#include "E-series.h"


// E6 (20%) IEC 60063
#define E6size 6
static const byte E6[E6size + 1] = { 10, 15, 22, 33, 47, 68, 100 };


float E6Value(float r)
{
  return EserieValue(E6, E6size, r);
}

char *E6FormattedValue(char *buf, int len, float r, char unitTypeChar)
{
  return EserieFormattedValue(buf, len, E6, E6size, r, unitTypeChar);
}
