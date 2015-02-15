#include <Commands/Latch.h>

// this file is incorrectly named.
// The Subsystem file might be named Latch.cpp
// This command should not be Latch.cpp (look at the name of the command!)
// use git mv <oldfile> <newfile> to change the name of this file.

/** Called just before this Command runs the first time

 * This is run after the constructor.  The initialization code could be done here, too.
 * In many cases, this method is no different than the constructor, so adding code here
 * is not always necessary.
 */
void LatchOpen::Initialize()
{
	timer = new Timer();
	// the following two lines are incorrect.
	// examine https://chantilly612code.github.io/612-2015/class_double_solenoid.html
	// to understand why.
	firstsolenoid = new DoubleSolenoid(FIRST_SOLENOID);
	secondsolenoid = new DoubleSolenoid(SECOND_SOLENOID);
	firstsolenoid->Set(DoubleSolenoid::Value::kForward);
	secondsolenoid->Set(DoubleSolenoid::Value::kForward);
	timer->Start();
	End();
}

// clean-up method
void LatchOpen::End()
{
	if(timer->Get() >= 1.0)
	{
		firstsolenoid->Set(DoubleSolenoid::Value::kOff);
		firstsolenoid->Set(DoubleSolenoid::Value::kOff);
	}
	else
	{
		End();
	}
}

