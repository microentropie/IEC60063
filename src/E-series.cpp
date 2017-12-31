/*
Author:  Stefano Di Paolo
License: MIT, https://en.wikipedia.org/wiki/MIT_License
Date:  2017-12-31

Library: IEC60063 series resistors.

Sources repository: https://github.com/microentropie/
*/

#include "intPowLog10.h"
#include "E-series.h"
#include "E-series-common.h"

#undef _DEBUG
#ifdef _DEBUG
#include <stdio.h>"
#else
#define NULL 0
#endif //_DEBUG


void EserieValueFind(const unsigned short *Eserie, int serieSize, float r, int &rE, int &decadeMultiplier)
{
  rE = decadeMultiplier = 0;
  if (r < 0.999E-12 || r > 100.1E6) // limit R (or C or L) from 1 pico to 100 Mega
    return; // computation refused

#ifdef _DEBUG
  printf("r: %e\n", r);
#endif //_DEBUG
  decadeMultiplier = log10(r) - 2; // less 2 because we need a number between 100 and < 1000
  // NOTE: due to rounding effects we may have <decadeMultiplier> +/-1
  //       thus we need to fine tune:
  while (r * pow10(-decadeMultiplier) < Eserie[0]/*100*/)
    --decadeMultiplier;
  while (r * pow10(-decadeMultiplier) >= Eserie[serieSize]/*1000*/)
    ++decadeMultiplier;
  int rNormalized = (int)(r * pow10(-decadeMultiplier) + 0.5);
#ifdef _DEBUG
  printf("rNormalized: %d (multiplier: %d)\n", rNormalized, decadeMultiplier);
#endif //_DEBUG
  // NOTE: a binary search would be more efficient
  for (int i = 0; i < serieSize; ++i)
  {
    // now: 100 <= rNormalized < 1000
#ifdef _DEBUG
    printf("test %d .. %d\n", Eserie[i], Eserie[i + 1]);
#endif //_DEBUG
    if (rNormalized >= Eserie[i] && rNormalized < Eserie[i + 1])
    {
      // decide between 2 values
      int rLowDiff = rNormalized - Eserie[i];
      int rHighDiff = Eserie[i + 1] - rNormalized;
#ifdef _DEBUG
      printf("rLowDiff=%d rHighDiff=%d\n", rLowDiff, rHighDiff);
#endif //_DEBUG
      int ir = (rHighDiff > rLowDiff) ? i : i + 1;
      if (ir == serieSize)
      {
        rE = Eserie[0];
        ++decadeMultiplier;
      }
      else
        rE = Eserie[ir];
      return;
    }
  }
  // failed to find standard value
}

float EserieValue(const unsigned short *Eserie, int serieSize, float r)
{
  int rE, decadeMultiplier;
  EserieValueFind(Eserie, serieSize, r, rE, decadeMultiplier);

  return (float)rE * pow10(decadeMultiplier);
}

static char *RemoveLeadingZeros(char *buf, int len)
{
  if (buf[0] == '0' && buf[1] == '0') return &buf[2];
  if (buf[0] == '0') return &buf[1];
  return buf;
}

char *EserieFormattedValue(char *buf, int len, const unsigned short *Eserie, int serieSize, float r, char unitTypeChar)
{
  if (len < EseriesBufSize)
    return NULL;

  int rE, decadeMultiplier;
  EserieValueFind(Eserie, serieSize, r, rE, decadeMultiplier);

  // we have now a 3 digits number and a multiplier (10^decadeMultiplier)
  // example 123 and -4
  char r100, r10, r1, multiplierCh;
  int scaledDecadeMultiplier = 0;
  if (decadeMultiplier <= -12) // 1.23E-12, 12.3E-12, 123E-12
  {
    multiplierCh = 'p';
    scaledDecadeMultiplier = decadeMultiplier + 12;
  }
  else if (decadeMultiplier <= -9) // 1.23E-9, 12.3E-9, 123E-9
  {
    multiplierCh = 'n';
    scaledDecadeMultiplier = decadeMultiplier + 9;
  }
  else if (decadeMultiplier <= -6) // 1.23E-6, 12.3E-6, 123E-6
  {
    multiplierCh = 'u';
    scaledDecadeMultiplier = decadeMultiplier + 6;
  }
  else if (decadeMultiplier <= /*-3*/-4) // 1.23E-3, 12.3E-3, (*)
  {
    multiplierCh = 'm';
    scaledDecadeMultiplier = decadeMultiplier + 3;
  }
  else if (decadeMultiplier <= 0) // .123 (*), 1.23, 12.3, 123
  {
    multiplierCh = unitTypeChar;
    scaledDecadeMultiplier = decadeMultiplier;
  }
  else if (decadeMultiplier <= 3) // 1.23E3, 12.3E3, 123E3
  {
    multiplierCh = 'K';
    scaledDecadeMultiplier = decadeMultiplier - 3;
  }
  else if (decadeMultiplier <= 6) // 1.23E6, 12.3E6, 123E6
  {
    multiplierCh = 'M';
    scaledDecadeMultiplier = decadeMultiplier - 6;
  }
  else
  {
    multiplierCh = '+'; // overflow
    scaledDecadeMultiplier = decadeMultiplier - 9;
  }

  // split single digits
  r100 = '0' + (rE / 100);
  r10 = '0' + ((rE / 10) % 10);
  r1 = '0' + (rE % 10);

  switch (scaledDecadeMultiplier)
  {
  case -3:
    // see note (*)
    buf[0] = multiplierCh;
    buf[1] = r100;
    buf[2] = r10;
    buf[3] = (serieSize >= 48) ? r1 : '\0';
    buf[4] = '\0';
    return RemoveLeadingZeros(buf, len);

  case -2:
    // example: 3p16, 3n16, 3u16, 3m16, 3R16, 3K16, 3M16
    buf[0] = r100;
    buf[1] = multiplierCh;
    buf[2] = r10;
    buf[3] = (serieSize >= 48) ? r1 : '\0';
    buf[4] = '\0';
    return RemoveLeadingZeros(buf, len);

  case -1:
    // example: 31p6, 31n6, 31u6, 31m6, 31R6, 31K6, 31M6
    buf[0] = r100;
    buf[1] = r10;
    buf[2] = multiplierCh;
    buf[3] = (serieSize >= 48) ? r1 : '\0';
    buf[4] = '\0';
    return RemoveLeadingZeros(buf, len);

  case 0:
    // example: 316p, 316n, 316u, no 316m (*), 316R, 316K, 316M
    buf[0] = r100;
    buf[1] = r10;
    buf[2] = r1;
    buf[3] = multiplierCh;
    buf[4] = '\0';
    return RemoveLeadingZeros(buf, len);
  }

  // error
  buf[0] = '?';
  buf[1] = '\0';
  return buf;

  // (*) note:
  // .123 value: instead of 123m I prefer R123 notation
}
