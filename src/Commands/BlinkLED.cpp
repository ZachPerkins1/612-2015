#include "BlinkLED.h"

BlinkLED::BlinkLED()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(led);
	timer = new Timer();
}

// Called just before this Command runs the first time
void BlinkLED::Initialize()
{
	timer->Start();
	state = 0;
}

// Called repeatedly when this Command is scheduled to run
void BlinkLED::Execute()
{
	if (timer->Get() > 1.0)
	{
		state++;
		timer->Reset();
	}

	switch(state)
	{
	case 0:
		led->ledOn(1);
		break;
	case 1:
		led->ledOn(2);
		led->ledOff(1);
		break;
	case 2:
		led->ledOn(3);
		led->ledOff(2);
		break;
	case 3:
		led->ledOff(3);
		break;
	default:
		state = 0;
	}
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
	timer->Stop();
}
