/*
Author:  Stefano Di Paolo
License: MIT, https://en.wikipedia.org/wiki/MIT_License
Date:  2017-12-31

Library: IEC60063 series resistors.

Sources repository: https://github.com/microentropie/
*/

#include "E-series.h"

const char E48Tolerance[] = "2%";

#define E48size 48
static const unsigned short E48[E48size + 1] = { 100, 105, 110, 115, 121, 127, 133, 140,
                                                 147, 154, 162, 169, 178, 187, 196, 205,
                                                 215, 226, 237, 249, 261, 274, 287, 301,
                                                 316, 332, 348, 365, 383, 402, 422, 442,
                                                 464, 487, 511, 536, 562, 590, 619, 649,
                                                 681, 715, 750, 787, 825, 866, 909, 953,
                                                1000 };


float E48Value(float r)
{
  return EserieValue(E48, E48size, r);
}

char *E48FormattedValue(char *buf, int len, float r, char unitTypeChar)
{
  return EserieFormattedValue(buf, len, E48, E48size, r, unitTypeChar);
}
