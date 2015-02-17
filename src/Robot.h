#ifndef ROBOT_H
#define ROBOT_H

#include <WPILib.h>
#include <Joystick.h>
#include <Compressor.h>
#include <CANTalon.h>
#include <DoubleSolenoid.h>
#include <Solenoid.h>

class Robot: public IterativeRobot
{
private:
	Joystick* joystick;
	Joystick* gun;
	//all acceleration is measured in meters per second squared
	// Used for speedgun, a accelerometer
	RobotDrive* drivetrain;
	Robot* robot;
	CANTalon* lift;
	Compressor* compressor;
	CANTalon* fl;
	CANTalon* fr;
	CANTalon* rl;
	CANTalon* rr;
	DoubleSolenoid* sol;
	Solenoid* sol2;
	/*
	Encoder* frontLeft;
	Encoder* frontRight;
	Encoder* rearLeft;
	Encoder* rearRight;
	*/
public:
	void RobotInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestInit();
	void TestPeriodic();
	void DisabledInit();
	void DisabledPeriodic();

	//612 functions
	void TestPulley();
	float getInput(uint32_t, Joystick* g);
	//612 Objects
	enum ROBOT_STATUS{
		NONE,
		ROBOTINIT,
		DISABLEDINIT,
		DISABLEDPERIODIC,
		AUTONOMOUSINIT,
		AUTONOMOUSPERIODIC,
		TELEOPINIT,
		TELEOPPERIODIC,
		TESTINIT,
		TESTPERIODIC
	};
	enum CLAMP_POS{
		OPEN,
		CLOSE
	};
	ROBOT_STATUS robot_status;
};
#endif
