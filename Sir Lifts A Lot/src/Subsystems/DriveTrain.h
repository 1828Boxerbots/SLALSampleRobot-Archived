#ifndef DriveTrain_H
#define DriveTrain_H

#include <Talon.h>
#include <Drive/DifferentialDrive.h>

#include "OI.h"
#include "RobotMap.h"

#include <Commands/Subsystem.h>

using namespace frc;

class DriveTrain : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon m_drive_Train_Left {DRIVE_TRAIN_LEFT_MOTOR};
	Talon m_drive_Train_Right {DRIVE_TRAIN_RIGHT_MOTOR};

	DifferentialDrive drive {m_drive_Train_Left, m_drive_Train_Right};

public:
	DriveTrain();
	void InitDefaultCommand();
	void Drive(double left, double right);
	void TeleopDrive(XboxController* controller);
	void Limit(double);
};

#endif  // DriveTrain_H
