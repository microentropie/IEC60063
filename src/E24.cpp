/*
Author:  Stefano Di Paolo
License: MIT, https://en.wikipedia.org/wiki/MIT_License
Date:  2017-12-31

Library: IEC60063 series resistors.

Sources repository: https://github.com/microentropie/
*/

#include "E-series.h"

const char E24Tolerance[] = "5%";

#define E24size 24
static const unsigned short E24[E24size + 1] = { 100, 110, 120, 130, 150, 160, 180, 200,
                                                 220, 240, 270, 300, 330, 360, 390, 430,
                                                 470, 510, 560, 620, 680, 750, 820, 910,
                                                1000 };


float E24Value(float r)
{
  return EserieValue(E24, E24size, r);
}

char *E24FormattedValue(char *buf, int len, float r, char unitTypeChar)
{
  return EserieFormattedValue(buf, len, E24, E24size, r, unitTypeChar);
}
