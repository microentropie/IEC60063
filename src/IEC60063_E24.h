#ifndef _E24_H_
#define _E24_H_

#include "E-series-common.h"

extern const char E24Tolerance[];
extern float E24Value(float r);
extern char *E24FormattedValue(char *buf, int len, float r, char unitTypeChar = 'R');

#endif //_E24_H_
