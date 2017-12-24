#include "E-series.h"



#define E12size 12
static const byte E12[E12size + 1] = { 10, 12, 15, 18, 22, 27, 33, 39, 47, 56, 68, 82, 100 };


float E12Value(float r)
{
  return EserieValue(E12, E12size, r);
}

char *E12FormattedValue(char *buf, int len, float r, char unitTypeChar)
{
  return EserieFormattedValue(buf, len, E12, E12size, r, unitTypeChar);
}
