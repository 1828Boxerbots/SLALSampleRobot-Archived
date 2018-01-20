#include "DriveTrain.h"
#include "../RobotMap.h"

#include <Talon.h>

using namespace frc;

DriveTrain::DriveTrain() : Subsystem("ExampleSubsystem") {

}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveTrain::Drive(double left, double right)
{
	drive.ArcadeDrive(left, right);
}

void DriveTrain::TeleopDrive(XboxController* controller)
{
	Drive(-controller->GetX(GenericHID::kLeftHand),
			-controller->GetY(GenericHID::kLeftHand));
}

void DriveTrain::Limit(double)
{
	if(TeleopDrive > 0.5)
	{
		TeleopDrive = 0.5;
	}
	if(TeleopDrive < -0.5)
	{
		TeleopDrive = -0.5;
	}
	else
	{
		return;
	}
}
