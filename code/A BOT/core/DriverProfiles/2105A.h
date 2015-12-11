task usercontrol {
	//int motorSpeed = 0;
int LastLeftU = 0;
int LastLeftL = 0;
	while(true){
		motor[DriveFrontRight] = vexRT[Ch4] - vexRT[Ch2] - vexRT[Ch1];
		motor[DriveRearRight] =  vexRT[Ch4] - vexRT[Ch2] + vexRT[Ch1];
		motor[DriveFrontLeft] = vexRT[Ch4] + vexRT[Ch2] + vexRT[Ch1];
		motor[DriveRearLeft] =  vexRT[Ch4] + vexRT[Ch2] - vexRT[Ch1];
		//----------------------
		//			Launcher
		//----------------------
		if(vexRT[Btn7D] == 1){
			motorSpeed = 113;
			nMotorPIDSpeedCtrl[LeftA] = mtrSpeedReg;
			nMotorPIDSpeedCtrl[RightA] = mtrSpeedReg;
			nMotorPIDSpeedCtrl[LeftB] = mtrSpeedReg;
			nMotorPIDSpeedCtrl[RightB] = mtrSpeedReg;
			slaveMotor(RightB, RightA);
			slaveMotor(LeftB, LeftA);
			motor[LeftA] = motorSpeed;
			motor[RightA] = motorSpeed;
			startTask(launchSound);
			}else if(vexRT[Btn7R] == 1){
			motorSpeed = 0;
			motor[LeftA] = motorSpeed;
			motor[LeftB] = motorSpeed;
			motor[RightA] = motorSpeed;
			motor[RightB] = motorSpeed;
			stopTask(launchSound);
			}else if(vexRT[Btn7L] == 1){
			motorSpeed = 98;
			motor[LeftA] = motorSpeed;
			motor[LeftB] = motorSpeed;
			motor[RightA] = motorSpeed;
			motor[RightB] = motorSpeed;
			startTask(launchSound);
			}else if(vexRT[Btn7U] == 1){
			motorSpeed = 84;
			motor[LeftA] = motorSpeed;
			motor[LeftB] = motorSpeed;
			motor[RightA] = motorSpeed;
			motor[RightB] = motorSpeed;
			startTask(launchSound);
			} else {
			writeDebugStreamLine("Set speed: %d", motorSpeed);
		}


		if(vexRT[Btn8U] == 1 && LastLeftU == 0) {
			motorSpeed = motorSpeed + 5;
			LastLeftU = 1;
			} else if(vexRT[Btn8U] == 0 && LastLeftU == 1) {
			LastLeftU = 0;
		} else {
			motor[LeftA] = motorSpeed;
			motor[LeftB] = motorSpeed;
			motor[RightA] = motorSpeed;
			motor[RightB] = motorSpeed;
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
			motor[LeftA] = motorSpeed;
			motor[LeftB] = motorSpeed;
			motor[RightA] = motorSpeed;
			motor[RightB] = motorSpeed;
		}

		//----------------------
		//			Collection
		//----------------------
		if(vexRT[Btn5U] == 1){
			motor[CollectionB] =  127;
			}else if(vexRT[Btn5D] == 1){
			motor[CollectionB] =  -127;
			}else{
			motor[CollectionB] =  0;
		}
		if(vexRT[Btn6U] == 1){
			motor[CollectionA] =  127;
			}else if(vexRT[Btn6D] == 1){
			motor[CollectionA] =  -127;
			}else{
			motor[CollectionA] =  0;
		}
		//----------------------
		//				Brake
		//----------------------
		if(vexRT[Btn8D] == 1){
			SensorValue[Brake1] = 1;
			SensorValue[Brake2] = 1;
			}else if(vexRT[Btn8R] == 1){
			SensorValue[Brake1] = 0;
			SensorValue[Brake2] = 0;
		}

	}
}
