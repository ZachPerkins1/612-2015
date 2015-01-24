#ifndef DisablePowerManagement_H
#define DisablePowerManagement_H

#include "../CommandBase.h"
#include "WPILib.h"

class DisablePowerManagement: public CommandBase
{
public:
	DisablePowerManagement();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
