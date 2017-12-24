#ifndef _E_SERIES_H_
#define _E_SERIES_H_

#ifndef byte
typedef unsigned char byte;
#endif //byte

void EserieValueFind(const byte Eserie[], int serieSize, float r, int &rE, int &decadeMultiplier);

float EserieValue(const byte Eserie[], int serieSize, float r);

char *EserieFormattedValue(char *buf, int len, const byte Eserie[], int serieSize, float r, char unitTypeChar);

#endif //_E_SERIES_H_
