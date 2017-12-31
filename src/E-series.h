#ifndef _E_SERIES_H_
#define _E_SERIES_H_

void EserieValueFind(const unsigned short Eserie[], int serieSize, float r, int &rE, int &decadeMultiplier);

float EserieValue(const unsigned short Eserie[], int serieSize, float r);

char *EserieFormattedValue(char *buf, int len, const unsigned short Eserie[], int serieSize, float r, char unitTypeChar);

#endif //_E_SERIES_H_
