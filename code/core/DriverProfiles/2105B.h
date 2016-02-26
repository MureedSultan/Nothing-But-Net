task usercontrol {
	int buttonToggleState = 0;
	int buttonPressed = 0;
	int drivemultiplier = 1;
	int dval = 0;
	int deadband = 10;
	while(1){
		//----------------------
		//			Drive
		//----------------------

		/*
		dval = (vexRT[Ch2] + (vexRT[Ch1] * drivemultiplier) + (vexRT[Ch3]*0.5) - (vexRT[Ch4]*0.5) * drivemultiplier) * drivemultiplier;
		motor[DriveRight]  = dval < deadband && dval > -deadband ? 0 : dval;
		dval = (-vexRT[Ch2] + (vexRT[Ch1] * drivemultiplier) - (vexRT[Ch3]*0.5) - (vexRT[Ch4]*0.5) * drivemultiplier) * drivemultiplier;
		motor[DriveLeft]  = dval < deadband && dval > -deadband ? 0 : dval;
		*/

		dval = ((vexRT[Ch2] * drivemultiplier) + (vexRT[Ch4]*0.5) * drivemultiplier);
		motor[DriveRight]  = dval < deadband && dval > -deadband ? 0 : dval;
		dval = ((-vexRT[Ch2] * drivemultiplier) + (vexRT[Ch4]*0.5) * drivemultiplier);
		motor[DriveLeft]  = dval < deadband && dval > -deadband ? 0 : dval;

		//----------------------
		//			Launcher
		//----------------------

		if(vexRT[Btn7D] == 1){
			//FwSetGain(0.00025);
			FwMaxPower(92);
			motorSpeed = 1;
			FwVelocitySet(&flywheel, 2380, 1);
			}else if(vexRT[Btn7R] == 1){
			motorSpeed = 0;
			FwVelocitySet( &flywheel, 0, motorSpeed);
			}else if(vexRT[Btn7L] == 1){
			FwMaxPower(82);
			motorSpeed = 0.9;
			FwVelocitySet( &flywheel, 1950, motorSpeed);
			}else if(vexRT[Btn7U] == 1){
			FwMaxPower(95);
			motorSpeed = 0.7;
			FwVelocitySet( &flywheel, 1460, motorSpeed);
			} else if(vexRT[Btn8D] == 1){
			motorSpeed = 0.9;
			FwVelocitySet( &flywheel, 2480, motorSpeed);
			}else if(vexRT[Btn8U] == 1) {
			FwMaxPower(72);
			FwGain(0.0005);
			motorSpeed = 0.5;
			FwVelocitySet( &flywheel, 1870, motorSpeed);
		}

		if(vexRT[Btn8L] == 1){
			SensorValue[Gyroscope] = 0;
			FwVelocitySet( &flywheel, 0, 0);
			Auton_Drive_Targeted(FORWARD, 400, 63);
			Auton_Drive_TurnTo(CLOCKWISE, -800, 45);
			Auton_Drive_Targeted(BACKWARD, 300, 63);
			Auton_Collect(80, 110);
			wait1Msec(500);
			ResetDriveEncoders();
			Auton_Drive_Targeted(FORWARD, 2000, 70);
			wait1Msec(1000);
			Auton_Drive_Targeted(FORWARD, 1030, 70);
			wait1Msec(500);
			SensorValue[Gyroscope] = 0;
			Auton_Collect(-127, 127);
			wait1Msec(1000);
			FwMaxPower(73);
			FwVelocitySet( &flywheel, 1900, 0.8);
			Auton_Drive_TurnTo(COUNTERCLOCKWISE, 850, 50);
			Auton_Drive_Targeted(BACKWARD, 200, 70);
			wait1Msec(500);
			Auton_Collect(127, 127);
		}

		/* ---------- CAT LAUNCHER -----------
		if(vexRT[Btn8L] == 1){
		motor[CatA] = 127;
		motor[CatB] = 127;
		} else {
		motor[CatA] = 0;
		motor[CatB] = 0;
		}
		//*/

		//----------------------
		//			Auto Drive thing
		//----------------------

		//----------------------
		//			Collection
		//----------------------

		if( vexRT[ Btn8R ] == 1 ){
			if( ! buttonPressed ){
				buttonToggleState = 1 - buttonToggleState;
				buttonPressed = 1;
			}
			}else{
			buttonPressed = 0;
		}

		if(buttonToggleState){
			drivemultiplier = -1;
			}else{
			drivemultiplier = 1;
		}

		if(vexRT[Btn6U] == 1){
			if(motorSpeed == 1){
				Auton_Collect(100, 127);
				wait1Msec(350);
				Auton_Collect(0, 127);
				wait1Msec(800);
				}else {
				motor[CollectionA] = 127;
				motor[CollectionB] = 127;
			}
			}else if(vexRT[Btn6D] == 1){
			motor[CollectionA] = -127;
			motor[CollectionB] = -127;
			}else{
			motor[CollectionA] = 0;
			motor[CollectionB] = 0;
		}
		if(vexRT[Btn5U] == 1){
			motor[CollectionB] =  127;
			}else if(vexRT[Btn5D] == 1){
			motor[CollectionB] =  -127;
		}

		//----------------------
		//		Driver Skills
		//----------------------
		/*
		if(vexRT[Btn5U] == 1){
		while(true){
		Auton_Launch();
		sleep(3000);
		Auton_Throw(63, 0, 4);
		while(true){
		Auton_Collect();
		}
		}
		}
		*/
	}
}
