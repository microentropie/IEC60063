/*
Author:  Stefano Di Paolo
License: MIT, https://en.wikipedia.org/wiki/MIT_License
Date:  2018-01-05

Library: IEC60063 series resistors.

Sources repository: https://github.com/microentropie/
*/

#include "E-series.h"

const char E96Tolerance[] = "1%";

#define E96size 96
static const unsigned short E96[E96size + 1] = { 100, 102, 105, 107, 110, 113,
                                                 115, 118, 121, 124, 127, 130,
                                                 133, 137, 140, 143, 147, 150,
                                                 154, 158, 162, 165, 169, 174,
                                                 178, 182, 187, 191, 196, 200,
                                                 205, 210, 215, 221, 226, 232,
                                                 237, 243, 249, 255, 261, 267,
                                                 274, 280, 287, 294, 301, 309,
                                                 316, 324, 332, 340, 348, 357,
                                                 365, 374, 383, 392, 402, 412,
                                                 422, 432, 442, 453, 464, 475,
                                                 487, 499, 511, 523, 536, 549,
                                                 562, 576, 590, 604, 619, 634,
                                                 649, 665, 681, 698, 715, 732,
                                                 750, 768, 787, 806, 825, 845,
                                                 866, 887, 909, 931, 953, 976,
                                                1000 };

float E96Value(float r)
{
  return EserieValue(E96, E96size, r);
}

char *E96FormattedValue(char *buf, int len, float r, char unitTypeChar)
{
  return EserieFormattedValue(buf, len, E96, E96size, r, unitTypeChar);
}
