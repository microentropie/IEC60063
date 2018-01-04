#ifndef _E192_H_
#define _E192_H_

#include "E-series-common.h"

extern const char E192olerance[];
extern float E192Value(float r);
extern char *E192FormattedValue(char *buf, int len, float r, char unitTypeChar = 'R');

#endif //_E192_H_
