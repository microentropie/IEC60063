#ifndef _E3_H_
#define _E3_H_

//#include <arduino.h>
#define E3BufSize 5
extern float E3Value(float r);
extern char *E3FormattedValue(char *buf, int len, float r, char unitTypeChar = 'R');

#endif //_E3_H_
