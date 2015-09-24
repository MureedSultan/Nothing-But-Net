task usercontrol {
	while(true){
		motor[DriveFrontRight] = vexRT[Ch4] - vexRT[Ch2] - vexRT[Ch1];
		motor[DriveRearRight] =  vexRT[Ch4] - vexRT[Ch2] + vexRT[Ch1];
		motor[DriveFrontLeft] = vexRT[Ch4] + vexRT[Ch2] + vexRT[Ch1];
		motor[DriveRearLeft] =  vexRT[Ch4] + vexRT[Ch2] - vexRT[Ch1];
		if(vexRT[Btn8U] == 1){
			nMotorPIDSpeedCtrl[LeftA] = mtrSpeedReg;
			nMotorPIDSpeedCtrl[RightA] = mtrSpeedReg;
			nMotorPIDSpeedCtrl[LeftB] = mtrSpeedReg;
			nMotorPIDSpeedCtrl[RightB] = mtrSpeedReg;
			slaveMotor(RightB, RightA);
			slaveMotor(LeftB, LeftA);
			//slaveMotor(RightB, RightA);

			//slaveMotor(LeftA, RightA);
			/*
			slaveMotor(RightB, RightA);
			slaveMotor(LeftB, LeftA);
			//*/
			motor[LeftA] = 113;
			motor[RightA] = 113;
			/*
			motor[LeftA] = 127;
			motor[LeftB] = 127;
			motor[RightA] = 127;
			motor[RightB] = 127;
			//*/
			} else if(vexRT[Btn8L] == 1){
			nMotorEncoder[LeftA] = 0;
			nMotorEncoder[RightA] = 0;
			nMotorEncoder[LeftB] = 0;
			nMotorEncoder[RightB] = 0;
		}


		if(vexRT[Btn7D] == 1){
			if(nImmediateBatteryLevel/1000.0 > 8.4){
				motor[LeftA] = 100;
				motor[LeftB] = 100;
				motor[RightA] = 100;
				motor[RightB] = 100;
				}else{
				motor[LeftA] = 127;
				motor[LeftB] = 127;
				motor[RightA] = 127;
				motor[RightB] = 127;
			}
			}else if(vexRT[Btn7R] == 1){
			motor[LeftA] = 0;
			motor[LeftB] = 0;
			motor[RightA] = 0;
			motor[RightB] = 0;
			}else if(vexRT[Btn7L] == 1){
			motor[LeftA] = 68;
			motor[LeftB] = 68;
			motor[RightA] = 68;
			motor[RightB] = 68;
			}else if(vexRT[Btn7U] == 1){
			motor[LeftA] = 53.5;
			motor[LeftB] = 53.5;
			motor[RightA] = 53.5;
			motor[RightB] = 53.5;
		}
		if(vexRT[Btn5U] == 1){
			motor[CollectB] =  127;
			}else if(vexRT[Btn5D] == 1){
			motor[CollectB] =  -127;
			}else{
			motor[CollectB] =  0;
		}
		if(vexRT[Btn6U] == 1){
			motor[CollectA] =  127;
			}else if(vexRT[Btn6D] == 1){
			motor[CollectA] =  -127;
			}else{
			motor[CollectA] =  0;
		}
		if(vexRT[Btn8D] == 1){
			SensorValue[Brake1] = 1;
			SensorValue[Brake2] = 1;
			}else if(vexRT[Btn8R] == 1){
			SensorValue[Brake1] = 0;
			SensorValue[Brake2] = 0;
		}
	}
}
