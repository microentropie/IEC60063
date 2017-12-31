/*
Author:  Stefano Di Paolo
License: MIT, https://en.wikipedia.org/wiki/MIT_License
Date:  2017-12-31

Library: IEC60063 series resistors.

Sources repository: https://github.com/microentropie/
*/

#include <IEC60063_E3.h>
#include <IEC60063_E6.h>
#include <IEC60063_E12.h>
#include <IEC60063_E24.h>
#include <IEC60063_E48.h>

/*
Required Libraries:
* https://github.com/microentropie/IEC60063
*/

/*
EXAMPLE:
Set some values in r[] array and print their nearest standard E-series values.
Example: 123 ohm is '120R' in E12 serie.
*/
 
void setup()
{
  Serial.begin(74880);
  Serial.println();
  Serial.println();
  Serial.println("EseriesTest.ino");
  Serial.println("https://github.com/microentropie/IEC60063");


  char buf[EseriesBufSize];

  // please note Arduino does not directly support printing of floating point numbers
  // with mantissa and exponent. Thus here the solution has been to increase the
  // number of decimals.
  // https://playground.arduino.cc/Main/Printf
  
  float r1 = 123; // 123 ohm
  Serial.print(r1);
  Serial.print(" => E12: ");
  Serial.print(E12Value(r1));
  Serial.print(" = \"");
  Serial.print(E12FormattedValue(buf, sizeof(buf), r1, 'R'));
  Serial.println("\"");

  float c = 24.2E-9; // 24.2nF
  Serial.print(c, 10);
  Serial.print(" => E12: ");
  Serial.print(E12Value(c));
  Serial.print(" = \"");
  Serial.print(E12FormattedValue(buf, sizeof(buf), c, 'F'));
  Serial.println("\"");

  c = 1E-12; // 1pF
  Serial.print(c, 12);
  Serial.print(" => E12: ");
  Serial.print(E12Value(c));
  Serial.print(" = \"");
  Serial.print(E12FormattedValue(buf, sizeof(buf), c, 'F'));
  Serial.print("\", E48: ");
  Serial.print(E48FormattedValue(buf, sizeof(buf), c, 'F'));
  Serial.println("\"");
  Serial.println();

  float r[] = { 0, 1e-12, .31, 74, 123, 1.4E3, 1050, 1049, 1098, 172E3, 100E6 };
  int qt = sizeof(r) / sizeof(float);
  for(int i = 0; i < qt; ++i)
  {
    Serial.print("R=");
    Serial.print(r[i], 12);
    Serial.print(" => E3: ");
    Serial.print(E3FormattedValue(buf, sizeof(buf), r[i], 'R'));
    Serial.print(", => E6: ");
    Serial.print(E6FormattedValue(buf, sizeof(buf), r[i], 'R'));
    Serial.print(", E12: ");
    Serial.print(E12FormattedValue(buf, sizeof(buf), r[i], 'R'));
    Serial.print(", E24: ");
    Serial.print(E24FormattedValue(buf, sizeof(buf), r[i], 'R'));
    Serial.print(", E48: ");
    Serial.print(E48FormattedValue(buf, sizeof(buf), r[i], 'R'));
    Serial.println();
  }
}

void loop()
{
  delay(0);
}

/*
 * here is the output from an Arduino Uno
 * 
EseriesTest.ino
https://github.com/microentropie/IEC60063
123.00 => E12: 120.00 = "120R"
0.0000000242 => E12: 0.00 = "22n"
0.000000000001 => E12: 0.00 = "1p0", E48: 1p00"

R=0.000000000000 => E3: 0R, => E6: 0R, E12: 0R, E24: 0R, E48: 0R
R=0.000000000001 => E3: 1p0, => E6: 1p0, E12: 1p0, E24: 1p0, E48: 1p00
R=0.309999990463 => E3: R22, => E6: R33, E12: R33, E24: R30, E48: R316
R=74.000000000000 => E3: 100R, => E6: 68R, E12: 68R, E24: 75R, E48: 75R0
R=123.000000000000 => E3: 100R, => E6: 100R, E12: 120R, E24: 120R, E48: 121R
R=1400.000000000000 => E3: 1K0, => E6: 1K5, E12: 1K5, E24: 1K5, E48: 1K40
R=1050.000000000000 => E3: 1K0, => E6: 1K0, E12: 1K0, E24: 1K1, E48: 1K05
R=1049.000000000000 => E3: 1K0, => E6: 1K0, E12: 1K0, E24: 1K1, E48: 1K05
R=1098.000000000000 => E3: 1K0, => E6: 1K0, E12: 1K2, E24: 1K1, E48: 1K10
R=172000.000000000000 => E3: 220K, => E6: 150K, E12: 180K, E24: 180K, E48: 169K
R=100000000.000000000000 => E3: 100M, => E6: 100M, E12: 100M, E24: 100M, E48: 100M
*/

