#ifndef _E6_H_
#define _E6_H_

//#include <arduino.h>
#define E6BufSize 5
extern float E6Value(float r);
extern char *E6FormattedValue(char *buf, int len, float r, char unitTypeChar = 'R');

#endif //_E6_H_
