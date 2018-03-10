#include <L298N.h>

//pin Left
#define A_ENA 2
#define A_N1  3
#define A_N2  4
#define A_N3  5 
#define A_N4  6
#define A_ENB 7

L298N mdA(A_ENA,A_N1,A_N2,A_N3,A_N4,A_ENB);

char junk;
String inputString="";

void setup() {
  Serial.begin(9600);    
  mdA.initmotor();
}

void loop() {

  if(Serial.available()){
  while(Serial.available())
    {
      char inChar = (char)Serial.read(); //read the input
      inputString += inChar;        //make a string of the characters coming on serial
    }
    Serial.println(inputString);
    while (Serial.available() > 0)  
    { junk = Serial.read() ; }      // clear the serial buffer

    if ( inputString == "1"){
        mdA.motorLeftForwardClock(150); 
    } else if ( inputString == "2" ){
      mdA.motorLeftRevertClock(200);
    }else if ( inputString == "3") {
        mdA.motorRightForwardClock(255);
    }else if ( inputString == "4" ){
        mdA.motorRightRevertClock(200);
    }else if ( inputString == "5"){
       mdA.motorLeftstop();
       mdA.motorRightstop();     
    }

    inputString = "";
  }


} //loop