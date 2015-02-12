#ifndef Drivetrain_H
#define Drivetrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <RobotDrive.h>
#include <CANTalon.h>

class Drivetrain: public Subsystem, public RobotDrive
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Drivetrain(CANTalon* fl,CANTalon* rl,CANTalon* fr,CANTalon* rr);
	void InitDefaultCommand();

	void move(float x, float y, float rotation);
	void stop();

	CANTalon* FL;
	CANTalon* RL;
	CANTalon* FR;
	CANTalon* RR;
};

#endif
