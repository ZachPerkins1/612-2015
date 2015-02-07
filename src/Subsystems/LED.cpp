#include "LED.h"
#include "../RobotMap.h"

LED::LED(uint32_t channel1, uint32_t channel2, uint32_t channel3) :
		Subsystem("LED")
{
	led1 = new DigitalOutput(channel1);
	led2 = new DigitalOutput(channel2);
	led3 = new DigitalOutput(channel3);
}

void LED::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void LED::ledOn(int led)
{
	switch(led)
	{
	case 1:
		led1->Set(1);
		//printf("Red light \n");
		break;
	case 2:
		led2->Set(1);
		//printf("Green light \n");
		break;
	case 3:
		led3->Set(1);
		//printf("Blue light \n");
		break;
	default:
		printf("Invalid led number. \n");
	}
}

void LED::ledOff(int led)
{
	switch(led)
	{
	case 1:
		led1->Set(0);
		break;
	case 2:
		led2->Set(0);
		break;
	case 3:
		led3->Set(0);
		break;
	default:
		printf("Invalid led number. \n");
	}
}

//All hail the magestic pegacorn!
