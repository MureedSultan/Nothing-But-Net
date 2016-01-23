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
			FwMaxPower(105);
			motorSpeed = 1;
			FwVelocitySet( &flywheel, 2450, motorSpeed);
			}else if(vexRT[Btn7R] == 1){
			motorSpeed = 0;
			FwVelocitySet( &flywheel, 0, motorSpeed);
			}else if(vexRT[Btn7L] == 1){
			FwMaxPower(88);
			motorSpeed = 1;
			FwVelocitySet( &flywheel, 2000, motorSpeed);
			}else if(vexRT[Btn7U] == 1){
			motorSpeed = 0.7;
			FwVelocitySet( &flywheel, 1565, motorSpeed);
			}else if(vexRT[Btn8U] == 1) {
			FwMaxPower(72);
			motorSpeed = 1;
			FwVelocitySet( &flywheel, 1850, motorSpeed);
		}

		//----------------------
		//			Collection
		//----------------------
		if(vexRT[Btn6U] == 1 && vexRT[Btn6D] == 1){
			motor[CollectionA] =  127;
			motor[CollectionB] =  70;
			}else if(vexRT[Btn6U] == 1){
			motor[CollectionA] = 127;
			motor[CollectionB] =  127;
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
			}else{
			if(vexRT[Btn6U] == 1){
				motor[CollectionB] =  127;
			}
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
			Auton_Drive_Targeted(FORWARD, 200, 100);
			Auton_Drive_TurnTo(CLOCKWISE, -800, 65);
			Auton_Drive_Targeted(BACKWARD, 300, 100);
			wait1Msec(500);
			ResetDriveEncoders();
			Auton_Drive_Targeted(FORWARD, 2000, 100);
			wait1Msec(500);
			Auton_Drive_Targeted(FORWARD, 850, 100);
			wait1Msec(500);
			SensorValue[Gyroscope] = 0;
			Auton_Collect(-70, 250);
			Auton_Collect(0);
			FwMaxPower(72);
			FwVelocitySet( &flywheel, 1870, 1);
			Auton_Drive_TurnTo(COUNTERCLOCKWISE, 900, 65);
			wait1Msec(500);
			Auton_Drive_Targeted(BACKWARD, 150, 60);
			wait1Msec(1000);
			Auton_Collect(127);
		}

	}
}
