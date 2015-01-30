#include "PowerManagement.h"
#include "../RobotMap.h"
#include "../CommandBase.h"

PowerManagement::PowerManagement() :
		Subsystem("ExampleSubsystem")
{

}

void PowerManagement::InitDefaultCommand()
{
	//SetDefaultCommand(new DisablePowerManagement());
	//TODO fix
}

void PowerManagement::Periodic()
{
	float voltage = CommandBase::powerboard->GetVoltage();
	if (componentsEnabled)
	{
		if (voltage > DISABLE_THRESHOLD)
		{
			componentsEnabled = false;
			//TODO Add logger for disabling of components
		}
	}
	else
	{
		if (voltage < ENABLE_THRESHOLD)
		{
			componentsEnabled = true;
			//TODO Add logger for enabling of components
		}
	}
}

void PowerManagement::setEnabled(bool isEnabled)
{

}

bool PowerManagement::isActive()
{
	return componentsEnabled;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
