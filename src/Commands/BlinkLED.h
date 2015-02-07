#ifndef BlinkLED_H
#define BlinkLED_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../Subsystems/LED.h"
#include <Timer.h>

class BlinkLED: public CommandBase
{
private:
	Timer* timer;
	int state;
public:
	BlinkLED();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
