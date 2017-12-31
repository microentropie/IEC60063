#ifndef _E48_H_
#define _E48_H_

#include "E-series-common.h"

extern const char E48olerance[];
extern float E48Value(float r);
extern char *E48FormattedValue(char *buf, int len, float r, char unitTypeChar = 'R');

#endif //_E48_H_
