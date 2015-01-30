#include "CommandBase.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Commands/Scheduler.h"
#include "Subsystems/MecanumDrivetrain.h"
#include "Subsystems/Elevator.h"
#include "RobotMap.h"

// Initialize a single static instance of all of your subsystems to NULL
PowerBoard* powerboard = NULL;
OI* CommandBase::oi = NULL;
Elevator* CommandBase::elevator = NULL;
MecanumDrivetrain* CommandBase::drivetrain = NULL;
PowerManagement* CommandBase::powermanagement = NULL;

CommandBase::CommandBase(char const *name) :
		Command(name)
{

}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	examplesubsystem = new ExampleSubsystem();
	oi = new OI();
	elevator = new Elevator();
	drivetrain = new MecanumDrivetrain(MOTOR_LR, MOTOR_LF, MOTOR_RR, MOTOR_RF);
	powermanagement = new PowerManagement();
	powerboard = new PowerBoard();
}
