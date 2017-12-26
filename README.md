IEC60063
========

* Author: Stefano Di Paolo (<http://github.com/microentropie>)
* Copyright (C) 2017 Stefano Di Paolo.
* Released under the MIT license.

Arduino library.
Given a value returns the E-series nearest value.
Example 123 ohm nearest E24 value is 120R.
Standard values for R, L and C are defined by [IEC60063](https://en.wikipedia.org/wiki/E-series_of_preferred_numbers)
This library currently implements E3, E6, E12 and E24.
Code is Arduino-portable so should work in any Arduino compatible platform.
Tested on Arduino Uno and ESP8266.

Requirements
------------
* An [Arduino](http://arduino.cc/)

Installation
------------
Download the ZIP archive (<https://github.com/microentropie/IEC60063> Press "Clone or download", then "Download ZIP"),
open the Arduino IDE and choose Sketch -> Include Library -> Add .ZIP Library... and select the downloaded file.

Code Examples
-------------
Library contains this example:
* [EseriesTest](./examples/EseriesTest/EseriesTest.ino):
  Report (to Serial) E-series values from some non standard values.

Documentation
-------------
Please change Exx with the relevant serie:
**float ExxValue(float r);**
given a non standard value, returns the nearest Exx value as a float number.
Example:
```C++
#include <IEC60063_Exx.h>
float rE = ExxValue(123);
```


Please change Exx with the relevant serie:
**`char *ExxFormattedValue(char *buf, int len, float r, char unitTypeChar = 'R');`**
given a non standard value, returns the nearest Exx value as a string.
Example:
```C++
#include <IEC60063_Exx.h>
char buf[ExxBufSize];

Serial.print(ExxFormattedValue(buf, sizeof(buf), 123, 'R')); 
// sends "100R" to serial
```


License
-------
Copyright (c) 2017 by Stefano Di Paolo
The MIT License (MIT).
A copy of the license is enclosed (see license file), or you can read it here:
<https://en.wikipedia.org/wiki/MIT_License>
