IEC60063
========

* Author: Stefano Di Paolo (<http://github.com/microentropie>)
* Copyright (C) 2017 Stefano Di Paolo.
* Released under the MIT license.

Arduino library.<br>
Given a value returns the E-series nearest value.<br>
Example 123 ohm nearest E24 value is "120R".<br>
Standard values for R, L and C are defined by [IEC60063](https://en.wikipedia.org/wiki/E-series_of_preferred_numbers).<br>
This library currently implements E3, E6, E12, E24 and E48.<br>
Code is Arduino-portable so should work in any Arduino compatible platform.<br>
Tested on Arduino Uno and ESP8266.

Requirements
------------
* An [Arduino](http://arduino.cc/)

Installation
------------
Download the ZIP archive (<https://github.com/microentropie/Arduino-Libraries> click on IEC60063.zip then click on the Download button)
open the Arduino IDE and choose Sketch -> Include Library -> Add .ZIP Library... and select the downloaded file.

Code Examples
-------------
Library contains this example:
* [EseriesTest](./examples/EseriesTest/EseriesTest.ino):
  Report (to Serial) E-series values from some non standard values.

Documentation
-------------
Please change Exx with the relevant serie:<br>
**float ExxValue(float r);**<br>
given a non standard value, returns the nearest Exx value as a float number.<br>
Example:<br>
```C++
#include <IEC60063_Exx.h>
float rE = ExxValue(123);
Serial.print(rE); 
// sends 100 to serial, if Exx is E6
```


Please change Exx with the relevant serie:<br>
**`char *ExxFormattedValue(char *buf, int len, float r, char unitTypeChar = 'R');`**<br>
given a non standard value, returns the nearest Exx value as a string.<br>
Example:<br>
```C++
#include <IEC60063_Exx.h>
char buf[ExxBufSize];

Serial.print(ExxFormattedValue(buf, sizeof(buf), 123, 'R')); 
// sends "100R" to serial, if Exx is E6
```


License
-------
Copyright (c) 2017 by Stefano Di Paolo
The MIT License (MIT).
A copy of the license is enclosed (see license file), or you can read it here:
<https://en.wikipedia.org/wiki/MIT_License>
