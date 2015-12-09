task usercontrol {
	int pnutoggle = 0;
	while(1){
		motor[DriveFrontLeft] =  -vexRT[Ch2] + vexRT[Ch1] +vexRT[Ch3] + vexRT[Ch4];
		motor[DriveRearLeft] =  -vexRT[Ch2] + vexRT[Ch1] +vexRT[Ch3] + vexRT[Ch4];
		motor[DriveFrontRight] = -vexRT[Ch2] - vexRT[Ch1] +vexRT[Ch3] - vexRT[Ch4];
		motor[DriveRearRight] = -vexRT[Ch2] - vexRT[Ch1] +vexRT[Ch3] - vexRT[Ch4];

		//----------------------
		//			Launcher
		//----------------------
		if(vexRT[Btn7D] == 1){
			motorSpeed = 0.60;
			FwVelocitySet( &flywheel, 2445, motorSpeed);
			}else if(vexRT[Btn7R] == 1){
			motorSpeed = 0;
			FwVelocitySet( &flywheel, 0, motorSpeed);
			}else if(vexRT[Btn7L] == 1){
			motorSpeed = 0.8;
			FwVelocitySet( &flywheel, 1900, motorSpeed);
			}else if(vexRT[Btn7U] == 1){
			motorSpeed = 0.66;
			FwVelocitySet( &flywheel, 1650, motorSpeed);
		}

		//if(vexRT[Btn8U] == 1) {
		//motor[CollectionB] = 127;
		//wait1Msec(800);
		//motor[CollectionB] = 0;
		//wait1Msec(1200);
		//}





		//----------------------
		//			Collectionion
		//----------------------
		if(vexRT[Btn6U] == 1){
			motor[CollectionA] =  127;
			motor[CollectionB] =  127;
			}else if(vexRT[Btn6D] == 1){
			motor[CollectionA] =  -127;
			motor[CollectionB] =  -127;
			}else{
			motor[CollectionA] =  0;
			motor[CollectionB] =  0;
		}
		if(vexRT[Btn6U] == 1){
			motor[CollectionA] =  127;
			}else if(vexRT[Btn6D] == 1){
			motor[CollectionA] =  -127;
			}else{
			motor[CollectionA] =  0;
		}

		if(vexRT[Btn5U] == 1){
			motor[CollectionB] =  127;
			}else if(vexRT[Btn5D] == 1){
			motor[CollectionB] =  -127;
			}else{
			motor[CollectionB] =  0;
		}

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
