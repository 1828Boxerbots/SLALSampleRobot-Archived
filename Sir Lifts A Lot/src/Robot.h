/*
 * Robot.h
 *
 *  Created on: Jan 20, 2018
 *      Author: 1828 Boxerbots
 */

#ifndef ROBOT_H_
#define ROBOT_H_

#include "Commands/ExampleCommand.h"
#include "Commands/MyAutoCommand.h"

#include "RobotMap.h"
#include "OI.h"

#include <Talon.h>
#include <XboxController.h>
#include <TimedRobot.h>

#include <Subsystems/DriveTrain.h>
#include <Drive/DifferentialDrive.h>
#include <Commands/Subsystem.h>
#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

using namespace std;

class Robot : public frc::TimedRobot
{
public:

	static shared_ptr<DriveTrain> drivetrain;

private:
	void RobotInit() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
};

#endif /* ROBOT_H_ */
