#ifndef EnablePowerManagement_H
#define EnablePowerManagement_H

#include "../CommandBase.h"
#include "WPILib.h"

class EnablePowerManagement: public CommandBase
{
public:
	EnablePowerManagement();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
