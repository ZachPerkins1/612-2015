#ifndef PowerManagement_H
#define PowerManagement_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <vector>

class PowerManagement: public Subsystem
{
private:
	bool powerManagementOn = false;
	vector* motorControllers;
	vector* controllerStatus;

public:
	PowerManagement();
	void InitDefaultCommand();
	void setEnabled(bool isEnabled);
	void setDisableVoltage(float);
	void setEnableVoltage(float);
	bool isActive(SpeedController*);

};

#endif
