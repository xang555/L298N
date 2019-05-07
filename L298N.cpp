#include "L298N.h"
#ifndef LOW_PWM
#define LOW_PWM 0

L298N::L298N(){/*init constructor*/};

/**
 * constructor function 
 * params map arduino pin to pin L298N module
 * 
 * ena -> ENA  or PWM pin motor left
 * n1 -> N1
 * n2 -> N2
 * n3 -> N3
 * n4 -> N4
 * enb -> ENB or PWM pin right
 */
L298N::L298N(uint8_t ena, uint8_t n1, uint8_t n2, uint8_t n3, uint8_t n4, uint8_t enb)
{
	this->ENA = ena;
	this->ENB = enb;
	this->N1 = n1;
	this->N2 = n2;
	this->N3 = n3;
	this->N4 = n4;
}

/**
 * initial arduino pin
 */
void L298N::begin()
{
	pinMode(ENA, OUTPUT);
	pinMode(ENB, OUTPUT);
	pinMode(N1, OUTPUT);
	pinMode(N2, OUTPUT);
	pinMode(N3, OUTPUT);
	pinMode(N4, OUTPUT);
}

/**
 * monit left (determine on README) trun right to left (Forward Clock)
 * by specify speed (PWM) 0 - 255
 */
void L298N::motorLeftForwardClock(uint8_t PWM)
{
	analogWrite(ENA, PWM);
	digitalWrite(N1, HIGH);
	digitalWrite(N2, LOW);
}

/**
 * monit right (determine on README) trun right to left (Forward Clock)
 * by specify speed (PWM) 0 - 255
 */
void L298N::motorRightForwardClock(uint8_t PWM)
{
	analogWrite(ENB, PWM);
	digitalWrite(N3, HIGH);
	digitalWrite(N4, LOW);
}

/**
 * monit left (determine on README) trun left to right (revert Clock)
 * specify speed (PWM) is 0(0%) - 255(100%)
 */
void L298N::motorLeftRevertClock(uint8_t PWM)
{
	analogWrite(ENA, PWM);
	digitalWrite(N1, LOW);
	digitalWrite(N2, HIGH);
}

/**
 * monit right (determine on README) trun left to right (revert Clock)
 * specify speed (PWM) is 0(0%) - 255(100%)
 */
void L298N::motorRightRevertClock(uint8_t PWM)
{
	analogWrite(ENB, PWM);
	digitalWrite(N3, LOW);
	digitalWrite(N4, HIGH);
}

/**
 * monit left (determine on README) break
 * specify break speed (PWM) is 0(0%) - 255(100%)
 * smooth break
 */
void L298N::motorLeftbreak(uint8_t PWM)
{
	analogWrite(ENA, PWM);
	digitalWrite(N1, HIGH);
	digitalWrite(N2, HIGH);
}

/**
 * monit right (determine on README) break
 * specify break speed (PWM) is 0(0%) - 255(100%)
 * smooth break
 */
void L298N::motorRightbreak(uint8_t PWM)
{
	analogWrite(ENB, PWM);
	digitalWrite(N3, HIGH);
	digitalWrite(N4, HIGH);
}

/**
 * monit left (determine on README) stop
 */
void L298N::motorLeftstop()
{
	analogWrite(ENA, LOW_PWM);
	digitalWrite(N1, LOW);
	digitalWrite(N2, LOW);
}

/**
 * monit right (determine on README) stop
 */
void L298N::motorRightstop()
{
	analogWrite(ENB, LOW_PWM);
	digitalWrite(N3, LOW);
	digitalWrite(N4, LOW);
}

#endif
