#include "L298N.h"
#ifndef	LOW_PWM	
#define	LOW_PWM	0

L298N::L298N(){/*init constructor*/};

L298N::L298N(uint8_t ena,uint8_t n1,uint8_t n2,uint8_t n3,uint8_t n4,uint8_t enb){
	this->ENA = ena;
	this->ENB = enb;
	this->N1 = n1;
	this->N2 = n2;
	this->N3 = n3;
	this->N4 = n4;		
}


void L298N::initmotor(){
		pinMode(ENA,OUTPUT);
		pinMode(ENB,OUTPUT);
		pinMode(N1,OUTPUT);
		pinMode(N2,OUTPUT);
		pinMode(N3,OUTPUT);
		pinMode(N4,OUTPUT);
	}
	
void L298N::motorLeftForwardClock(uint8_t PWM){
	analogWrite(ENA,PWM);
	digitalWrite(N1,HIGH);
	digitalWrite(N2,LOW);
}	

void L298N::motorRightForwardClock(uint8_t PWM){
	analogWrite(ENB,PWM);
	digitalWrite(N3,HIGH);
	digitalWrite(N4,LOW);
}

void L298N::motorLeftRevertClock(uint8_t PWM){
	analogWrite(ENA,PWM);
	digitalWrite(N1,LOW);
	digitalWrite(N2,HIGH);
}

void L298N::motorRightRevertClock(uint8_t PWM){
	analogWrite(ENB,PWM);
	digitalWrite(N3,LOW);
	digitalWrite(N4,HIGH);
}

void L298N::motorLeftbreak(uint8_t PWM){
	analogWrite(ENA,PWM);
	digitalWrite(N1,HIGH);
	digitalWrite(N2,HIGH);
}

void L298N::motorRightbreak(uint8_t PWM){
	analogWrite(ENB,PWM);
	digitalWrite(N3,HIGH);
	digitalWrite(N4,HIGH);
}

void L298N::motorLeftstop(){
	analogWrite(ENA,LOW_PWM);
	digitalWrite(N1,LOW);
	digitalWrite(N2,LOW);
}

void L298N::motorRightstop(){
	analogWrite(ENB,LOW_PWM);
	digitalWrite(N3,LOW);
	digitalWrite(N4,LOW);
}

#endif



