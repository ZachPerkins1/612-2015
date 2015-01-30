#ifndef PowerManagement_H
#define PowerManagement_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <vector>

class PowerManagement: public Subsystem
{
/*
 * When the power of the system is too high, this subsystem
 * shuts off components that are not critical to the robot's
 * operation (ie, the elevator). This will be enabled at time s
 * when the robot is enabled for long periods, so that power
 * consumption is reduced to a minimum
 */

private:
	bool componentsEnabled = true; //System only runs when this is true

public:
	PowerManagement();
	void InitDefaultCommand();
	void setEnabled(bool isEnabled); //Sets the power management system as disabled or enabled
	void setThresholdVoltage(float, float); //Range in which it stays off
	bool isActive(); //Returns if the given speed controller is enabled
	void Periodic(); //For checking voltage. Used in enabling PowerManagement
};

#endif
