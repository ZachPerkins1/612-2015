/*
 * Robot.h
 *
 *  Created on: Jan 26, 2015
 *      Author: zachary
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

#include "Commands/Move.h"

class Robot: public IterativeRobot
{
private:
	LiveWindow* lw;
	Drivetrain* drivetrain;
	Joystick* joy;
	//Move* move;
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
	float getValues(int);
	void MecDrive(float x,float y,float rotation);
};

#endif /* SRC_ROBOT_H_ */
