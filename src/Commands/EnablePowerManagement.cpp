#include "EnablePowerManagement.h"

EnablePowerManagement::EnablePowerManagement()
{
	Requires(powermanagement);
}

// Called just before this Command runs the first time
void EnablePowerManagement::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void EnablePowerManagement::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool EnablePowerManagement::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void EnablePowerManagement::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void EnablePowerManagement::Interrupted()
{

}
