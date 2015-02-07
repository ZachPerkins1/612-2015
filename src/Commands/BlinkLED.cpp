#include "BlinkLED.h"

BlinkLED::BlinkLED()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(led);
}

// Called just before this Command runs the first time
void BlinkLED::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void BlinkLED::Execute()
{
	//Blink through all the colors, all of them!!!!!!!!
	led->ledOn(1); //red
	Wait(1);
	led->ledOff(1);
	Wait(1);
	led->ledOn(2); //green
	Wait(1);
	led->ledOff(2);
	Wait(1);
	led->ledOn(3); //blue
	Wait(1);
	led->ledOff(3);
	Wait(1);
}

// Make this return true when this Command no longer needs to run execute()
bool BlinkLED::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void BlinkLED::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BlinkLED::Interrupted()
{
	led->ledOff(1);
	led->ledOff(2);
	led->ledOff(3);
}
