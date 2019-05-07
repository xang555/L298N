# L298N

Simple Arduino L298N Library make for easy way for control DC motor by using L298N Module.

# how to use

- install library to your arduino IDE (Download from github)
- let see examples

# Example

```c++

#include <L298N.h>

//pin Left
#define A_ENA 2
#define A_N1 3
#define A_N2 4
#define A_N3 5
#define A_N4 6
#define A_ENB 7

L298N mdA(A_ENA, A_N1, A_N2, A_N3, A_N4, A_ENB);

char junk;
String inputString = "";

void setup()
{
  Serial.begin(9600);
  mdA.begin();
}

void loop()
{

  if (Serial.available())
  {
    while (Serial.available())
    {
      char inChar = (char)Serial.read();
      inputString += inChar;
    }
    Serial.println(inputString);
    while (Serial.available() > 0)
    {
      junk = Serial.read();
    } // clear the serial buffer

    if (inputString == "1")
    {
      mdA.motorLeftForwardClock(150);
    }
    else if (inputString == "2")
    {
      mdA.motorLeftRevertClock(200);
    }
    else if (inputString == "3")
    {
      mdA.motorRightForwardClock(255);
    }
    else if (inputString == "4")
    {
      mdA.motorRightRevertClock(200);
    }
    else if (inputString == "5")
    {
      mdA.motorLeftstop();
      mdA.motorRightstop();
    }
    else if (inputString == "6")
    {
      mdA.motorLeftbreak(100);
    }
    else if (inputString == "7")
    {
      mdA.motorRightbreak(100);
    }

    inputString = "";
  }

} //loop

```

# determine left and right motor

![l298n](https://github.com/xang555/L298N/blob/master/img/l298edit.png)
