#include <PString.h>
#include "pow10.h"

#ifndef byte
typedef unsigned char byte;
#endif //byte


//#define _DEBUG
#ifdef _DEBUG
#include <Arduino.h>
#endif //_DEBUG


static void EserieValueFind(const byte *Eserie, int serieSize, float r, int &rE, int &decadeMultiplier)
{
  rE = decadeMultiplier = 0;
  if (r <= 0.1 || r > 1e6) // limit R from 0.1 ohm to 1 Mohm
    return; // computation refused

#ifdef _DEBUG
  Serial.print("r: ");
  Serial.println(r);
#endif //_DEBUG
  while (r * pow10(-decadeMultiplier) < Eserie[0]/*10*/)
    --decadeMultiplier;
  while (r * pow10(-decadeMultiplier) >= Eserie[serieSize]/*100*/)
    ++decadeMultiplier;
  int rNormalized = (int)(r * pow10(-decadeMultiplier) + 0.5);
#ifdef _DEBUG
  Serial.print("rNormalized: ");
  Serial.println(rNormalized);
#endif //_DEBUG
  for (int i = 0; i < serieSize; ++i)
  {
    // now: 10 <= rNormalized < 100
#ifdef _DEBUG
    Serial.print("test ");
    Serial.print(Eserie[i]);
    Serial.print(" .. ");
    Serial.println(Eserie[i + 1]);
#endif //_DEBUG
    if (rNormalized >= Eserie[i] && rNormalized < Eserie[i + 1])
    {
      // decide between 2 values
      int rLowDiff = rNormalized - Eserie[i];
      int rHighDiff = Eserie[i + 1] - rNormalized;
#ifdef _DEBUG
      Serial.print("rLowDiff=");
      Serial.print(rLowDiff);
      Serial.print(" rHighDiff=");
      Serial.println(rHighDiff);
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

float EserieValue(const byte *Eserie, int serieSize, float r)
{
  int rE, decadeMultiplier;
  EserieValueFind(Eserie, serieSize, r, rE, decadeMultiplier);

  return (float)rE * pow10(decadeMultiplier);
}
char *EserieFormattedValue(char *buf, int len, const byte *Eserie, int serieSize, float r, char unitTypeChar)
{
  int rE, decadeMultiplier;
  EserieValueFind(Eserie, serieSize, r, rE, decadeMultiplier);

  char rL, rR, multiplierCh;
  if (decadeMultiplier < 2) // 100
    multiplierCh = unitTypeChar;
  else if (decadeMultiplier < 5) //100E3
    multiplierCh = 'K';
  else if (decadeMultiplier < 8) //100E6
    multiplierCh = 'M';
  else
    multiplierCh = '+'; // overflow
  if (decadeMultiplier == -2)
  {
    // example: R15
    //snprintf(buf, len, "%c%d", multiplierCh, rE);
    PString str(buf, len);
    str = multiplierCh;
    str += rE;
    return buf;
  }
  if (decadeMultiplier == -1 || decadeMultiplier == 2 || decadeMultiplier == 5 || decadeMultiplier == 8)
  {
    rL = '0' + (rE / 10);
    rR = '0' + (rE % 10);
    // example: 1R2 or 1K2 or 1M2
    //snprintf(buf, len, "%c%c%c", rL, multiplierCh, rR);
    PString str(buf, len);
    str = rL;
    str += multiplierCh;
    str += rR;
    return buf;
  }
  else if (decadeMultiplier == 1 || decadeMultiplier == 4 || decadeMultiplier == 7)
  {
    // example: 120R or 120K or 120M
    //snprintf(buf, len, "%d0%c", rE, multiplierCh);
    PString str(buf, len);
    str = rE;
    str += "0";
    str += multiplierCh;
    return buf;
  }
  else
  {
    // example: 12R or 12K or 12M
    //snprintf(buf, len, "%d%c", rE, multiplierCh);
    PString str(buf, len);
    str = rE;
    str += multiplierCh;
    return buf;
  }
}
