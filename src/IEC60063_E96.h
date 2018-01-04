#ifndef _E96_H_
#define _E96_H_

#include "E-series-common.h"

extern const char E96olerance[];
extern float E96Value(float r);
extern char *E96FormattedValue(char *buf, int len, float r, char unitTypeChar = 'R');

#endif //_E96_H_
