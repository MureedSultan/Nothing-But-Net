task usercontrol {
	//int motorSpeed = 0;
	int buttonToggleState = 0;
	int buttonPressed = 0;
	int drivemultiplier = 1;
	int dval = 0;
	int deadband = 10;
	int driverSetRpm = 0;
	while(true){
		//----------------------
		//			Drive
		//----------------------

		dval = (vexRT[Ch2] - vexRT[Ch1] + (vexRT[Ch3]*0.5) - (vexRT[Ch4]*0.5) * drivemultiplier) * drivemultiplier;
		motor[DriveRight]  = dval < deadband && dval > -deadband ? 0 : dval;
		dval = (-vexRT[Ch2] - vexRT[Ch1] - (vexRT[Ch3]*0.5) - (vexRT[Ch4]*0.5) * drivemultiplier) * drivemultiplier;
		motor[DriveLeft]  = dval < deadband && dval > -deadband ? 0 : dval;


		//----------------------
		//			Launcher
		//----------------------

		// HAMMER
		if( vexRT[ Btn8D ] == 1 ){
			if( ! buttonPressed ){
				buttonToggleState = 1 - buttonToggleState;
				buttonPressed = 1;
			}
			}else{
			buttonPressed = 0;
		}

		if(buttonToggleState){
			motor[CT] = 127;
			motor[CM] = 127;
			motor[CB] = 127;
			}else{
			motor[CT] = 0;
			motor[CM] = 0;
			motor[CB] = 0;
		}

		// FLYWHEEL
		if(vexRT[Btn7R] == 1){
			motorSpeed = 0;
			driverSetRpm = 0;
			FwVelocitySet( &flywheel, driverSetRpm, motorSpeed);
			}else if(vexRT[Btn7D] == 1){
			//FwSetGain(0.00025);
			FwMaxPower(127);
			motorSpeed = 1;
			driverSetRpm = 2450;
			FwVelocitySet( &flywheel, driverSetRpm, motorSpeed);
			}else if(vexRT[Btn7L] == 1){
			FwMaxPower(83);
			motorSpeed = 0.6;
			driverSetRpm = 1960;
			FwVelocitySet( &flywheel, driverSetRpm, motorSpeed);
			}else if(vexRT[Btn7U] == 1){
			FwMaxPower(83);
			motorSpeed = 0.8;
			FwVelocitySet( &flywheel, 1670, motorSpeed);
			}else if(vexRT[Btn8U] == 1){
			FwMaxPower(83);
			motorSpeed = 0.9;
			driverSetRpm = 1900;
			FwVelocitySet( &flywheel, driverSetRpm, motorSpeed);
		}

		//----------------------
		//			Collection
		//----------------------
		if(vexRT[Btn6U] == 1){
			if(flywheel.current >= (driverSetRpm - 25)){
				motor[CollectionA] = 127;
				motor[CollectionB] = 127;
			}

			}else if(vexRT[Btn6D] == 1){
			motor[CollectionA] = -127;
			motor[CollectionB] = -127;
			}else{
			motor[CollectionB] = 0;
			if(vexRT[Btn5U] == 1){
				motor[CollectionA] =  127;
				}else if(vexRT[Btn5D] == 1){
				motor[CollectionA] =  -127;
				} else {
				motor[CollectionA] =  0;
			}
		}

		//----------------------
		//		Driver Skills
		//----------------------

		if(vexRT[Btn8R] == 1){
			SensorValue[Gyroscope] = 0;
			Auton_Drive_Targeted(FORWARD, 160, 55);
			Auton_Drive_TurnTo(CLOCKWISE, -800, 45);
			Auton_Drive_Targeted(BACKWARD, 150, 63, 500);
			ResetDriveEncoders();
			Auton_Collect(70, 127);
			Auton_Drive_Targeted_PID(BACKWARD, 1245, 90);
			wait1Msec(1000);
			Auton_Drive_Targeted_PID(BACKWARD, 1125, 127);
			Auton_Collect(-70, 127);
			Auton_Drive_TurnTo_PID(CLOCKWISE, 60, 60, 5, 1000);
			Auton_Collect(0, 0);
			Auton_Drive_Targeted(BACKWARD, 150, 55);
		}

	}
}
