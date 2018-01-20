#include "DriveTrain.h"
#include "../RobotMap.h"

#include <Commands/Subsystem.h>
#include <Drive/DifferentialDrive.h>

#include "Robot.h"

using namespace frc;

DriveTrain::DriveTrain() : Subsystem("ExampleSubsystem")
{

}

void DriveTrain::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

/* Setting the drive train to arcade drive.*/
void DriveTrain::Drive(double left, double right)
{
	drive.ArcadeDrive(left, right);
}

/* Getting value from Xbox Controller.*/
void DriveTrain::TeleopDrive(XboxController* controller)
{
	double joystick = value;

	Drive(-controller->GetX(GenericHID::kLeftHand),
			-controller->GetY(GenericHID::kLeftHand));
}

/* Limit function, if the vale of the the motors
 * goes over 0.5 set the value of the motors to 0.5.
 * If the value of the motors goes under -0.5,
 * set the value of the motors to -0.5.*/
void DriveTrain::Limit(double upperLimit, double lowerLimit, double value)
{
	if(value >= upperLimit)
	{
		value = upperLimit;
		return value;
	}
	if(value <= lowerLimit)
	{
		value = lowerLimit;
		return value;
	}
	else
	{
		return value;
	}
}

/* Resets the motor values to 0.*/
void DriveTrain::Reset()
{

}
