#ifndef LatchOpen_H
#define LatchOpen_H

// This file is incorrectly named.  Compare the class name below with the file name.
// This does not follow the standard of how we name files.
// use git mv <oldfile> <newfile> to change the name of this file.

#include "RobotMap.h"
#include "../CommandBase.h"
#include "WPILib.h"
#include <Timer.h>
#include "DoubleSolenoid.h"

class LatchOpen: public CommandBase
{
public:
	Timer* timer;
	LatchOpen();
	void Initialize();
	void End();
private:
	DoubleSolenoid* firstsolenoid;
	DoubleSolenoid* secondsolenoid;
};

#endif
