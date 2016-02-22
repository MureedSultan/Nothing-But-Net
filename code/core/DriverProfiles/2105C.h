task usercontrol {
	int pnutoggle = 0;
	while(1){
		motor[DriveFrontLeft] =  -vexRT[Ch2] + vexRT[Ch1] + vexRT[Ch3] + vexRT[Ch4];
		motor[DriveRearLeft] =  -vexRT[Ch2] + vexRT[Ch1] + vexRT[Ch3] + vexRT[Ch4];
		motor[DriveFrontRight] = vexRT[Ch2] + vexRT[Ch1] - vexRT[Ch3] + vexRT[Ch4];
		motor[DriveRearRight] = vexRT[Ch2] + vexRT[Ch1] - vexRT[Ch3] + vexRT[Ch4];

		//----------------------
		//			Launcher
		//----------------------
		if(vexRT[Btn7D] == 1){
			FwMaxPower(80);
			motorSpeed = 1;
			FwVelocitySet( &flywheel, 2400, motorSpeed);
			}else if(vexRT[Btn7R] == 1){
			motorSpeed = 0;
			FwVelocitySet( &flywheel, 0, motorSpeed);
			}else if(vexRT[Btn7L] == 1){
			FwMaxPower(68);
			motorSpeed = 0.9;
			FwVelocitySet( &flywheel, 2050, motorSpeed);
			}else if(vexRT[Btn7U] == 1){
			FwMaxPower(52);
			motorSpeed = 0.5;
			FwVelocitySet( &flywheel, 1700, motorSpeed);
			}else if(vexRT[Btn8U] == 1) {
			FwMaxPower(63);
			motorSpeed = 0.4;
			FwVelocitySet( &flywheel, 1950, motorSpeed);
		}

		//----------------------
		//			Collection
		//----------------------
		if(vexRT[Btn6U] == 1){
			if(motorSpeed == 1){
				motor[CollectionA] = 127;
				motor[CollectionB] =  127;
				} else {
				motor[CollectionA] = 127;
				motor[CollectionB] =  127;
			}
			}else if(vexRT[Btn6D] == 1){
			motor[CollectionA] =  -127;
			motor[CollectionB] =  -127;
			}else{
			motor[CollectionA] =  0;
			motor[CollectionB] =  0;
		}

		if(vexRT[Btn5U] == 1){
			motor[CollectionB] =  127;
			}else if(vexRT[Btn5D] == 1){
			motor[CollectionB] =  -127;
		}

		//----------------------
		//			Pnumatics
		//----------------------
		if(vexRT[Btn8D] == 1 && pnutoggle == 0) {
			SensorValue[pnu_l] = 1;
			SensorValue[pnu_r] = 1;
			SensorValue[pnu_lift3] = 1;
			pnutoggle = 1;
			} else if(vexRT[Btn8D] == 0 && pnutoggle == 1) {
			SensorValue[pnu_l] = 0;
			SensorValue[pnu_r] = 0;
			SensorValue[pnu_lift3] = 0;
			pnutoggle = 0;
		}
		if(vexRT[Btn8L] == 1){
			SensorValue[pnu_lift1] = 1;
			SensorValue[pnu_lift2] = 1;
			} else {
			SensorValue[pnu_lift1] = 0;
			SensorValue[pnu_lift2] = 0;
		}

		//----------------------
		//		Driver Skills
		//----------------------
		if(vexRT[Btn8R] == 1){
			SensorValue[Gyroscope] = 0;
			Auton_Collect();
			FwVelocitySet( &flywheel, 0, 0);
			Auton_Drive_Targeted(FORWARD, 300, 127);
			Auton_Drive_TurnTo(CLOCKWISE, -800, 80);
			Auton_Drive_Targeted(BACKWARD, 300, 127);
			wait1Msec(500);
			ResetDriveEncoders();
			Auton_Drive_Targeted(FORWARD, 1800, 127);
			wait1Msec(500);
			Auton_Drive_Targeted(FORWARD, 950, 120);
			wait1Msec(500);
			SensorValue[Gyroscope] = 0;
			Auton_Collect(-100, -100,250);
			Auton_Collect(0, 0);
			FwMaxPower(65);
			FwVelocitySet( &flywheel, 1900, 0.4);
			Auton_Drive_TurnTo(COUNTERCLOCKWISE, 940, 65);
			wait1Msec(500);
			Auton_Drive_Targeted(BACKWARD, 130);
			wait1Msec(1000);
			Auton_Collect();
		}

	}
}
