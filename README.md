IEC60063
========

* Author: Stefano Di Paolo (<http://github.com/microentropie>)
* Copyright (C) 2017 Stefano Di Paolo.
* Released under the MIT license.

Given a value returns the E-series nearest value.
Example 123 ohm nearest E24 value is 120R.
Standard values for R, L and C are defined by [IEC60063](https://en.wikipedia.org/wiki/E-series_of_preferred_numbers)
This library currently implements E6, E12 and E24.
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
**float E6Value(float r);**
given a non standard value, returns the nearest E6 value as a float number.
Example:
```C++
float rE6 = E6Value(123);
```


**`char *E6FormattedValue(char *buf, int len, float r, char unitTypeChar = 'R');`**
given a non standard value, returns the nearest E6 value as a string.
Example:
```C++
char buf[E6BufSize];

Serial.print(E6FormattedValue(buf, sizeof(buf), 123, 'R')); 
// sends "100R" to serial
```


**`float E12Value(float r);`**
given a non standard value, returns the nearest E12 value as a float number.
Example:
```C++
float rE12 = E12Value(123);
```


**`char *E12FormattedValue(char *buf, int len, float r, char unitTypeChar = 'R');`**
given a non standard value, returns the nearest E12 value as a string.
Example:
```C++
char buf[E12BufSize];

Serial.print(E12FormattedValue(buf, sizeof(buf), 123, 'R')); 
// sends "120R" to serial
```


**`float E24Value(float r);`**
given a non standard value, returns the nearest E24 value as a float number.
Example:
```C++
float rE24 = E24Value(123);
```


**`char *E24FormattedValue(char *buf, int len, float r, char unitTypeChar = 'R');`**
given a non standard value, returns the nearest E24 value as a string.
Example:
```C++
char buf[E24BufSize];

Serial.print(E24FormattedValue(buf, sizeof(buf), 123, 'R')); 
// sends "120R" to serial
```


License
-------
Copyright (c) 2017 by Stefano Di Paolo
The MIT License (MIT).
A copy of the license is enclosed (see license file), or you can read it here:
<https://en.wikipedia.org/wiki/MIT_License>
