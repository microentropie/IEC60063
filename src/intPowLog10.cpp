/*
Author:  Stefano Di Paolo
License: MIT, https://en.wikipedia.org/wiki/MIT_License
Date:  2017-12-31

Library: IEC60063 series resistors.
This source performs integer math power and log, base 10.

Sources repository: https://github.com/microentropie/
*/

static const float _pow10[] = { 1e-15, 1e-14, 1e-13, 1e-12, 1e-11, 1e-10, 1e-9, 1e-8, 1e-7, 1e-6, 1e-5, 1e-4, 1e-3, 1e-2, 1e-1, 1e0, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9, 1e10, 1e11, 1e12, 1e13, 1e14, 1e15 };
#define MIN_EXP -15
#define MAX_EXP 15


// returns the power (base 10) of an integer number
float pow10(int y)
{
  if (y < MIN_EXP || y > MAX_EXP)
    return 0; // out of range
  return _pow10[y - MIN_EXP];
}


// raw logaritmic function
int log10(float f)
{
  // NOTE: a binary search would be more efficient
  for (int y = 0; y < MAX_EXP - MIN_EXP + 1; ++y)
    if (_pow10[y] <= f && f < _pow10[y + 1])
      return y + MIN_EXP;
  return 0; // out of range
}