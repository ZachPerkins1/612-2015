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
	bool powerManagementOn = false; //System only runs when this is true
	std::vector<Talon> motorControllers; //Keeps track of all the motor controllers being logged
	std::vector<bool> controllerStatus; //Keeps track of the status of those motor controllers

public:
	PowerManagement();
	void InitDefaultCommand();
	void setEnabled(bool isEnabled); //Sets the power management system as disabled or enabled
	void setDisableVoltage(float); //Sets the voltage that will start turning components off
	void setEnableVoltage(float); //Sets the voltage at which systems may be re-enabled
	bool isActive(SpeedController*); //Returns if the given speed controller is enabled
	void addSpeedController(SpeedController*); //Adds a speed controller to be disabled when power usage is too high

};

#endif
