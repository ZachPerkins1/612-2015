#include "PowerManagement.h"
#include "../RobotMap.h"


PowerManagement::PowerManagement() :
		Subsystem("ExampleSubsystem")
{

}

void PowerManagement::InitDefaultCommand()
{
	SetDefaultCommand(new DisablePowerManagement());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
