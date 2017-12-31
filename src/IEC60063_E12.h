#ifndef _E12_H_
#define _E12_H_

#include "E-series-common.h"

extern const char E12Tolerance[];
extern float E12Value(float r);
extern char *E12FormattedValue(char *buf, int len, float r, char unitTypeChar = 'R');

#endif //_E12_H_
