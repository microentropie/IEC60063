/*
Author:  Stefano Di Paolo
License: MIT, https://en.wikipedia.org/wiki/MIT_License
Date:  2017-12-31

Library: IEC60063 series resistors.

Sources repository: https://github.com/microentropie/
*/

#include "E-series.h"

const char E3Tolerance[] = ">20%";

#define E3size 3
static const unsigned short E3[E3size + 1] = { 100, 220, 470, 1000 };


float E3Value(float r)
{
  return EserieValue(E3, E3size, r);
}

char *E3FormattedValue(char *buf, int len, float r, char unitTypeChar)
{
  return EserieFormattedValue(buf, len, E3, E3size, r, unitTypeChar);
}
