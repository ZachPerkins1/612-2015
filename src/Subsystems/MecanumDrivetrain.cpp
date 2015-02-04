#include "MecanumDrivetrain.h"
#include "../RobotMap.h"
#include <Talon.h>
#include <MotorSafetyHelper.h>

MecanumDrivetrain::MecanumDrivetrain(uint32_t talonchannel1,
		                             uint32_t talonchannel2,
		                             uint32_t talonchannel3,
		                             uint32_t talonchannel4):
		Subsystem("MecanumDrivetrain"),
		RobotDrive(new Talon(talonchannel1),
				   new Talon(talonchannel2),
				   new Talon(talonchannel3),
				   new Talon(talonchannel4))

{
	SetSafetyEnabled(true);
	SetExpiration(MOTOR_EXPIRATION);
	std::printf("Expiration = %f", GetExpiration());
	//import trackball or something? idk.
}

void MecanumDrivetrain::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new Drive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void MecanumDrivetrain::move(float magnitude, float direction, float rotation)
{
	MecanumDrive_Polar(magnitude, direction, rotation);
	m_safetyHelper->Feed();
}

void MecanumDrivetrain::stop()
{
	MecanumDrive_Polar(0.0f, 0.0f, 0.0f);
	m_safetyHelper->Feed();
}

bool MecanumDrivetrain::switchSense(float d)// inf is on by default
{
	if(d < 6){// switch to infrard m8
		return true;
	}else{
		return false;
	}
}

void MecanumDrivetrain::switchSense(float d)// inf is on by default
{
	switchSense(d) ? (sensor = ultra) : (sensor = infrared);// switch sensors
}




