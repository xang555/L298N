
#ifndef	MAX_PWM_SPEED
#define	MAX_PWM_SPEED	255

#include "Arduino.h"

class L298N {
	
	
	public :
	   L298N();
	   L298N(uint8_t ena,uint8_t n1,uint8_t n2,uint8_t n3,uint8_t n4,uint8_t enb); // init pin l298 motor driver
		void initmotor();
		void motorLeftForwardClock(uint8_t PWM);
		void motorLeftRevertClock(uint8_t PWM);
		void motorRightForwardClock(uint8_t PWM);
		void motorRightRevertClock(uint8_t PWM);
		void motorLeftstop();
		void motorRightstop();
		void motorLeftbreak(uint8_t PWM);
		void motorRightbreak(uint8_t PWM);
		
	private :
		uint8_t ENA;
		uint8_t N1;
		uint8_t N2;
		uint8_t N3;
		uint8_t N4;
		uint8_t ENB; 
	
};

#endif
