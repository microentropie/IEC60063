#ifndef _E12_H_
#define _E12_H_

#define E12BufSize 5

extern float E12Value(float r);
/*
String E12FormattedValue(float r, char unitTypeChar = 'R')
{
  char buf[5];
  return String(E12FormattedValue(buf, sizeof(buf), r, unitTypeChar));
}
*/
char *E12FormattedValue(char *buf, int len, float r, char unitTypeChar = 'R');

#endif //_E12_H_
