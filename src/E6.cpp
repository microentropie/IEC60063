/*
Author:  Stefano Di Paolo
License: MIT, https://en.wikipedia.org/wiki/MIT_License
Date:  2017-12-31

Library: IEC60063 series resistors.

Sources repository: https://github.com/microentropie/
*/

#include "E-series.h"

const char E6Tolerance[] = "20%";

#define E6size 6
static const unsigned short E6[E6size + 1] = { 100, 150, 220, 330, 470, 680, 1000 };


float E6Value(float r)
{
  return EserieValue(E6, E6size, r);
}

char *E6FormattedValue(char *buf, int len, float r, char unitTypeChar)
{
  return EserieFormattedValue(buf, len, E6, E6size, r, unitTypeChar);
}
