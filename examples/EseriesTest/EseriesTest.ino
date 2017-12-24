#include <IEC60063_E6.h>
#include <IEC60063_E12.h>
#include <IEC60063_E24.h>

/*
Required Libraries:
* https://github.com/microentropie/IEC60063
* http://arduiniana.org/libraries/pstring/ (http://arduiniana.org/PString/PString3.zip)
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


  char buf[E24BufSize];
  
  Serial.print(123);
  Serial.print(" => E12: ");
  Serial.print(E12FormattedValue(buf, sizeof(buf), 123, 'R'));
  Serial.println();

  float r[] = {123, 1.4E3, 1050, 1049, 1098 };
  int qt = sizeof(r) / sizeof(float);
  for(int i = 0; i < qt; ++i)
  {
    Serial.print("R=");
    Serial.print(r[i]);
    Serial.print(" => E6: ");
    Serial.print(E6FormattedValue(buf, sizeof(buf), r[i], 'R'));
    Serial.print(", E12: ");
    Serial.print(E12FormattedValue(buf, sizeof(buf), r[i], 'R'));
    Serial.print(", E24: ");
    Serial.print(E24FormattedValue(buf, sizeof(buf), r[i], 'R'));
    Serial.println();
  }
}

void loop()
{
  delay(0);
}
