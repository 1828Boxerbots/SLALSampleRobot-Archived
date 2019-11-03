/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>
#include <frc/XboxController.h>
#include <frc/Talon.h>
#include <frc/SampleRobot.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/DigitalInput.h>
#include <frc/AnalogInput.h>
#include <frc/interfaces/Potentiometer.h>
#include "RobotMap.h"

/**
 * This is a demo program showing the use of the DifferentialDrive class. The
 * SampleRobot class is the base of a robot application that will automatically
 * call your Autonomous and OperatorControl methods at the right time as
 * controlled by the switches on the driver station or the field controls.
 *
 * WARNING: While it may look like a good choice to use for your code if you're
 * inexperienced, don't. Unless you know what you are doing, complex code will
 * be much more difficult under this system. Use TimedRobot or Command-Based
 * instead if you're new.
 */
using namespace frc;
class Robot : public frc::SampleRobot 
{
 public:
  Robot();

  void RobotInit() override;
  void Autonomous() override;
  void OperatorControl() override;
  void Test() override;

 private:
  //Drivetrain
  Talon m_leftMotor{PWM_LEFT_DRIVE};
  Talon m_rightMotor{PWM_RIGHT_DRIVE};

  //Xbox Controller
  XboxController m_xbox{USB_CONTROLLER};

  //Lead Screws
  Talon m_leftLeadScrew{PWM_LEFT_SCREW};
  Talon m_rightLeadScrew{PWM_RIGHT_SCREW};

  //Arm
  Talon m_arm{PWM_ARM_MOTOR};

  //Limit Switches
  DigitalInput m_topLimit{DIO_TOP_LIMIT};
  DigitalInput m_bottomLimit{DIO_BOTTOM_LIMIT};

  //Potentiometer
  AnalogInput m_armPot{ANALOG_POT};

  //Compact Functions
  void Drive();
  void LeadScrew();
  void Arms();
};
