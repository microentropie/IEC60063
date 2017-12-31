#ifndef _E6_H_
#define _E6_H_

#include "E-series-common.h"

extern const char E6Tolerance[];
extern float E6Value(float r);
extern char *E6FormattedValue(char *buf, int len, float r, char unitTypeChar = 'R');

#endif //_E6_H_
