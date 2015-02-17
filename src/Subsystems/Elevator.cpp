#include "Elevator.h"
#include <cmath>

Elevator::Elevator() :
	Subsystem("Elevator")
{
	talon = new CANTalon(ELEVATOR_MOTOR_1);
#ifdef TALON
	talon2 = new CANTalon(ELEVATOR_MOTOR_2);
#endif
	//topSwitch = new DigitalInput(ELEVATOR_TOP_SWITCH);
	//bottomSwitch = new DigitalInput(ELEVATOR_BOTTOM_SWITCH);
	encoder = new Encoder(ELEVATOR_ENCODER_A, ELEVATOR_ENCODER_B);
	leftIR = new AnalogInput(LEFT_IR);
	rightIR = new AnalogInput(RIGHT_IR);
	sense = IR; //default to IR sensor
	ultrasonic = new AnalogInput(ELEVATOR_ULTRASONIC);
	//elevatorIR = new AnalogInput(ELEVATOR_IR); We need 2, not 1
	latchSol = new DoubleSolenoid(SOLENOIDCHAN1, SOLENOIDCHAN2);
	leftLedGreen = new DigitalOutput(L_ELEVATOR_LED_GREEN); //LEDs to show if we're aligned
	leftLedRed = new DigitalOutput(L_ELEVATOR_LED_RED);
	rightLedGreen = new DigitalOutput(R_ELEVATOR_LED_GREEN);
	rightLedRed = new DigitalOutput(R_ELEVATOR_LED_RED);
}

Elevator::~Elevator()
{
	delete talon;
#ifdef TALON
	delete talon2;
#endif
}

void Elevator::InitDefaultCommand()
{
	//SetDefaultCommand(new ElevatorUp());
}

void Elevator::move(float magnitude)
{
	/*
	//Checks the sensors to see if the elevator is at the top or the bottom
	bool topInput = topSwitch->Get();
	bool bottomInput = bottomSwitch->Get();

	//If the sensors give any input then the elevator can't be moved more that way, so don't move
	if (topInput || bottomInput)
	{
		talon->Set(0);
		talon2->Set(0);
	}
	else
	{

		talon->Set(magnitude);
		talon2->Set(magnitude);
	}
	static int count = 0;
	if (count % 60 == 0)
	{
		printf("Elevator motor moved! Speed = %f", magnitude);
	}
	*/
	talon->Set(magnitude);
#ifdef TALON
	talon2->Set(magnitude);
#endif
}

void Elevator::stop()
{
	//Sets motor speed to nothing
	talon->Set(0);
#ifdef TALON
	talon2->Set(0);
#endif
	printf("Stop elevator motor");
}

Encoder* Elevator::getEncoder()
{
	return NULL;//encoder;
}

bool Elevator::getLeftAlignment()
{

	/* float val = leftIR->GetVoltage();
	val = IRVoltageToDistance(val);
	float dist = 0.0f;
	if (val >= (dist - BUFFER) && val <= (dist + BUFFER)) //Distance to ground +/- 2 inches TODO
	{
		printf("Crate not found\n");
		leftLedGreen->Set(1); //green light on
		leftLedRed->Set(0);
		return false;
	}
	printf("Crate found\n");
	leftLedRed->Set(1);
	leftLedGreen->Set(0);
	return true;
*/
	return false;
}

bool Elevator::getRightAlignment()
{
/*
	float val = rightIR->GetVoltage();
	val = IRVoltageToDistance(val); //TODO test to make sure this works
	float dist = getElevatorHeight(); //This should work make sure it does
	
	if (val >= (dist - BUFFER) && val <= (dist + BUFFER)) //Distance to ground +/- 2 inches (buffer) TODO
	{
		printf("Crate not found\n");
		rightLedGreen->Set(1);
		rightLedRed->Set(0);
		return false;
	}
	rightLedRed->Set(1); //make LED red
	rightLedGreen->Set(0); //turn off Green LED
	*/
	return true;
}

float Elevator::IRVoltageToDistance(float val)
{
	return (pow((4187.8/val),1.1060))/2.54; //make sure this is right, make sure it returns INCHES
}

float Elevator::getElevatorHeight()
{
	if (sense == IR)
	{
		//float voltage = 1.0f;
		float l = leftIR->GetVoltage();
		float r = rightIR->GetVoltage();
		return IRVoltageToDistance((l+r)/2.0); //returns average of the two sensors
	}
	else
	{
		float voltage = ultrasonic->GetVoltage();
		return UltrasonicVoltageToDistance(voltage);
	}
}

float Elevator::UltrasonicVoltageToDistance(float voltage)
{
	//int16_t inputVoltage = ultrasonic->GetValue(); //Zach said this should always be 5, so I'll try that
	float voltsPerInch = 5.0/512.0; //Very small number
	voltsPerInch *= 1000; //converts to milliVolts
	//formula from here: http://www.maxbotix.com/articles/032.htm confused by it
	return voltage/voltsPerInch; //TODO test to make sure this works
	
}

Elevator::MainSensor Elevator::switchSensor(float IRDistance, float UDistance)
{
	if(IRDistance > MAX_IR)
	{
		return ULTRASONIC;
	}
	else if(UDistance < MIN_ULTRA)
	{
		return IR;
	}
	else //Buffer zone
	{
		return sense; //doesn't change
	}
}

DoubleSolenoid* Elevator::getSolenoid()
{
	return latchSol;
}

