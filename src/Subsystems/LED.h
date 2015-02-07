#ifndef LED_H
#define LED_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <DigitalOutput.h>

class LED: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	DigitalOutput* led1; //this on is red
	DigitalOutput* led2; //this one is green
	DigitalOutput* led3; //this one is blue
public:
	LED(uint32_t channel1, uint32_t channel2, uint32_t channel3);
	void InitDefaultCommand();

	void ledOn(int led);
	void ledOff(int led);
};

#endif
