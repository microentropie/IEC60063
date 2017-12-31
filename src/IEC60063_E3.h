#ifndef _E3_H_
#define _E3_H_

#include "E-series-common.h"

extern const char E3Tolerance[];
extern float E3Value(float r);
extern char *E3FormattedValue(char *buf, int len, float r, char unitTypeChar = 'R');

#endif //_E3_H_
