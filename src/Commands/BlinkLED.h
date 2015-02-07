#ifndef BlinkLED_H
#define BlinkLED_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../Subsystems/LED.h"

class BlinkLED: public CommandBase
{
public:
	BlinkLED();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
