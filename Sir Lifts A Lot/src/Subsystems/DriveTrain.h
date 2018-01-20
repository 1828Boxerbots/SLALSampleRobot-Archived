#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include <Drive/DifferentialDrive.h>

#include <Talon.h>
#include <XboxController.h>

#include "Robot.h"

using namespace frc;

class DriveTrain : public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon m_drive_Train_Left {DRIVE_TRAIN_LEFT_MOTOR};
	Talon m_drive_Train_Right {DRIVE_TRAIN_RIGHT_MOTOR};

	DifferentialDrive drive {m_drive_Train_Left, m_drive_Train_Right};

	double upperLimit = 0.5;
	double lowerLimit = -0.5;
	double value;

public:
	DriveTrain();
	void InitDefaultCommand();
	void Drive(double left, double right);
	void TeleopDrive(XboxController* controller);
	void Limit(double upperLimit, double lowerLimit, double value);
	void Reset();
};

#endif  // DriveTrain_H
