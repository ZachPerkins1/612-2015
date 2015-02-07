#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "Commands/Move.h"
#include "CommandBase.h"
#include "Robot.h"
#include "RobotMap.h"

void Robot::RobotInit()
{
	CommandBase::init();
	lw = LiveWindow::GetInstance();
	joy = new SmoothJoystick(0);
	blinkCommand = new BlinkLED();
	drivetrain = new Drivetrain();

	gyro = new Gyro(GYRO_CH); //todo
	//Remember to do this, and it must come after the drivetrain constructor call
}

void Robot::DisabledInit()
{

}

void Robot::DisabledPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit()
{

}

void Robot::AutonomousPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
	printf("Teleop Initialized \n");
	blinkCommand->Start();
	printf("Start Blinking!");
}

void Robot::TeleopPeriodic()
{
	static int interval = 0;
	//Get the values from the joystick
	float x = joy->GetModValue(LEFT_X);
	float y = joy->GetModValue(LEFT_Y);
	float rotation = joy->GetModValue(RIGHT_X);

	if(joy->GetModValue(LEFT_X) == 0.0f && joy->GetModValue(LEFT_Y) == 0.0f && joy->GetModValue(RIGHT_X) == 0.0f)
	{
		drivetrain->move(0.0f,0.0f,0.0f);
		printf("Drivetrain move now \n");
	}


	drivetrain->move(x,y,rotation);

	if (interval >= 30) //Prints every half second
	{
		printf("Robot facing %f degrees \n", gyro->GetAngle());
		interval = 0;
	}
	interval++;
	//moveCommand->Start();
	Scheduler::GetInstance()->Run();
}

void Robot::TestInit()
{

}

void Robot::TestPeriodic()
{
//	lw->Run();
}

float Robot::getValues(int axis)
{
	printf("GetValues running now! \n");
	float val = joy->GetRawAxis(axis);
	if (axis < TOLORANCE && axis > -TOLORANCE)
	{
		return 0.0f;
	}
	else
	{
		if (axis == 0 || axis == 4)
		{
			return -val*THROTTLE;
		}
		else
		{
			return val*THROTTLE;
		}
	}
}

void Robot::MecDrive(float x, float y, float rotation)
{
}

START_ROBOT_CLASS(Robot);
