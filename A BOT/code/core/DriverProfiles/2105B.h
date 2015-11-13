task usercontrol {
	int LastLeftU = 0;
	int LastLeftL = 0;
	int LastDriveInvert = 0;
	int Drive = 1;
	while(true){
		/*
		motor[DriveFrontRight] = vexRT[Ch4] - vexRT[Ch2] + vexRT[Ch1];
		motor[DriveRearRight] =  vexRT[Ch4] - vexRT[Ch2] - vexRT[Ch1];
		motor[DriveFrontLeft] = vexRT[Ch4] + vexRT[Ch2] + vexRT[Ch1];
		motor[DriveRearLeft] =  vexRT[Ch4] + vexRT[Ch2] - vexRT[Ch1];
		*/
		motor[DriveLeft] =  vexRT[Ch4] - vexRT[Ch2] ;
		motor[DriveRight] = -vexRT[Ch4] - vexRT[Ch2];
		//----------------------
		//			Launcher
		//----------------------
		if(vexRT[Btn7D] == 1){
			motorSpeed = 127;
			motor[LLT] = motorSpeed;
			motor[LLM] = motorSpeed;
			motor[LLB] = motorSpeed;
			motor[LRT] = motorSpeed;
			motor[LRM] = motorSpeed;
			motor[LRB] = motorSpeed;
			}else if(vexRT[Btn7R] == 1){
			motorSpeed = 0;
			motor[LLT] = motorSpeed;
			motor[LLM] = motorSpeed;
			motor[LLB] = motorSpeed;
			motor[LRT] = motorSpeed;
			motor[LRM] = motorSpeed;
			motor[LRB] = motorSpeed;
			}else if(vexRT[Btn7L] == 1){
			motorSpeed = 74;
			motor[LLT] = motorSpeed;
			motor[LLM] = motorSpeed;
			motor[LLB] = motorSpeed;
			motor[LRT] = motorSpeed;
			motor[LRM] = motorSpeed;
			motor[LRB] = motorSpeed;
			}else if(vexRT[Btn7U] == 1){
			motorSpeed = 64;
			motor[LLT] = motorSpeed;
			motor[LLM] = motorSpeed;
			motor[LLB] = motorSpeed;
			motor[LRT] = motorSpeed;
			motor[LRM] = motorSpeed;
			motor[LRB] = motorSpeed;
			} else {
			writeDebugStreamLine("Set speed: %d", motorSpeed);
		}

		//----------------------
		//		Speed Intervals
		//----------------------
		if(vexRT[Btn8D] == 1 && LastLeftU == 0) {
			Drive = -Drive;
			LastDriveInvert = 1;
			} else if(vexRT[Btn8D] == 0 && LastLeftU == 1) {
			LastDriveInvert = 0;
		}

		if(vexRT[Btn8U] == 1 && LastLeftU == 0) {
			motorSpeed = motorSpeed + 5;
			LastLeftU = 1;
			} else if(vexRT[Btn8U] == 0 && LastLeftU == 1) {
			LastLeftU = 0;
			} else {
			motor[LLT] = motorSpeed;
			motor[LLM] = motorSpeed;
			motor[LLB] = motorSpeed;
			motor[LRT] = motorSpeed;
			motor[LRM] = motorSpeed;
			motor[LRB] = motorSpeed;
		}

		if(vexRT[Btn8L] == 1 && LastLeftL == 0) {
			if(motorSpeed > 127){
				motorSpeed = 127;
				} else if(motorSpeed < 0){
				motorSpeed = 127;
			}
			motorSpeed = motorSpeed - 5;
			LastLeftL = 1;
			} else if(vexRT[Btn8L] == 0 && LastLeftL == 1) {
			LastLeftL = 0;
			} else {
			motor[LLT] = motorSpeed;
			motor[LLM] = motorSpeed;
			motor[LLB] = motorSpeed;
			motor[LRT] = motorSpeed;
			motor[LRM] = motorSpeed;
			motor[LRB] = motorSpeed;
		}
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
