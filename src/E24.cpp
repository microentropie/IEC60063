#include "E-series.h"



#define E24size 24
static const byte E24[E24size + 1] = { 10, 11, 12, 13, 15, 16, 18, 20, 22, 24, 27, 30, 33, 36, 39, 43, 47, 51, 56, 62, 68, 75, 82, 91, 100 };


float E24Value(float r)
{
  return EserieValue(E24, E24size, r);
}

char *E24FormattedValue(char *buf, int len, float r, char unitTypeChar)
{
  return EserieFormattedValue(buf, len, E24, E24size, r, unitTypeChar);
}
