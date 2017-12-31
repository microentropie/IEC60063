/*
Author:  Stefano Di Paolo
License: MIT, https://en.wikipedia.org/wiki/MIT_License
Date:  2017-12-31

Library: IEC60063 series resistors.

Sources repository: https://github.com/microentropie/
*/

#include "E-series.h"

const char E12Tolerance[] = "10%";

#define E12size 12
static const unsigned short E12[E12size + 1] = { 100, 120, 150, 180, 220, 270, 330, 390, 470, 560, 680, 820, 1000 };


float E12Value(float r)
{
  return EserieValue(E12, E12size, r);
}

char *E12FormattedValue(char *buf, int len, float r, char unitTypeChar)
{
  return EserieFormattedValue(buf, len, E12, E12size, r, unitTypeChar);
}
