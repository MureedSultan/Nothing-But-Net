task usercontrol {
	while(1){
		motor[DriveLeft] =  -vexRT[Ch2] + vexRT[Ch1];
		motor[DriveRight] = +vexRT[Ch2] + vexRT[Ch1];

		//----------------------
		//			Launcher
		//----------------------
		if(vexRT[Btn7D] == 1){
			//FwSetGain(0.00025);
			FwMaxPower(105);
			motorSpeed = 1;
			FwVelocitySet( &flywheel, 2400, motorSpeed);
			}else if(vexRT[Btn7R] == 1){
			motorSpeed = 0;
			FwVelocitySet( &flywheel, 0, motorSpeed);
			}else if(vexRT[Btn7L] == 1){
			FwMaxPower(82);
			motorSpeed = 0.9;
			FwVelocitySet( &flywheel, 1950, motorSpeed);
			}else if(vexRT[Btn7U] == 1){
			FwMaxPower(115);
			motorSpeed = 0.7;
			FwVelocitySet( &flywheel, 1450, motorSpeed);
			} else if(vexRT[Btn8D] == 1){
			motorSpeed = 0.9;
			FwVelocitySet( &flywheel, 2480, motorSpeed);
			}else if(vexRT[Btn8U] == 1) {
			FwMaxPower(70);
			motorSpeed = 0.4;
			FwVelocitySet( &flywheel, 1875, motorSpeed);
		}

		if(vexRT[Btn8L] == 1){
			SensorValue[Gyroscope] = 0;
			FwVelocitySet( &flywheel, 0, 0);
			Auton_Drive_Targeted(FORWARD, 400, 63);
			Auton_Drive_TurnTo(CLOCKWISE, -800, 45);
			Auton_Drive_Targeted(BACKWARD, 300, 63);
			Auton_Collect(90);
			wait1Msec(500);
			ResetDriveEncoders();
			Auton_Drive_Targeted(FORWARD, 2000, 70);
			wait1Msec(500);
			Auton_Drive_Targeted(FORWARD, 950, 70);
			Auton_Collect(0);
			wait1Msec(500);
			SensorValue[Gyroscope] = 0;
			Auton_Collect(-70, 250);
			Auton_Collect(0);
			FwMaxPower(70);
			FwVelocitySet( &flywheel, 1900, 1);
			Auton_Drive_TurnTo(COUNTERCLOCKWISE, 800, 45);
			wait1Msec(500);
			Auton_Drive_Targeted(BACKWARD, 150, 70);
			wait1Msec(1000);
			Auton_Collect(127);
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
		if(vexRT[Btn6U] == 1){
			if(motorSpeed == 1){
				motor[CollectionA] = 80;
				motor[CollectionB] = 127;
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
		if(vexRT[Btn8R] == 1){
			motor[CollectionA] = 100;
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
